#include<stdio.h>
void main()
{
	int x[8]={10,20,30,40,50,60,70,80};
	printf("what is the meaning of x\n");
	printf("the address location of x is %d\n",x);
	printf("what is the meaning of(x+2)\n");
	printf("the address location of(x+2) is %d\n",            (x+2));
	printf("what is the value of *x\n");
	printf("the value at x[0] is %d\n",*x);
	printf("what is the value of(*x+2)\n");
	printf("%d\n",(*x+2));
	printf("what is the value of *(x+2)\n");
	printf("%d\n",(*(x+2)));
}