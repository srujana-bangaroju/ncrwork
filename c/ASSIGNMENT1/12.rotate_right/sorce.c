#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int rotate_right(int, int);
int pow(int, int);
int main()
{
	int num,x, rotate_count, newnum;
	char exit;
	printf("ENTER THE INTEGER : ");
	scanf_s("%d", &num);
	printf("\nNUMBER OF ROTATIONS TO RIGHT : ");
	scanf_s("%d", &rotate_count);
	newnum = rotate_right(num, rotate_count);
	printf("\nNUMBER AFTER %d RIGHT ROTATIONS : %d", rotate_count, newnum);
	
	scanf("%d", &x);
	getchar();
}