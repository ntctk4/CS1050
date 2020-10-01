
#include <stdio.h>

int main(void)
{

	int number;

	printf("Enter a positive number:");
	scanf("%d", &number );

	while ( number <= 0) {
		printf("Number should be positive enter the number again:");
		scanf("%d", &number);

	}

	printf("\n\nThe positive number entered is %d", number);
} 
