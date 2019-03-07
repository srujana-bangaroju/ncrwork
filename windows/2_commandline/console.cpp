#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[])
{
	LPWSTR *szArgList;
	int nargs=argc;
	int i;
	szArgList = CommandLineToArgvW(GetCommandLineW(), &nargs);
	if (NULL == szArgList)
	{
		wprintf(L"no command line arguments");
		return 0;
	}
	else
	{
		for (i = 0; i < nargs; i++)
		{
			printf("%d : %lS", i, argv[i]);
			printf("\n");
		}
	}
	getchar();
}