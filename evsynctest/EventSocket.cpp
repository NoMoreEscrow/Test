
#include "LogMessage.h"
#include "EventSocket.h"
#ifdef _WIN32
#define close closesocket
#else
#define ERRNO errno
#endif

int32_t EventSyncClientFD   = -1;
int32_t EventSyncServerPORT = 4000;

static bool EventSetupTCPClient(int32_t *serverfd, int32_t port)
{
    int32_t fd;
    int32_t on = 1;
    struct sockaddr_in servaddr;

    if( !serverfd )
        return false;

    // complete failure is return of false with clientfd of -1
    *serverfd = -1;

    if( (fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ) {
        EvSyncLogV(
            "Failed to create socket for TCP client for port %d: %d(%s)\n",
            port, ERRNO, strerror(ERRNO));
        return false;
    }

    // Our service is available on the same localhost
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port        = htons(port);

    if( connect(fd, (struct sockaddr *) &servaddr,
        (socklen_t)sizeof(servaddr)) < 0 ) {
        EvSyncLogV("Failed to connect socket for TCP server on port %d: "
            "%d(%s)\n",
            port, ERRNO, strerror(ERRNO));

        close(fd);
        return false;
    }

    // Setup for non-blocking I/O
    if( setsockopt(fd, SOL_SOCKET,  SO_REUSEADDR,
        (char *)&on, sizeof(on)) < 0 ) {
        EvSyncLogV(
            "Failed setsockopt(SO_REUSEADDR) on connected socket: "
            "%d(%s)\n",
            ERRNO, strerror(ERRNO));
        close(fd);
        return false;
    }

    if( setsockopt(fd, SOL_SOCKET,  SO_KEEPALIVE,
        (char *)&on, sizeof(on)) < 0 ) {
        EvSyncLogV(
            "Failed setsockopt(SO_KEEPALIVE) on connected socket: "
            "%d(%s)\n",
            ERRNO, strerror(ERRNO));
        close(fd);
        return false;
    }

    if( fcntl(fd, F_SETFL, O_NONBLOCK) < 0 ) {
        EvSyncLogV(
            "Failed fcntl(O_NONBLOCK) on connected socket: %d(%s)\n",
            ERRNO, strerror(ERRNO));
        close(fd);
        return false;
    }

    *serverfd = fd;
    return true;
}

static bool EventFlushTCPConnection(int32_t serverfd)
{
    char buffer[128];
    int32_t size;
    int32_t cnt;

    size = sizeof(buffer);
    do {
        cnt = recv(serverfd, buffer, size, 0);
        if( (cnt == 0) || ((cnt < 0) && (ERRNO != EAGAIN)) ) {
            // client closed connection or socket failure
            if( cnt < 0 )
                EvSyncLogV("Flush failure on fd %d: %d(%s)\n",
                    serverfd, ERRNO, strerror(ERRNO));
            return false;
        } else if (cnt < 0) {
            break;
        }
    } while(1);

    return true;
}

static bool EventReadTCPConnection(int32_t serverfd, char *buffer, int32_t *len,
    int32_t *op, int32_t timeout)
{
    PEVSYNCMSGHDR bufptr;
    int32_t size = *len;  // Size of given buffer
    int32_t offset = 0;
    int32_t overflow;
    int32_t cnt;
    int32_t left;
    time_t now, start;

    if( !buffer || !len || !op )
        return false;

    // We must have enough room for the header
    if( size < (int32_t)sizeof(EVSYNCMSGHDR) )
        return false;

    // complete failure is return of false with len set to -1
    *len = -1;

    // keep track of start time for timeout processing
    start = time(0);

    // First read our header
    left = sizeof(EVSYNCMSGHDR);
    bufptr = (PEVSYNCMSGHDR)buffer;
    do {
        cnt = recv(serverfd, &buffer[offset], left, 0);
        if( (cnt == 0) || ((cnt < 0) && (ERRNO != EAGAIN)) ) {
            // client closed connection or socket failure
            if( cnt < 0 )
                EvSyncLogV("Read failure on fd %d: %d(%s)\n",
                    serverfd, ERRNO, strerror(ERRNO));
            return false;
        } else if (cnt > 0) {
            left -= cnt;
            offset += cnt;
            start = time(0);  // bump start timer
        } else if (cnt < 0) {
            // No data on socket.  Return now if no timeout
            if(!timeout) {
                *len = 0;
                return false;
            }
        }
        now = time(0);
    } while( left && (!timeout || (now - start < timeout)) );
    
    // On a timeout return a length of zero
    if( left ) {
        *len = 0;
        return false;
    }

    // Now know length and operation code
    *len = ntohl(bufptr->len) + sizeof(EVSYNCMSGHDR);
    *op = ntohl(bufptr->op);

    // If we are done return now
    left = ntohl(bufptr->len);
    if( !left ) {
        return true;
    }

    overflow = 0;
    if( left > (size - offset) ) {
       overflow = (left - (size - offset));
       left = (size - offset);

       // adjust what is being returned to caller
       bufptr->len = htonl(left + sizeof(EVSYNCMSGHDR));
    }

    // We are in the middle of the message, set our timeout to 10 seconds
    timeout = 10;

    // Go get the rest
    do {
        cnt = recv(serverfd, &buffer[offset], left, 0);
        if( (cnt == 0) || ((cnt < 0) && (ERRNO != EAGAIN)) ) {
            // client closed connection or socket failure
            if( cnt < 0 )
                EvSyncLogV("Read failure on fd %d: %d(%s)\n",
                    serverfd, ERRNO, strerror(ERRNO));
            return false;
        } else if (cnt > 0) {
            left -= cnt;
            offset += cnt;
            start = time(0);  // bump start timer
        }
        now = time(0);
    } while( left && (timeout && (now - start < timeout)) );
    
    // On a timeout return a length of zero
    if( left ) {
        *len = 0;
        return false;
    }

    if( overflow ) {
        // Flush our socket.  If false is returned then client closed
        // connection.
        if( EventFlushTCPConnection(serverfd) == false ) {
            *len = -1;
            return false;
        }
    }

    return true;
}

static bool EventWriteTCPConnection(int32_t fd, char *buffer, int32_t *len,
    int32_t timeout)
{
    int32_t cnt;
    int32_t offset = 0;
    int32_t left;
    time_t now, start;

    if( !buffer || !len )
        return false;

    // We must have enough data for the header
    if( *len < (int32_t)sizeof(EVSYNCMSGHDR) )
        return false;

    // keep track of start time for timeout processing
    start = time(0);

    left = *len;
    do {
        cnt = send(fd, &buffer[offset], left, 0);
        if( (cnt == 0) || ((cnt < 0) && (ERRNO != EAGAIN)) ) {
            // client closed connection
            if( cnt < 0 )
                EvSyncLogV("Write failure on fd %d: %d(%s)\n",
                    fd, ERRNO, strerror(ERRNO));
            *len = -1;
            return false;
        } else if (cnt > 0) {
            left -= cnt;
            offset += cnt;
            start = time(0);  // bump start timer
        } else if (cnt < 0) {
            // Socket is full.  Return now if no timeout
            if(!timeout) {
                *len = 0;
                return false;
            }
        }
        now = time(0);
    } while( left && (!timeout || (now - start < timeout)) );
    
    // On a timeout return a length of zero
    if( left ) {
        *len = 0;
        return false;
    }

    return true;
}

bool EventSyncClientSetup()
{
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        EvSyncLogV("WSAStartup failed: %d\n", GetLastError());
        return false;
    }
#endif
    return(EventSetupTCPClient(&EventSyncClientFD, EventSyncServerPORT));
}

