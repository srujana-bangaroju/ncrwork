#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<windows.h>
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{

	if (argc != 2)
	{
		_tprintf(_T("Usage fileopenread.exe <name of file>"));
		getchar();
		return FALSE;
	}
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);
	DWORD nbr;
	DWORD nBytesToRead=BUFFSIZE;
	while (1)
	{
		ZeroMemory(buffer, BUFFSIZE);
		BOOL ret = ReadFile(hFile, buffer, nBytesToRead-1 , &nbr, NULL);
		if (ret&&nbr == 0)
		{
			_tprintf(_T("\nEnd of file\n"));
			
			CloseHandle(hFile);
			break;
		}

		buffer[BUFFSIZE-1] = '\0';
		_tprintf(_T("%LS"), buffer);
		
	
	}

	getchar();
	return TRUE;

}