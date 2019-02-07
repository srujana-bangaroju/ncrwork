#include<stdio.h>
void main()
{
	int i,num,a[8],count=0,num1;
	printf("enter the number\n");
	scanf_s("%d",&num);
	for(i=8;i>0;i--)
	{
		num1=num%2;
		num=num/2;
		a[i-1]=num1;
	}
	for(i=0;i<8;i++)
	{
		if(a[i]==1)
		count++;
	}
	printf("number of ones in the number is %d",count);
}