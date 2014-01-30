#include "LogMessage.h"

#include <stdio.h>
#include <stdarg.h>

#include <sys/stat.h>
#ifdef _WIN32
#include <time.h>
#include <sys/timeb.h>
#else
#include <unistd.h>
#endif


LogMessage::LogMessage(const char* szFileName)
{
    m_strFileName = szFileName;
    m_nMaxSize = 10000000;

    pthread_mutex_init(&m_mutex, NULL);
}


LogMessage::~LogMessage()
{
    pthread_mutex_destroy(&m_mutex);
}

#ifdef _WIN32
LogMessage& LogMessage::EvSyncLogInstance()
{
    static LogMessage evSyncLog("evsynctest.log");
    return(evSyncLog);
}

void LogMessage::Log(const char* szString)
{
    FILE* pLogFile;
    char szTime[128];
    time_t timeNow;
    char szTimeZone[7] = "Z";
    struct _timeb timebuffer;
    short timezone;
    short timeleft;

    pthread_mutex_lock(&m_mutex);
    Rotate();

    if (pLogFile = _fsopen(m_strFileName.c_str(), "a", _SH_DENYNO))
    {
        timeNow = time(NULL);
        struct tm gmt;
        gmtime_s(&gmt, &timeNow);
        strftime(szTime, sizeof(szTime), "%Y-%m-%dT%H:%M:%S", &gmt);

        _ftime_s(&timebuffer);
        if (timebuffer.timezone != 0) {
            timezone = timebuffer.timezone / 60;

            // handle 30 min timezone, ex. India
            timeleft = timebuffer.timezone - timezone * 60;
            _snprintf_s(szTimeZone, 7, 7, "%c%02d:%02d",
                (timebuffer.timezone > 0) ? '-' : '+', timezone, timeleft);
        }
        fprintf(pLogFile, "%s%s ", szTime, szTimeZone);
#ifdef _DEBUG
        printf("%s%s ", szTime, szTimeZone);
#endif

        fputs(szString, pLogFile);
        fclose(pLogFile);
#ifdef _DEBUG
        printf("%s\n", szString);
#endif
    }

    pthread_mutex_unlock(&m_mutex);
}

void LogMessage::LogV(const char* szString, ...)
{
    FILE* pLogFile;
    char szBuffer[1024];
    char szTime[128];
    char szTimeZone[7] = "Z";
    time_t timeNow;
    struct _timeb timebuffer;
    short timezone;
    short timeleft;

    pthread_mutex_lock(&m_mutex);
    Rotate();

    if (pLogFile = _fsopen(m_strFileName.c_str(), "a",_SH_DENYNO))
    {
        timeNow = time(NULL);
        struct tm gmt;
        gmtime_s(&gmt, &timeNow);
        strftime(szTime, sizeof(szTime), "%Y-%m-%dT%H:%M:%S", &gmt);

        _ftime_s(&timebuffer);
        if (timebuffer.timezone != 0) {
            timezone = timebuffer.timezone / 60;

            // handle 30 min timezone, ex. India
            timeleft = timebuffer.timezone - timezone * 60;
            _snprintf_s(szTimeZone, 7, 7, "%c%02d:%02d",
                (timebuffer.timezone > 0) ? '-' : '+', timezone, timeleft);
        }
        fprintf(pLogFile, "%s%s ", szTime, szTimeZone);
#ifdef _DEBUG
        printf("%s%s ", szTime, szTimeZone);
#endif

        va_list vaList;
        va_start(vaList, szString);
        vsnprintf_s(szBuffer, sizeof(szBuffer), _TRUNCATE,
            szString, vaList);
        va_end(vaList);

        fputs(szBuffer, pLogFile);
        fclose(pLogFile);
#ifdef _DEBUG
        printf("%s\n", szBuffer);
#endif

    }

    pthread_mutex_unlock(&m_mutex);
}
#else
LogMessage& LogMessage::EvSyncLogInstance()
{
    static LogMessage evSyncLog("/opt/illumio/log/evsynctest.log");
    return(evSyncLog);
}

void LogMessage::Log(const char* szString)
{
    FILE* pLogFile;
    char szTime[128];
    time_t timeNow;

    pthread_mutex_lock(&m_mutex);
    Rotate();

    if ((pLogFile = fopen(m_strFileName.c_str(), "a")) != NULL)
    {
        timeNow = time(NULL);
        strftime(szTime, sizeof(szTime), "%m/%d/%Y %T ", localtime(&timeNow));
        fputs(szTime, pLogFile);

        fputs(szString, pLogFile);
        fclose(pLogFile);

    }

    pthread_mutex_unlock(&m_mutex);
}


void LogMessage::LogV(const char* szString, ...)
{
    FILE* pLogFile;
    char szBuffer[1024];
    char szTime[128];
    time_t timeNow;

    pthread_mutex_lock(&m_mutex);
    Rotate();

    if ((pLogFile = fopen(m_strFileName.c_str(), "a")) != NULL)
    {
        timeNow = time(NULL);
        strftime(szTime, sizeof(szTime), "%m/%d/%Y %T ", localtime(&timeNow));
        fputs(szTime, pLogFile);


        va_list vaList;
        va_start(vaList, szString);
        vsnprintf(szBuffer, sizeof(szBuffer), szString, vaList);
        va_end(vaList);

        fputs(szBuffer, pLogFile);
        fclose(pLogFile);

    }

    pthread_mutex_unlock(&m_mutex);
}
#endif

void LogMessage::Rotate()
{
    string strOldFileName;
    struct stat statBuffer;

    if (!stat(m_strFileName.c_str(), &statBuffer))
    {
        if (statBuffer.st_size > m_nMaxSize)
        {
            strOldFileName = m_strFileName + ".old";
            unlink(strOldFileName.c_str());

            rename(m_strFileName.c_str(), strOldFileName.c_str());
        }
    }
}
