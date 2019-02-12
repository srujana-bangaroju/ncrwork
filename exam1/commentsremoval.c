#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void remove(FILE* fp) 
{
	FILE *fp2 = fopen("result.txt", "w");
	char c2;
	do
	{
		if (feof(fp))
			break;
		char c = fgetc(fp);
		if (feof(fp))break;
		if (c == '/')
		{
			c2 = fgetc(fp);
			if (c2 == '/')
			{
				while (1) 
				{
					c2 = fgetc(fp);
					if (feof(fp))break;
					if (c2 == '\n')break;
					
				}
			}
			else if(c2=='*')
			{
				int tell = ftell(fp);
				tell = tell - 2;
				while (1)
				{
					c2 = fgetc(fp);
					if (feof(fp))
					{
						fseek(fp, tell, SEEK_SET);
						c = fgetc(fp);
						fputc('/', fp2);
						break;
					}
					c = fgetc(fp);
					if (feof(fp))
					{			
						fseek(fp, tell, SEEK_SET);
						c = fgetc(fp);
						fputc('/', fp2);
						break;
					}
					if (c2 == '*' && c=='/')
					{
						break;
					}
					else if (c2 == '/'&&c == '*')
					{
			
						fseek(fp, tell, SEEK_SET);
						c = fgetc(fp);
						fputc('/', fp2);
						break;
					}
				}
			}
			else 
			{
				fputc(c, fp2);
			}
			//fwrite(tab, sizeof(tab), 1, fp);
		}
		else 
		{
			fputc(c, fp2);
		}

	} while (1);
	fclose(fp2);
	fclose(fp);
	getchar();
}