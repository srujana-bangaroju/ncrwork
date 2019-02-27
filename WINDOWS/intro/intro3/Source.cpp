//command line to argument conversion
#include <windows.h>
#include <stdio.h>
#include <shellapi.h>
#include<tchar.h>
using namespace std;
constexpr auto INFO_BUFFER_SIZE = 32767;//src or dest max limit is 32k
int _tmain(int argc,      // Number of strings in array argv
	TCHAR *argv[],   // Array of command-line argument strings
	TCHAR *envp[])  // Array of environment variable strings
{
	LPWSTR *szArglist;
	int nArgs;
	int i, BufferCharCount1, BufferCharCount2, BufferCharCount3;
	TCHAR InfoBuf1[INFO_BUFFER_SIZE],InfoBuf2[INFO_BUFFER_SIZE],InfoBuf3[INFO_BUFFER_SIZE];
	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (NULL == szArglist)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	else for (i = 0; i < nArgs; i++) 
		printf("%d: %ws\n", i, szArglist[i]);
//Printing environment strings
	BufferCharCount1 = ExpandEnvironmentStrings("%TEMP%", InfoBuf1, INFO_BUFFER_SIZE);
	BufferCharCount2 = ExpandEnvironmentStrings("%WINDIR%", InfoBuf2, INFO_BUFFER_SIZE);
	BufferCharCount3 = ExpandEnvironmentStrings("%SYSTEMROOT%", InfoBuf3,INFO_BUFFER_SIZE);
//path
	if (BufferCharCount1 > INFO_BUFFER_SIZE)
		wprintf(L"Buffer is too small to expand:\%S\n", InfoBuf1);
	else
		wprintf(L"\n%S\n", InfoBuf1);
//windir
	if (BufferCharCount2 > INFO_BUFFER_SIZE)
		wprintf(L"Buffer is too small to expand:\%S\n", InfoBuf2);
	else
		wprintf(L"\n%S\n", InfoBuf2);
//systemroot
	if (BufferCharCount3 > INFO_BUFFER_SIZE)
		wprintf(L"Buffer is too small to expand:\%S\n", InfoBuf3);
	else
		wprintf(L"\n%S\n", InfoBuf3);
// Free memory allocated for CommandLineToArgvW arguments.
	LocalFree(szArglist);
	system("pause");
	return(1);
}
