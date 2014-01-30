#include "platform_win32.h"
#include "LogMessage.h"

int pthread_create(uint32_t *thread, const pthread_attr_t *attr,
	void *(*start_routine)(void*), void *arg)
{
	HANDLE hThread;

	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)start_routine, arg, 0, (LPDWORD)thread);

	if (hThread == NULL) {
		EvSyncLogV("Failed to create  thread, error = %d\n", GetLastError());
		return -1;
	}

	return 0;
}

bool processIsRunning(string process_name, int32_t pid)
{
	return false;
}

bool runAsDaemon()
{
	return true;
}

int fcntl(int32_t fd, int32_t type, int32_t mode)
{
	// this is for non-bloking socket
	if ((type == F_SETFL) && (mode == O_NONBLOCK)) {
		u_long iMode = 1;
		int iResult = ioctlsocket(fd, FIONBIO, &iMode);
		if (iResult != NO_ERROR) {
			EvSyncLogV("ioctlsocket failed with error: %ld\n", iResult);
		}
	}
	return 0;
}

int pthread_mutex_init(HANDLE *mutex, int ignore)
{
	//WCHAR wzMutexName[128];
	//_snwprintf_s(wzMutexName, 128, 128, L"ThreadMutex_%d", GetCurrentThreadId());
	*mutex = CreateMutex(NULL, FALSE, NULL);
	if (*mutex == NULL)
		return -1;
	return 0;
}

int pthread_mutex_lock(HANDLE *mutex)
{
	WaitForSingleObject(*mutex, INFINITE);
	return 0;
}

int pthread_mutex_unlock(HANDLE *mutex)
{
	ReleaseMutex(*mutex);
	return 0;
}

int pthread_mutex_destroy(HANDLE *mutex)
{
	CloseHandle(*mutex);
	return 0;
}

char *MyStrError(int ErrNo)
{
    static char s[128];
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, ErrNo,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        s, 128, NULL);
    int len = strlen(s);

    if (len >= 2) {
        if ((s[len - 2] == '\r') && (s[len - 1] == '\n')) {
            s[len - 2] = '\0';
        }
    }
    return s;
}