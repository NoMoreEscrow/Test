#ifndef __EVENTSOCKET_H__
#define __EVENTSOCKET_H__ 1

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "Platform.h"

#define USERNAME_SZ         16
#define PASSWORD_SZ         16
#define MAXBUFFER_SZ        1024
#define MESSAGE_TIMEOUT     20    // seconds


// Definitions for class handler types
typedef enum {
    EVHDLR_PLATFORM_TYPE    = 50,
    EVHDLR_LOGGING_TYPE     = 51,
    EVHDLR_IDS_TYPE         = 52
} EVHDLRTYPE;



// Definitions for messaging between MIDDLEWARE and EVENTSYNC
typedef enum {
    EVSYNC_HELLO_OP         = 100,
    EVSYNC_ACK_OP           = 101,
    EVSYNC_NAK_OP           = 102,
    EVSYNC_IDENTIFY_OP      = 103,
    EVSYNC_EVENTMSG_OP      = 104,
    EVSYNC_VALIDATE_OP      = 105,
    EVSYNC_BCASTEVENTMSG_OP = 106
} EVSYNCOP;

// Type definitions for various device types supported
#define UNKNOWN_TYPE            0
#define AGENT_TYPE              1
#define SENSOR_TYPE             2


#ifdef _WIN32
#pragma pack(1)

typedef struct _evsyncmsg_header {
    int32_t op;
    int32_t len;
} EVSYNCMSGHDR, *PEVSYNCMSGHDR;

// Message for class handlers to identify themselves
typedef struct _evsyncmsg_identify {
    EVSYNCMSGHDR hdr;
    uint64_t identifier;
    int32_t flags;
    uint8_t type;
} EVSYNCMSGIDENTIFY, *PEVSYNCMSGIDENTIFY;

// Event message for a class handler
typedef struct _evsyncmsg_event {
    EVSYNCMSGHDR hdr;
    uint64_t sid;
    int32_t classhdlr;
    uint8_t type;
    char data;
} EVSYNCMSGEVENT, *PEVSYNCMSGEVENT;

// Message for us to validate ourselves to EventService
typedef struct _evsyncmsg_validate {
    EVSYNCMSGIDENTIFY identify;
    char uid[USERNAME_SZ];
    char token[PASSWORD_SZ];
    uint64_t orgid;
} EVSYNCMSGVALIDATE, *PEVSYNCMSGVALIDATE;

// Broadcast message for a class handler
typedef struct _evsyncmsg_bcastevent {
    EVSYNCMSGHDR hdr;
    uint64_t orgid;
    uint32_t flags;
    int32_t classhdlr;
    char data;
} EVSYNCMSGBCASTEVENT, *PEVSYNCMSGBCASTEVENT;

#pragma pack()

#else
typedef struct _evsyncmsg_header {
    int32_t op __attribute__((__packed__));
    int32_t len __attribute__((__packed__));
} EVSYNCMSGHDR, *PEVSYNCMSGHDR;

// Message for class handlers to identify themselves
typedef struct _evsyncmsg_identify {
    EVSYNCMSGHDR hdr;
    uint64_t identifier __attribute__((__packed__));
    int32_t flags __attribute__((__packed__));
    uint8_t type;
} EVSYNCMSGIDENTIFY, *PEVSYNCMSGIDENTIFY;

// Event message for a class handler
typedef struct _evsyncmsg_event {
    EVSYNCMSGHDR hdr;
    uint64_t sid __attribute__((__packed__));
    int32_t classhdlr __attribute__((__packed__));
    uint8_t type;
    char data;
} EVSYNCMSGEVENT, *PEVSYNCMSGEVENT;

// Message for us to validate ourselves to EventService
typedef struct _evsyncmsg_validate {
    EVSYNCMSGIDENTIFY identify;
    char uid[USERNAME_SZ];
    char token[PASSWORD_SZ];
    uint64_t orgid __attribute__((__packed__));
} EVSYNCMSGVALIDATE, *PEVSYNCMSGVALIDATE;

// Broadcast message for a class handler
typedef struct _evsyncmsg_bcastevent {
    EVSYNCMSGHDR hdr;
    uint64_t orgid __attribute__((__packed__));
    uint32_t flags __attribute__((__packed__));
    int32_t classhdlr __attribute__((__packed__));
    char data;
} EVSYNCMSGBCASTEVENT, *PEVSYNCMSGBCASTEVENT;
#endif

#define BCASTFLAG_NONE         0
#define BCASTFLAG_SENSORS      1
#define BCASTFLAG_AGENTS       2
#define BCASTFLAG_STAGGER      4
// End of definitions for messaging between MIDDLEWARE and EVENTSYNC



extern bool EventSyncClientSetup();
extern bool EventSyncClientRead(char *buffer, int32_t *len,
    int32_t *op, int32_t timeout);
extern bool EventSyncClientWrite(char *buffer, int32_t *len, int32_t timeout);
extern bool EventSyncClientClose();

uint64_t htonll(const uint64_t value);
uint64_t ntohll(const uint64_t value);

#endif
