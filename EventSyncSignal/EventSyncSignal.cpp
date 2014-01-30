#include <windows.h>
#include <stdio.h>

LPCSTR EventSyncEvents[2] = { "Global\\EventSyncDebug", "Global\\EventSyncDumpMap" };

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        printf("\t1 - Dump Map of Handlers\n");
        printf("\t2 - Toggle Debug mode\n");
        exit(-1);
    }

    DWORD dwEvent = atoi(argv[1]);

    if (dwEvent > 2) {
        printf("Invalid Event number: %s\n", argv[1]);
        exit(-1);
    }
    
    HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, EventSyncEvents[dwEvent - 1]);

    if (hEvent == NULL) {
        printf("CreateEvent(%s) failed with error = %d.\n", EventSyncEvents[dwEvent - 1], GetLastError());
        exit(-1);
    }

    if (ERROR_ALREADY_EXISTS == GetLastError()) {
        printf("Signal EventSync service with event - %s.\n", EventSyncEvents[dwEvent - 1]);
        SetEvent(hEvent);
    }
    else {
        printf("Event(%s) is not existing. Please check if EventSyncSvc is running.\n", EventSyncEvents[dwEvent - 1]);
    }

    CloseHandle(hEvent);
    return 0;
}