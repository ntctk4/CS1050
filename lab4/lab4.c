/*
 *Nathaniel Callahan
 *Lab4
 *Lab code: Monday, June23
 *
 *
 **/
#include<stdio.h>
#include<math.h>

void display_menu(void);//prototype for display_menu function
int check_option(int);//protoype for check_option function
int check_amount(float);//prototpe for check_amount function
int check_year(int);//prototype for check_year function

int main(void)//main function
{

	int account;//variable for the account type
	int y;//variable used to check if inputs are valid
	float amount;//variable for the amount put in the account
	unsigned int year;//variabel for the number of years money is in the account
	float interest;//variable for interest amount that each account holds
	float amountci;// variable to hold the amount put in plus the interest made
	float rate;//variable used to hold the rate of intrest each account has

	display_menu();//called function to display the menu to the user

	printf("\n\nPlease make a selection:");
	scanf("%d", &account);

	y = check_option(account);//called function to check if the the entered is a valid account type

	while(y != 1) {//loop for error checking to make sure a valid number is entered for an account type before program continues
		printf("Invalid choice enter the choice again:");
		scanf("%d", &account);

		y = check_option(account);//called function to check again to see if number entered is a valid account type
	}
	
	printf("\n\nEnter the amount:$");
	scanf("%f", &amount);

	y = check_amount(amount);//called function to check for a valid amount 

	while (y != 1) {//error checking loop to make sure a valid amount is entered before program continues
		printf("Amount should be positive enter the amount again:$");
		scanf("%f", &amount);

		y = check_amount(amount);//called function to check for valid amounts
	
	}

	printf("\n\nEnter a year:");
	scanf("%d", &year);

	y = check_year(year);//called function to check for a valid year between 1-10

	while (y != 1) {//error loop checking to make sure a valid year is entered before program continues
		printf("Year should be between 1-10 enter the amount again: ");
		scanf("%d", &year);

		y = check_year(year);//called function to check for a valid year between 1-10
	}

	switch (account) {//used to relate account type to the rate of intrest made in each account

		case 1://account type is checking
		rate = 1.25;
		break;//exits switch

		case 2://account type is saving
		rate = 3.5;
		break;//exits switch

		case 3://account type is fixed deposit
		rate = 5.75;
		break;//exits switch
	}

	amountci = (float)amount * pow(1+ (float)(rate/100),year);//formula used to calculate compound interest 

	interest = amountci - amount;//formula used to calculate interest made

	printf("\n\nTotal amount after %d years at the interest rate of %.2f%% is $%.2f\nTotal interest earned in %d years on the amount $%.2f is $%.2f\n",year, rate, amountci, year, amount, interest);

	return 0;//main returns 0
	}


void display_menu()//function to display the account options 
{
	printf("\nBank account type\n(1)Checking\n(2)Saving\n(3)Fixed Deposit");

	}


int check_option(int z) // function to check for valid account options
{
	if (z > 0 && z < 4)
		return 1;//return 1 for a valid account option

	else
		return 0;//return 0 for numbers that don't have a valid account option
	}

int check_amount(float a)//function to check for valid amount entered
{
	if (a > 0)
		return 1;//return 1 for a valid amount entered

	else
		return 0;//return 0 for an invalid amount entered
	}

int check_year(int y)//function to check for valid year from 1-10
{
	if (y > 0 && y < 11)
		return 1;//return 1 for a valid year entered

	else
		return 0;//return 0 for an invalid year entered
	} 
