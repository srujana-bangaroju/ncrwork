#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void replaceTabs(FILE* fp);
void count(FILE* fp);
void remove(FILE* fp);
void rotate(FILE* fp);
int main()
{
	int ch = 0;
	char file[20];
	while (ch != 5)
	{
		printf("\nEnter File name : \n");
		scanf("%s", file);
		FILE * fp;
		fp=fopen(file, "r");
		printf("Enter choice : \n 1) count 2)Remove comments 3)Rotate 4)Replace Tabs 5)Exit\n");
		scanf("%d", &ch);
		switch (ch) 
		{
		case 1:
			count(fp);
			break;
		case 2:
			remove(fp);
			break;
		case 3:
			rotate(fp);
			break;
		case 4:
			replaceTabs(fp);
			break;
		case 5:
			break;
		default:
			break;
		}		
	}
}