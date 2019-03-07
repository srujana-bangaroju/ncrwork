#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
void DumpEnvStrings(PTSTR[]);
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envVarStrings0[] = TEXT("%SystemRoot%");
	TCHAR envVarStrings1[] = TEXT("%windir%");
	
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarStrings0, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%ls\n", buffer);
	ret = ExpandEnvironmentStrings(envVarStrings1, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%ls\n", buffer);
	
	getchar();
	return 0;

}
void DumpEnvStrings(PTSTR pEnvBlock[])
{
	int curr = 0;
	PTSTR *pele = (PTSTR *)pEnvBlock;
	PTSTR pCurrent = NULL;
	while (pele != NULL)
	{
		pCurrent = (PTSTR )(* pele);
		if (pCurrent == NULL)
			pele = NULL;
		else
		{
			_tprintf(TEXT(" [%u] %s\r\n"), curr, pCurrent);
			curr++;
			pele++;
		}


	}
	
}