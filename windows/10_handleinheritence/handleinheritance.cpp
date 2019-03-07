#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
#define BUFFSIZE 100
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return ;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);
	if (argc != 3)
	{
		printf("Usage %S[cmdline]\n", argv[0]);
		getchar();
		return;
	}

	if (!CreateProcess(NULL, argv[2], NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}

	printf("Current process id is %ld\n", GetCurrentProcessId());
	printf("Current thread id is %ld\n", GetCurrentThreadId());
	printf("process id of first process is %ld\n", GetProcessId(pi1.hProcess));
	printf("thread id of first process is %ld\n", GetThreadId(pi1.hThread));
	printf("Handle of first process is %ld \n", pi1.hProcess);


	getchar();
}