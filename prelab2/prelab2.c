#include <stdio.h>

int main(void)
{

	int num1;
	int num2;
	int sum = 0;
	int product = 0;

	printf("Enter first number: ");
	scanf("%d", &num1 );

	if (num1 <= 0) {
		printf("Invalid number enter the number again: ");
		scanf("%d", &num1 );
	}
	
	printf("Enter second number: ");
	scanf("%d", &num2 );
		
	if (num2 <= 0) {
		printf("Invalid number enter the number again: ");
		scanf("%d", &num2 );
	}

	printf("The two numbers provided by the user are %d and %d\n", num1, num2);

	if (num1 > num2) {
		printf("%d is the bigger number\n", num1);
	}

	else if (num1 < num2) {
		printf("%d is the bigger number\n", num2);
	}
	
	else {
		printf("The two numbers are equal\n");
	}

	sum = num1 + num2;

	printf("Sum of the two numbers is %d\n", sum);

	product = num1 * num2;

	printf("Product of the two numbers is %d\n", product);
}

