#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int check_size(int);
void initialize_2Darray(int [][MAX], int);
void print_2Darray(int[][MAX], int);
int smallest_number(int[][MAX], int);


int main(void)
{

	int input;
	int y;
	int index;

	int array[MAX][MAX]={0};

	srand(time(NULL));

	printf("Enter the size of the input:");
	scanf("%d", &input);

	y = check_size(input);

	while(y != 1)
	{
		printf("Invalid input enter the size of the input again:");
		scanf("%d", &input);

		y = check_size(input);
	}

	initialize_2Darray(array, input);

	print_2Darray(array, input);

	y = smallest_number(array, input);

	printf("\nThe smallest number in the array is %d", y);

	return 0;
}

int check_size(int input)
{

	if(input > 0 && input < 101)
		return 1;

	else
		return 0;
}

void initialize_2Darray(int array[][MAX], int input)
{
	int i;
	int j;
	int t;

	for(i=0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
			t=rand()%100;
			array[i][j]=t;
		}
	}
}

void print_2Darray(int array[][MAX], int input)
{
	int i;
	int j;

	printf("\nInput 2D array\n");

	for(i=0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}


int smallest_number(int array[][MAX],int input)
{
	int i, j, min, index;

	for(i=0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
			if(array[i][j] < min)
			{
				min = array[i][j];
			}
		}
	}
	return min;
}
