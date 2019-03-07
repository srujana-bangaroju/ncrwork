#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
void main()
{
	char c='B';
	wchar_t wc=L'A';
	printf("\ncharacter is :%c", c);	
	printf("\nwide character is %C", wc);
	CHAR ansiArray[] = "ANSI";
	WCHAR wideArray[]= L"WIDE";
	printf("\ncharcter ansi array is %s", ansiArray);
	printf("\ncharacter wide array is %S", wideArray);
	TCHAR tc = TEXT('D');
	printf("\ntext char is %c", tc);
	int res;
	res = IsTextUnicode(ansiArray, strlen(ansiArray), NULL);
	if (res == 0)
	{
		printf("\nansiArray is not unicode");
	}
	else
	{
		_tprintf(_T("\nansiArray is unicode"));
	}
	res = IsTextUnicode(wideArray, wcslen(wideArray), NULL);
	if (res == 0)
	{
		printf("\nwideArray is not unicode");
	}
	else
	{
		printf("\nwideArray is unicode");
	}
	int size;
	size = MultiByteToWideChar(CP_UTF8, 0, ansiArray, -1, NULL, 0);
	if (size == 0)
	{
		printf("\nthe error occured is %d",GetLastError());
	}
	else
		printf("\nsize of ansiArray is %d", size);
	WCHAR *ansitowide = new WCHAR[size];
	size=MultiByteToWideChar(CP_UTF8, 0, ansiArray,-1, ansitowide, size);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
		return;
	}
	else
		printf("\nthe ansitowide contains %S", ansitowide);
	size = WideCharToMultiByte(CP_UTF8, 0, wideArray, -1, NULL, 0, NULL, NULL);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
		return;
	}
	else
		printf("\nsize of ansiArray is %d", size);

	CHAR *widetoansi = new CHAR[size];
	size=WideCharToMultiByte(CP_UTF8, 0, wideArray, -1, widetoansi, size, NULL, NULL);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
	}
	else
		printf("\nthe widetoansi contains %s", widetoansi);
	delete(ansitowide);
	delete(widetoansi);
	getchar();	

}