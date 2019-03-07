#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<windows.h>
int _tmain(int argc, LPTSTR argv[])
{

	if (argc != 2)
	{
		_tprintf(_T("Usage fileopenread.exe <name of file>"));
		getchar();
		return FALSE;
	}
	HANDLE hFile;
	TCHAR buffer[] = TEXT("Hello from filewrite");
	hFile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);
	DWORD nbw;
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &nbw, NULL);
	if (ret == 0)
	{
		printf("cannot open file");
	}
	CloseHandle(hFile);
	getchar();
}