
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
long g_x;
DWORD exitcode;
DWORD WINAPI secondary_thread(LPVOID lparam)
{
	g_x++;
	printf(" in secondary thread %ld\n", g_x);

	return 0;
}
int main()
{
	DWORD thid;
	HANDLE hthread;
	g_x = 0;
	printf("value of g_x in primary thread is %ld\n", g_x);
	hthread = CreateThread(NULL, 0, secondary_thread, NULL, CREATE_SUSPENDED, &thid);
	if (hthread == NULL)
	{
		printf("Unable to thread to create %d", GetLastError());
		getchar();
		return FALSE;
	}
	WaitForSingleObject(hthread, 1000);
	TerminateThread(hthread, exitcode);
	printf(" exit code is %ld\n", GetExitCodeThread(hthread, &exitcode));
	CloseHandle(hthread);
	printf("value of g_x in secondary thread is %ld\n", g_x);
	printf("Waiting for user input to exit\n");
	getchar();
	return 0;
}