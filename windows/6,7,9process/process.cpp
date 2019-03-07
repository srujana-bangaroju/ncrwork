#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1,si2;
	HANDLE hproc;
	PROCESS_INFORMATION pi1,pi2;
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&si2, sizeof(si2));
	si1.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));

	if (argc != 3)
	{
		printf("Usage %S[cmdline]\n", argv[0]);
		getchar();
		return ;
	}

	if (!CreateProcess(NULL, argv[1] , NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}
	printf("Handle of first process is %ld \n", pi1.hProcess);
	printf("Process id of first process is %ld \n", pi1.dwProcessId);
	printf("primary thread id of first procezs is %ld\n", pi1.dwThreadId);
	printf("Handle of second process is %ld \n", pi2.hProcess);
	printf("Process id of second process is %ld \n", pi2.dwProcessId);
	printf("primary thread id of second procezs is %ld\n", pi2.dwThreadId);
	printf("Process information using functions\n");
	printf("Current process id is %ld\n",GetCurrentProcessId());
	printf("Current thread id is %ld\n", GetCurrentThreadId());
	printf("process id of first process is %ld\n", GetProcessId(pi1.hProcess));
	printf("thread id of first process is %ld\n", GetThreadId(pi1.hThread));
	printf("process id of of first process thread id %ld\n", GetProcessIdOfThread(pi1.hThread));
	printf("process id of second process is %ld\n", GetProcessId(pi2.hProcess));
	printf("thread id of second process is %ld\n", GetThreadId(pi1.hThread));
	printf("process id of of second process thread id %ld\n", GetProcessIdOfThread(pi1.hThread));
		CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);
	getchar();
}