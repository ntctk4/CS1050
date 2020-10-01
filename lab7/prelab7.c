#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void initialiaze_array(int *, int);
void print_array(int *, int size);
int check_size(int);
int count_even(int*, int);

int main(void)
{
	int *aPtr;
	int input;
	int y;
	int x;

	srand(time(NULL));

	printf("Enter the size of the input:");
	scanf("%d", &input);

	y = check_size(input);

	while(y != 1)
	{
		printf("Invalid input enter the size of the array again:");
		scanf("%d", &input);

		y = check_size(input);
	}

	initialiaze_array(aPtr, input);

	print_array(aPtr, input);

	x = count_even(aPtr, input);

	printf("\n\nThere are %d even numbers present in the array", x);

	return 0;

}

int check_size(int input)
{
	if(input>0 && input<101)
		return 1;
	else
		return 0;
}

void initialiaze_array(int *aPtr, int input)
{
	int i;

	for(i=0; i<input; i++)
	{
		*aPtr=rand()%10;
		aPtr++;
	}
}

void print_array(int *aPtr, int input)
{
	int i;

	printf("\n\nInput array\n");

	for(i=0; i<input; i++)
	{
		printf("%d ", *aPtr);
		aPtr++;
	}
}

int count_even(int *aPtr, int input)
{
	int i;
	int frequency=0;

	for(i=0; i<input; i++)
	{
		if(*aPtr %2 == 0)
		{ 
			++frequency;
		}
		
		aPtr++;
	}
	return frequency;
}
