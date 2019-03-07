#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	/*if (argc != 2)
	{
		printf("Usage %S[cmdline]\n", argv[0]);
		getchar();
		return;
	}*/
	if (!CreateProcess(NULL,_T("notepad.exe"), NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}
	/*TCHAR buffer[] = TEXT("Hello from filewrite");
	HANDLE hFile1;
	printf("%hS", GetCommandLine());
	hFile1= CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile1 == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return;
	}
	_tprintf(_T("File (%s)opened successfully\n"),argv[1]);
	DWORD nbw;
	BOOL ret = WriteFile(hFile1, buffer, sizeof(buffer), &nbw, NULL);
	if (ret == 0)
	{
		printf("cannot open file");
	}
	CloseHandle(hFile1);*/
}
