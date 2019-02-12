#include <stdio.h>
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main()
{
	printf("enter the numbers\n");
	int number1, number2;
	scanf("%d", &number1);
	scanf("%d", &number2);
	int choice = -1;

	while (choice != 5)
	{
		printf("enter the choice you want\n");
		printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
		scanf("%d", &choice);
		switch (choice) {

		case 1: 
				printf("Addition of %d and %d is %d\n",number1,number2, add(number1, number2));
			break;
		case 2: printf("subtraction of %d and %d is %d\n", number1, number2, sub(number1, number2));
			break;
		case 3: printf("multiplication of %d and %d is %d\n", number1, number2, mul(number1, number2));
			break;
		case 4: printf("Division of %d and %d is %d\n", number1, number2, div(number1, number2));
			break;
		case 5: break;
		}
		printf("\n");
		}
}
