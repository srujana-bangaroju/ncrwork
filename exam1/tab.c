#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void replaceTabs(FILE* fp)
{
	FILE* fp2 = fopen("result.txt", "w");
	char tab[] = "\\t";
	do
	{
		if (feof(fp))
		{
			break;
		}
		char c = fgetc(fp);
		if (feof(fp)) 
		{
			break;
		}	
		if (c == '\t')
		{
			//fwrite(tab, sizeof(tab), 1, fp);
			printf("tab");
			fputs(tab, fp2);
		}
		else
		{
			fputc(c, fp2);
		}

	} while (1);
	fclose(fp2);
	fclose(fp);
	getchar();
	return;
}