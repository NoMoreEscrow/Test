#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include "Platform.h"
#include "LogMessage.h"
#include "EventSocket.h"

using namespace std;

const string MY_APP_NAME = "EventLogger";

// Global definitions
void EventServiceCleanup();
char *HandlerTypeToString(EVHDLRTYPE optype);
char *EventSyncOpToString(EVSYNCOP optype);
#define EXIT(x) { EventServiceCleanup(); exit(x); }

// Global flags to control our threads
const int32_t WATCHDOGINTERVAL     = (10 * 60);
const int32_t BACKOFF_TIME         = (4);
const int32_t SLEEP_TIME           = (1);

// Keep track of our signal being handled
static bool fatal_error_raised = false;

// Toggle this flag if user wants us to turn on/off debugging
bool EventSyncDebug = true;
// Toggle this flag to run process in daemon mode
bool EventLoggerRunAsDaemon = false;

static void handleSignal(int32_t sigNum)
{
    string strSig = strsignal( sigNum);

    if( strSig.length() == 0)
        strSig = "unknown signal";
 
    EvSyncLogV("received signal %d - %s\n", sigNum, strSig.c_str());
    
    if(fatal_error_raised)
    {
        raise( sigNum);
    }

    fatal_error_raised = true;

    EventServiceCleanup();

    // Set signal handler to default and then raise it
    struct sigaction actions;
    memset(&actions, 0, sizeof(actions));
    sigemptyset(&actions.sa_mask);
    actions.sa_flags = 0;
    actions.sa_handler = SIG_DFL;
    if( sigaction (sigNum, &actions, NULL) == -1) {
        EvSyncLog("Failed to reset handler\n");
    }

    raise( sigNum);
}

void setupSignalHandler()
{
    struct sigaction actions;

    memset(&actions, 0, sizeof(actions));
    sigemptyset(&actions.sa_mask);
    actions.sa_flags = 0;

    actions.sa_handler = SIG_IGN;
    if( sigaction (SIGPIPE, &actions, NULL) == -1) {
        EvSyncLog("Failed to ignore SIGPIPE\n");
        exit(-1);
    }

    actions.sa_handler = handleSignal;
    if( sigaction (SIGINT, &actions, NULL) == -1) {
        EvSyncLog("Failed to set SIGINT handler\n");
        exit(-1);
    }
    if( sigaction (SIGHUP, &actions, NULL) == -1) {
        EvSyncLog("Failed to set SIGHUP handler\n");
        exit(-1);
    }
    if( sigaction (SIGTERM, &actions, NULL) == -1) {
        EvSyncLog("Failed to set SIGTERM handler\n");
        exit(-1);
    }
    if( sigaction (SIGSEGV, &actions, NULL) == -1) {
        EvSyncLog("Failed to set SIGSEGV handler\n");
        exit(-1);
    }
    if( sigaction (SIGBUS, &actions, NULL) == -1) {
        EvSyncLog("Failed to set SIGBUS handler\n");
        exit(-1);
    }
}

