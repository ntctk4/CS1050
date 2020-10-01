/*
*Nathaniel Callahan
*Lab 3
*Lab Code: Compile (gcc) with -lm option
*
*
* */
#include<stdio.h>
#include<math.h>

int main(void)
{
	float amountci;
	float amount;
	float rate;
	unsigned int year;
	float interest;

	printf("Enter the amount:");
	scanf("%f", &amount);

	while (amount <= 0) {
	printf("Invalid amount enter the amount again:");
	scanf("%f",&amount);
	} 

	printf("\nEnter the year:");
	scanf("%d",&year);

	while (year < 1 || year > 10) {
	printf("Invalid year enter the year again:");
	scanf("%d", &year);
	}

	printf("\nEnter the account type:");
	scanf("%f", &rate);
	

	while(rate  <= 0 || rate >= 4) {
	printf("Invalid account type enter the account type again:");
	scanf("%f", &rate);
	}	

	if(rate == 1){
	rate = 1.25;
	}

	else if(rate == 2){
	rate = 3.5;
	}

	else if (rate == 3){
	rate = 5.75;
	}

	amountci = (float)amount * pow(1+(float)(rate/100),year);

	interest = amountci - amount;

	printf("\nAmount after %d years with the interest rate of %.2f%% is $%.2f\nInterest earned is $%.2f", year, rate, amountci, interest);

return 0;
}
