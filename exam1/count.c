#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void count(FILE* fp)
{
	int alpha= 0, digits = 0, spaces = 0, splchars = 0;
	do
	{
		if (feof(fp)) 
		{
			splchars--;
			break;
		}
		char c = fgetc(fp);
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		alpha++;
		else if ('0' <= c && c <= '9')
		digits++;
		else if (c == ' ')
		spaces++;
		else
		splchars++;
		if (c == '\n' || c == '\t')
		sc--;
	}
	while (1);
	printf("%d- alphabets , %d - digits ,%d - spaces ,%d - special characters",alpha,digits,spaces,splchars);
	getchar();
	fclose(fp);
	return;
}