#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
long g_x = 0;
DWORD WINAPI thread_func1(LPVOID lparam)
{
	
	g_x++;
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{
	
	g_x++;
	return 0;
}
int main()
{
	DWORD thid1, thid2;
	HANDLE hthread1, hthread2;
	HANDLE arry_hand[2];
	while (1)
	{
		g_x = 0;
		hthread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &thid1);
		if (hthread1 == NULL)
		{

			printf("Unable to thread to create %d", GetLastError());
			getchar();
			return FALSE;
		}
		hthread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &thid2);
		if (hthread2 == NULL)
		{

			printf("Unable to thread to create %d", GetLastError());
			getchar();
			return FALSE;
		}
		arry_hand[0] = hthread1;
		arry_hand[1] = hthread2;
		WaitForMultipleObjects(2, arry_hand, TRUE, INFINITE);

		printf("g_x value is %d\n", g_x);
		if (g_x == 1)
			break;
	}
	CloseHandle(hthread1);
	CloseHandle(hthread2);
	printf("Waiting for user input to exit\n");
	getchar();
	return 0;
}