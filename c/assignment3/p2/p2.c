#include<stdio.h>
void main()
{
	int a[50],b[50],i,j=0,l,x;
	printf("enter the array size\n");
	scanf_s("%d",&l);
	printf("enter the array elements\n");
	for(i=0;i<l;i++)
	{
		scanf_s("%d",&a[i]);
	}
	for(i=0;i<l;i++)
	{
		if (a[i] < 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for(i=0;i<l;i++)
	{
		if (a[i] > 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < l; i++)
	{
		printf("%d", b[i]);
	}
	scanf_s("%d", &x);
}
