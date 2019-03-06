#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void rotate(FILE* fp) 
{
	char s[50], s2[50];
	int chk = 0;
	printf("Enter a string");
	scanf("%s", s);
	char c;
	FILE* fp2 = fopen("result.txt", "w");
	int size = strlen(s);
	do
	{
		if (feof(fp)) 
		{
			break;
		}	
		c = fgetc(fp);
		if (feof(fp)) 
		{
			break;
		}
		int i = 0;
		while (1)
		{
			if (c == ' ' || c == '\n' || c=='\t') 
			{
				s2[i] = '\0';
				break;
			}
			s2[i++] = c;
			c = fgetc(fp);
			if (feof(fp))
			{
				s2[i++] = '\0';
				break;
			}
		}
		if (strcmp(s,s2)==0)
		{
			_strrev(s2);
			fputs(s2, fp2);
		}
		else
		{
			fputs(s2, fp2);
		}
		if (c == ' ' || c == '\n' || c == '\t') 
		{
			fputc(c, fp2);	
		}

	} while (1);
	fclose(fp2);
	fclose(fp);
	getchar();
}