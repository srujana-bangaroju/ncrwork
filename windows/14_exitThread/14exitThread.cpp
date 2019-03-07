#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
long g_x;
DWORD exitcode;
DWORD WINAPI secondary_thread(LPVOID lparam)
{
	g_x++;
	
	ExitThread(exitcode);
}
int main()
{
	DWORD thid;
	HANDLE hthread;
	g_x = 0;
	printf("value of g_x in primary thread is %ld\n", g_x);
	hthread = CreateThread(NULL, 0, secondary_thread, NULL,0, &thid);
	if (hthread == NULL)
	{
		printf("Unable to thread to create %d", GetLastError());
		getchar();
		return FALSE;
	}
	WaitForSingleObject(hthread, 5000);
	GetExitCodeThread(hthread, LPDWORD(exitcode));
	CloseHandle(hthread);
	printf("value of g_x in secondary thread is %ld\n", g_x);
	printf("Waiting for user input to exit\n");
	getchar();
	return 0;
}
