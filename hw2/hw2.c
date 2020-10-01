/*
 *Nathaniel Callahan
 *ntctk4
 *HW2
 *
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check_input(int);
void initialize_array(int[], int);
void print_array(int[], int);
void display_menu();
int check_option(int);
int common_numbers(int[], int[], int);
int count_numbers(int[], int, int);
int mode(int[], int);
void print_histogram(int[], int[], int);


int main(void)
{
	int input;//input from the user
	int x;//counter for switch statment
	int y;//holds function values in while loops
	int z;//operation to perform

	int a[100]={0};//array a
	int b[100]={0};//array b

	srand(time(NULL));//used to randomize arrays

	printf("\nEnter the size of the input:");
	scanf("%d", &input);

	y = check_input(input);//function to check input

	while(y != 1)//error checking
	{
		printf("Invalid input enter the size of the input again:");
		scanf("%d", &input);

		y = check_input(input);
	}
	
	while (z != 4)//loop to do options 1-3
	{
	
		initialize_array(a, input);//initializes array a

		initialize_array(b, input);//initializes array b


		display_menu();//shows menu options to user
	
		printf("Enter the operation you want to perform:");
		scanf("%d", &z);

		y = check_option(z);//function to check input

		while (y != 1)//error checking
		{
			printf("Invalid option enter the option agian:");
			scanf("%d", &z);

			y = check_option(z);
		}

		if( z != 4)//prints arrays when option isn't 4
		{

			printf("\nInput arrays\n");

			print_array( a, input);

			print_array( b, input);
		}


		switch(z)//switch statment for each option
		{
			case 1://option 1
			x = common_numbers(a, b, input);//checks for common numbers

			printf("\nThere are %d common numbers between the two arrays\n", x);
		
			break;//break case 1

	
			case 2://option 2
			x = mode( a, input);//finds mode for a
	
			printf("\nMode for the first array is number %d",x);

			x = mode(b, input);//finds mode for b

			printf("\nMode for the second array in number %d\n", x);

			break;//break case 2

		
			case 3://option 3
			print_histogram(a, b, input);//makes histogram from arrays a and b

			break;//break case 3
		}
	}

	printf("\n");

	return 0;




}//end main



int check_input(int input)//error checking
{
	if(input > 0 && input < 101)//makes sure input is between 1 and 100
		return 1;

	else 
		return 0;
}//end of function



void initialize_array(int a[], int input)//initializes both arrays
{
	int i;//counter
	int j;//random number for array

	for(i=0; i<input; i++)//puts random numbers in array
	{
		j=rand()%10;
		a[i]=j;
	}
}//end function



void print_array(int array[], int input)//prints out both arrays
{
	int i;//counter

	for(i=0; i<input; i++)//loops through array to print it
	{
		printf("%d ", array[i]);
	}
	
	printf("\n");
}// end function



void display_menu()//displays options
{
	printf("\nArray operations, your options are:\n\n1: Common Numbers\n2: Mode\n3: Histogram\n4: Exit\n");


}//end function



int check_option(int z)//error checking 
{
	if(z > 0 && z < 5)//makes sure user puts in valid input
		return 1;

	else 
		return 0;

}//end function



int common_numbers(int a[], int b[],int input)//checks for common numbers between the arrays
{

	int i;//first for loop counter
	int j;//second for loop counter
	int frequency=0;

	for(i=0; i<input; i++)//for loop for first array
	{
		for(j=0; j<input; j++)//for loo[ for second array
		{
		if(a[i] == b[j])//if elements are equal bump frequency
			frequency++;
		}
	}

	return frequency;
}//end function



int count_numbers(int array[], int input, int y)//counts amount of each number in array
{
	int i;//counter
	int frequency=0;//frequency of number, starts at 0

	for(i=0; i<input; i++)//loop to go through array
	{
		if(array[i] == y)//if element equal the number bump the frequency
			++frequency;

	}

	return frequency;

}//end function



int mode(int array[], int input)//finds mode of an array
{
	int i;//counter
	int modeFrequency=0;//frequency of mode
	int j;//variabe to hold count_number value
	int mode;//variable for mode

	for(i=0; i<input; i++)//loop to go through array
	{
		j = count_numbers(array, input, array[i]);//finds frequency

		if(modeFrequency < j)//determines mode
		{
			modeFrequency = j;
			mode=array[i];
		}	
	}
	
	return mode;
}//end function



void print_histogram(int a[], int b[], int input)//prints histogram
{
	
	int i;//counter for first for loop
	int x;//frequency of current number in a
	int y;//frequency of current number in b
	int sum;//total frequency
	int j;//counter for second for loop

	printf("\nPrinting histogram\n\n");
	
	for(i=0; i<10; i++)//loop through all possible number options
	{
	
		x = count_numbers(a, input, i);//counts numbers in array a

		y = count_numbers(b, input, i);//counts numbers in array b

		sum = x + y;//adds array a and b 

		printf("\n%d:", i);

		for(j=0; j<sum; j++)//prints off bars for histogram
		{
			printf("%c", '*');
		}
	}
	printf("\n");
}//end function
