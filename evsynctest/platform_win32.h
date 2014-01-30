//
// Copyright 2013 Illumio, Inc. All Rights Reserved.
//
#ifndef __PLATFORM_WIN32_H__
#define __PLATFORM_WIN32_H__ 1

#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <winsock.h>

using namespace std;

#define pthread_t uint32_t
#define pthread_attr_t uint32_t
#define pid_t uint32_t
#define uid_t uint32_t
#define gid_t uint32_t
#define sigval_t uint32_t
#define socklen_t int32_t
#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#endif

#define SIG_BLOCK 0
#define PR_SET_DUMPABLE 0
#define SIGUSR1 0
#define SIGUSR2 0
#define F_SETFL 0
#define O_NONBLOCK 0

#define sigset_t int
#define pthread_mutex_t HANDLE

#define sleep Sleep
#define getpid GetCurrentProcessId
#define pthread_self GetCurrentThreadId
#define snprintf _snprintf
#define unlink(a) DeleteFile((LPCWSTR)a)
#define ERRNO WSAGetLastError()
#ifdef EAGAIN
#undef EAGAIN
#endif
#ifdef EADDRINUSE
#undef EADDRINUSE
#endif
#define EAGAIN WSAEWOULDBLOCK
#define EADDRINUSE WSAEADDRINUSE

#define pthread_exit return
#define pthread_detach(a) 0
#define pthread_sigmask(a,b,c) 0
#define pthread_attr_init(a) 0

#define getpwnam(a) 0
#define setgid(a) 0
#define setuid(a) 0
#define prctl(a,b)
#define res_init()

#define sigfillset(a)
#define sigemptyset(a)
#define sigaddset(a,b)
#define sigaction(a,b,c) 0
#define strsignal(a) ("")
#define strerror MyStrError

int fcntl(int32_t fd, int32_t type, int32_t mode);
int pthread_mutex_init(HANDLE *mutex, int ignore);
int pthread_mutex_lock(HANDLE *mutex);
int pthread_mutex_unlock(HANDLE *mutex);
int pthread_mutex_destroy(HANDLE *mutex);
int pthread_create(uint32_t *thread, const pthread_attr_t *attr,
	void *(*start_routine)(void*), void *arg);

extern char *MyStrError(int ErrNo);

struct passwd {
	char   *pw_name;       /* username */
	char   *pw_passwd;     /* user password */
	uid_t   pw_uid;        /* user ID */
	gid_t   pw_gid;        /* group ID */
	char   *pw_gecos;      /* user information */
	char   *pw_dir;        /* home directory */
	char   *pw_shell;      /* shell program */
};

typedef struct _siginfo_t{
	int      si_signo;    /* Signal number */
	int      si_errno;    /* An errno value */
	int      si_code;     /* Signal code */
	int      si_trapno;   /* Trap number that caused
						  hardware-generated signal
						  (unused on most architectures) */
	pid_t    si_pid;      /* Sending process ID */
	uid_t    si_uid;      /* Real user ID of sending process */
	int      si_status;   /* Exit value or signal */
	clock_t  si_utime;    /* User time consumed */
	clock_t  si_stime;    /* System time consumed */
	sigval_t si_value;    /* Signal value */
	int      si_int;      /* POSIX.1b signal */
	void    *si_ptr;      /* POSIX.1b signal */
	int      si_overrun;  /* Timer overrun count; POSIX.1b timers */
	int      si_timerid;  /* Timer ID; POSIX.1b timers */
	void    *si_addr;     /* Memory location which caused fault */
	long     si_band;     /* Band event (was int in
						  glibc 2.3.2 and earlier) */
	int      si_fd;       /* File descriptor */
	short    si_addr_lsb; /* Least significant bit of address
						  (since Linux 2.6.32) */
} siginfo_t;

struct sigaction {
	void(*sa_handler)(int);
	void(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void(*sa_restorer)(void);
};

#endif
