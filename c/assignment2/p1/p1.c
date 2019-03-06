#include<stdio.h>
#include<math.h>
void main()
{
	int num1=0,k,x[50],y[50],i,j,bin,dec,len,l=0,base=1,a;
	printf("enter the binary number\n");
	scanf_s("%d",&bin);
	len=sizeof(bin);
	for(i=0;i<len;i++)
	{
		k=bin%10;
		num1=num1+(k*base);
		bin=bin/10;
		base=base*2;
	}
	printf("the converted decimal number is %d",num1);

	printf("enter the decimal number\n");
	scanf_s("%d",&dec);
	for(i=0;dec>0;i++)
	{
		x[i]=dec%2;
		dec=dec/2;
		l++;
	}
	for(i=0,j=(l-1);j>=0;i++,j--)
	{
		y[i]=x[j];
		printf("%d",y[i]);
	}
scanf_s("%d",&a);

}