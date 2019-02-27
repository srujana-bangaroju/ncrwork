//coding conventions 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<WinDef.h>
int main()
{
	BYTE x;
	scanf("%c",&x);
	printf("size of x=%c", strlen((char *)x));
}