#ifndef _LOG_MESSAGE_H
#define _LOG_MESSAGE_H

#include "Platform.h"
#include <string>

#include <sys/types.h>

using namespace std;

#define EvSyncLog(msg) \
LogMessage::EvSyncLogInstance().Log(msg)

#ifdef _WIN32
#define EvSyncLogV(msg, ...) \
    LogMessage::EvSyncLogInstance().LogV(msg, ##__VA_ARGS__)
#else
#define EvSyncLogV(msg, args...) \
LogMessage::EvSyncLogInstance().LogV(msg, ## args)
#endif

class LogMessage
{
public:
    static LogMessage& EvSyncLogInstance();

    void Log(const char* szString);
    void LogV(const char* szString, ...);


protected:
    LogMessage(const char* szFileName);
    ~LogMessage();

    void Rotate();

    pthread_mutex_t m_mutex;

    string m_strFileName;

    int32_t m_nMaxSize;
};


#endif  // #ifndef _LOG_MESSAGE_H