#ifdef _WIN32
bool processIsRunning(string process_name, int32_t pid);
bool runAsDaemon(void);
#else
// searches through proc to see if process_name is running
// pid defaults to 0
bool processIsRunning(string process_name, int32_t pid)
{
    DIR *prcDir;
    struct dirent *dp  = NULL;
    string statusPath;
    string tmp;
    string processName;
    ifstream in;

    string procDirName = "/proc/";
    prcDir = opendir(procDirName.c_str());
    if(!prcDir)
    {
        EvSyncLogV("Unable to open %s directory: %s\n",
                procDirName.c_str(), strerror(errno));
        return false;
    }
 
    while( prcDir)
    {
        if(( dp = readdir( prcDir)) != NULL)
        {
            if( isdigit( dp->d_name[0]) )
            {
                statusPath = procDirName + string(dp->d_name) + "/status";
                in.open( statusPath.c_str(), ios::in);
                if( !in)
                {
                    EvSyncLogV("Unable to open status file %s: %s\n",
                            statusPath.c_str(), strerror(errno));
                    continue;
                }
                getline( in, tmp, '\n');
                in.close();

                // parse the process name
                processName = tmp.substr( 6, tmp.size() - 6);
                if( processName == process_name)
                {
                    if( pid != 0)
                    {
                        // skip this process
                        if(pid == atoi(dp->d_name))
                        {
                            continue;
                        }
                        else
                        {
                            closedir(prcDir);
                            return true;
                        }
                    }
                    else
                    { 
                        closedir( prcDir);
                        return true;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }

    closedir( prcDir);

    return false;
}


bool runAsDaemon()
{
    // Fork from the parent process
    pid_t pid = fork();
    if( pid < 0)
    {
        EvSyncLog("Unable to fork from parent process, exiting\n");
        exit(1);
    }

    // Exit the parent process
    if( pid > 0)
    {
        exit(0);
    }

    // Create new sid for child process
    pid_t sid = setsid();
    if( sid < 0)
    {
        EvSyncLog("Failed to create new sid, exiting\n");
        return false;
    }

    return 1;
}
#endif

void parseArgs(int32_t argc, char **argv)
{
    for( int32_t i = 1; i < argc; i++)
    {
        if( strcmp( argv[i], "-d") == 0)
        {
            EventSyncDebug = true;
            EvSyncLog("Starting EventLogger in debug mode\n");
        }
        else if( strcmp( argv[i], "-D") == 0)
        {
            EventLoggerRunAsDaemon = true;
            EvSyncLog("Starting EventLogger as daemon\n");
        }
    }
}

int main(int32_t argc, char **argv)
{
    char buffer[MAXBUFFER_SZ];
    int32_t msglen;
    PEVSYNCMSGHDR hdrptr;
    PEVSYNCMSGIDENTIFY idptr;
    PEVSYNCMSGEVENT eventptr = NULL;
    PEVSYNCMSGBCASTEVENT bcasteventptr = NULL;
    int32_t opcode;
    time_t lastWatchdogTime;
    bool needEventSyncClient = true;
    bool needEventSyncClientACK = false;
    bool sendAck;

    int32_t myclassid = (int32_t)EVHDLR_IDS_TYPE;

    setupSignalHandler();

    parseArgs(argc, argv);

    // Check to see if we are already running
    if( processIsRunning(MY_APP_NAME, getpid()) ) {
        EvSyncLog("Process is already running, exiting\n");
        exit(0);
    }

    // Run in daemon mode if requested
    if( EventLoggerRunAsDaemon ) {
        runAsDaemon();
    }

    if( !EventSyncClientSetup() ) {
        EvSyncLog("Unable to setup Handler TCP client, retry later...\n");
    } else {
        needEventSyncClient = false;

        // Immediately send out the IDENTIFY message
        idptr = (PEVSYNCMSGIDENTIFY)buffer;
        idptr->hdr.op = htonl(EVSYNC_IDENTIFY_OP);
        idptr->hdr.len =
            htonl(sizeof(EVSYNCMSGIDENTIFY) - sizeof(EVSYNCMSGHDR));
        idptr->identifier = htonll((uint64_t)myclassid);
        idptr->flags = htonl(0);
        idptr->type = UNKNOWN_TYPE;
        msglen = sizeof(EVSYNCMSGIDENTIFY);
        if( EventSyncClientWrite(buffer, &msglen, 0) == false ) {
            EvSyncLogV("Unable to send IDENTIFY message to EventSync, "
                "%s...closing connection and retry later\n",
                (msglen == 0) ? "timeout" : "socket failure");
            EventSyncClientClose();
            needEventSyncClient = true;
        } else {
            // Should get an ACK or a NAK for this
            needEventSyncClientACK = true;

            if( EventSyncDebug )
                EvSyncLog("Sent IDENTIFY to EventSync.\n");
        }
    }

    // If this timer expires send a HELLO to EventSync or terminate the
    // socket if we are waiting on an ACK
    lastWatchdogTime = time(0);

    while( 1 ) {
        time_t now;
        bool sts;

        // Process EventSync connection
        if( needEventSyncClient && EventSyncClientSetup() ) {
            needEventSyncClient = false;

            // Immediately send out the IDENTIFY message
            idptr = (PEVSYNCMSGIDENTIFY)buffer;
            idptr->hdr.op = htonl(EVSYNC_IDENTIFY_OP);
            idptr->hdr.len = 
                htonl(sizeof(EVSYNCMSGIDENTIFY) - sizeof(EVSYNCMSGHDR));
            idptr->identifier = htonll((uint64_t)myclassid);
            idptr->flags = htonl(0);
            idptr->type = UNKNOWN_TYPE;
            msglen = sizeof(EVSYNCMSGIDENTIFY);
            if( EventSyncClientWrite(buffer, &msglen, 0) == false ) {
                EvSyncLogV("Unable to send IDENTIFY message to EventSync, "
                    "%s...closing connection and retry later\n",
                    (msglen == 0) ? "timeout" : "socket failure");
                EventSyncClientClose();
                needEventSyncClient = true;
            } else {
                // Should get an ACK or a NAK for this
                needEventSyncClientACK = true;

                if( EventSyncDebug )
                    EvSyncLog("Sent IDENTIFY to EventSync.\n");
            }
        } else if( needEventSyncClient ) {
            sleep(BACKOFF_TIME);
        }

        if( !needEventSyncClient ) {
            msglen = (MAXBUFFER_SZ - 1);
            sts = EventSyncClientRead(buffer, &msglen, &opcode, 0);
            if( sts == false ) {
                if( msglen < 0 ) {
                    EvSyncLog(
                        "Failure receiving message from EventSync, "
                        "socket failure...closing connection.\n");
                    EventSyncClientClose();
                    needEventSyncClient = true;
                }
            } else {
                if( EventSyncDebug )
                    EvSyncLogV(
                       "Received %s from EventSync.\n",
                       EventSyncOpToString((EVSYNCOP)opcode) );
                switch( opcode ) {
                    case EVSYNC_HELLO_OP:
                        hdrptr = (PEVSYNCMSGHDR)buffer;
                        hdrptr->op = htonl(EVSYNC_ACK_OP);
                        hdrptr->len = htonl(0);
                        msglen = sizeof(EVSYNCMSGHDR);
                        if( EventSyncClientWrite(buffer, &msglen,
                                0) == false ) {
                            EvSyncLogV("Unable to send ACK message to "
                                       "EventSync, %s...closing "
                                       "connection and retry later\n",
                                (msglen == 0) ? "timeout" : "socket failure");
                            EventSyncClientClose();
                            needEventSyncClient = true;
                        } else if( EventSyncDebug )
                            EvSyncLog("Sent ACK to EventSync.\n");
                        break;

                    case EVSYNC_ACK_OP:
                        if( !needEventSyncClientACK )
                            EvSyncLog(
                                "Received unexpected ACK from "
                                "EventSync, ignoring it\n");
                        needEventSyncClientACK = false;
                        break;

                    case EVSYNC_NAK_OP:
                        needEventSyncClientACK = false;
                        EvSyncLog(
                            "Received NAK message from EventSync, "
                            "closing connection.\n");
                        EventSyncClientClose();
                        needEventSyncClient = true;
                        break;

                    case EVSYNC_EVENTMSG_OP:
                    case EVSYNC_BCASTEVENTMSG_OP:
                    default:
                        // Log the event
                        sendAck = true;
                        buffer[msglen] = 0;
                        if( opcode == EVSYNC_EVENTMSG_OP ) {
                            eventptr = (PEVSYNCMSGEVENT)buffer;
                            EvSyncLogV("Sensor: %llu Handler: %s "
                              "DataLen: %d EventData:\n[%s]\n",
                              ntohll(eventptr->sid),
                              HandlerTypeToString(
                                (EVHDLRTYPE)ntohl(eventptr->classhdlr)),
                              ntohl(eventptr->hdr.len) +
                                  sizeof(EVSYNCMSGHDR) -
                                  sizeof(EVSYNCMSGEVENT) +
                                  sizeof(char),
                              (char *)&eventptr->data);
                        } else if( opcode == EVSYNC_BCASTEVENTMSG_OP ) {
                            bcasteventptr = (PEVSYNCMSGBCASTEVENT)buffer;
                            EvSyncLogV("Org: %llu Flags: 0x%x Handler: "
                              "%s DataLen: %d EventData:\n[%s]\n",
                              ntohll(bcasteventptr->orgid),
                              ntohl(bcasteventptr->flags),
                              HandlerTypeToString((EVHDLRTYPE)
                                ntohl(bcasteventptr->classhdlr)),
                              ntohl(bcasteventptr->hdr.len) +
                                  sizeof(EVSYNCMSGHDR) -
                                  sizeof(EVSYNCMSGBCASTEVENT) +
                                  sizeof(char),
                              (char *)&bcasteventptr->data);
                        } else {
                            EvSyncLogV(
                                "Unexpected message opcode %d received from "
                                "EventSync, dropping it and sending NAK.\n",
                                opcode);
                            sendAck = false;
                        }

                        hdrptr = (PEVSYNCMSGHDR)buffer;
                        hdrptr->op = (sendAck ?
                            htonl(EVSYNC_ACK_OP) : htonl(EVSYNC_NAK_OP));
                        hdrptr->len = htonl(0);
                        msglen = sizeof(EVSYNCMSGHDR);
                        if( EventSyncClientWrite(buffer, &msglen,
                                0) == false ) {
                            EvSyncLogV("Unable to send %s message to "
                                       "EventSync, %s...closing "
                                       "connection and retry later\n",
                                EventSyncOpToString((EVSYNCOP)
                                    ntohl(hdrptr->op)),
                                (msglen == 0) ? "timeout" : "socket failure");
                            EventSyncClientClose();
                            needEventSyncClient = true;
                        } else if( EventSyncDebug )
                            EvSyncLogV("Sent %s to EventSync.\n",
                                EventSyncOpToString((EVSYNCOP)
                                    ntohl(hdrptr->op)));
                        break;
                }
                // If we hear from EventSync bump our watchdog timer
                lastWatchdogTime = time(0);
            }
        }

        // Check for need for watchdog
        if( !needEventSyncClient ) {
            now = time(0);
            if( now < lastWatchdogTime )
                lastWatchdogTime = now;
            if( (now - lastWatchdogTime) >= WATCHDOGINTERVAL ) {
                if( needEventSyncClientACK ) {
                    EvSyncLogV(
                        "No ACK message from EventSync in %d "
                        "seconds, closing connection.\n",
                        (int32_t)WATCHDOGINTERVAL);
                    EventSyncClientClose();
                    needEventSyncClient = true;
                } else {
                    // Send a HELLO message to the EventSync
                    hdrptr = (PEVSYNCMSGHDR)buffer;
                    hdrptr->op = htonl(EVSYNC_HELLO_OP);
                    hdrptr->len = htonl(0);
                    msglen = sizeof(EVSYNCMSGHDR);
                    if( EventSyncClientWrite( buffer, &msglen, 0) == false ) {
                        EvSyncLogV("Unable to send HELLO message to "
                            "EventSync %s, closing connection.\n",
                            (msglen == 0) ? "timeout" : "socket failure");
                        EventSyncClientClose();
                        needEventSyncClient = true;
                    } else {
                        needEventSyncClientACK = true;
                        if( EventSyncDebug )
                            EvSyncLog("Sent HELLO to EventSync.\n");
                    }
                }
                lastWatchdogTime = time(0);
            }
        } else {
            lastWatchdogTime = time(0);
        }

        // Sleep
        sleep(SLEEP_TIME);
    }

    EXIT(0);
}

void EventServiceCleanup()
{
    EvSyncLog("Cleaning up.\n");
    EventSyncClientClose();
}

char *EventSyncOpToString(EVSYNCOP optype)
{
    static char buffer[32];
    switch (optype) {
        case EVSYNC_HELLO_OP:
            sprintf(buffer, "HELLO");
            break;

        case EVSYNC_ACK_OP:
            sprintf(buffer, "ACK");
            break;

        case EVSYNC_NAK_OP:
            sprintf(buffer, "NAK");
            break;

        case EVSYNC_IDENTIFY_OP:
            sprintf(buffer, "IDENTIFY");
            break;

        case EVSYNC_EVENTMSG_OP:
            sprintf(buffer, "EVENT");
            break;

        case EVSYNC_VALIDATE_OP:
            sprintf(buffer, "VALIDATE");
            break;

        case EVSYNC_BCASTEVENTMSG_OP:
            sprintf(buffer, "BCASTEVENT");
            break;

        default:
            sprintf(buffer, "Unknown Opcode Type %d", (int32_t)optype);
            break;
    }

    return buffer;
}

char *HandlerTypeToString(EVHDLRTYPE optype)
{
    static char buffer[32];
    switch (optype) {
        case EVHDLR_PLATFORM_TYPE:
            sprintf(buffer, "PLATFORM");
            break;

        case EVHDLR_LOGGING_TYPE:
            sprintf(buffer, "LOGGING");
            break;

        case EVHDLR_IDS_TYPE:
            sprintf(buffer, "IDS");
            break;

        default:
            sprintf(buffer, "Unknown Handler Type %d", (int32_t)optype);
            break;
    }

    return buffer;
}