bool EventSyncClientRead(char *buffer, int32_t *len,
    int32_t *op, int32_t timeout)
{
    return(EventReadTCPConnection(EventSyncClientFD, buffer, len,
        op, timeout));
}

bool EventSyncClientWrite(char *buffer, int32_t *len, int32_t timeout)
{
    return(EventWriteTCPConnection(EventSyncClientFD, buffer, len, timeout));
}

bool EventSyncClientClose()
{
    if( EventSyncClientFD >= 0 )
        close(EventSyncClientFD);
    return true;
}

uint64_t ntohll(const uint64_t value)
{
    enum { TYP_INIT, TYP_SMLE, TYP_BIGE };

    union
    {
       uint64_t ull;
       uint8_t  c[8];
    } x;

    // Test if on Big Endian system.
    static int typ = TYP_INIT;

    if (typ == TYP_INIT)
    {
       x.ull = 0x01;
       typ = (x.c[7] == 0x01) ? TYP_BIGE : TYP_SMLE;
    }

    // System is Big Endian; return value as is.
    if (typ == TYP_BIGE)
    {
       return value;
    }

    // else convert value to Big Endian
    x.ull = value;

    int8_t c = 0;
    c = x.c[0]; x.c[0] = x.c[7]; x.c[7] = c;
    c = x.c[1]; x.c[1] = x.c[6]; x.c[6] = c;
    c = x.c[2]; x.c[2] = x.c[5]; x.c[5] = c;
    c = x.c[3]; x.c[3] = x.c[4]; x.c[4] = c;

    return x.ull;
}

uint64_t htonll(const uint64_t value)
{
    return ntohll(value);
}
