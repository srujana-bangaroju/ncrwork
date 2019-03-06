#include<stdio.h>
void main()
{
	int a[50],l,sum,temp,i,j=0,x;
	printf("enter the array size\n");
	scanf_s("%d",&l);
	printf("enter the array elements\n");
	for(i=0;i<l;i++)
	{
		scanf_s("%d",&a[i]);
	}
	printf("enter the sum value\n");
	scanf_s("%d",&sum);
	for(i=0;i<l;++i)
	{
		temp = 0;
		j = i;
		while ((j < l) && (temp <= sum))
		{
				temp = temp + a[j];
				if (temp == sum)
				{
					printf("sum found between indexes %d and %d", i, j);
				}j++;
		}
	}
	scanf_s("%d", &x);
}