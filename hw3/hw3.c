/*
 *Nathaniel Callahan
 *ntctk4
 *HW#
 *
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

//prototypes
void display_menu();
int check_option(int);
int check_size(int);
void initialize_2Darray(int x[][MAX], int size);
void print_2Darray(int x[][MAX], int size);
void initialize_1Darray(int y[], int size);
void print_1Darray(int y[], int size);
int search_max(int x[][MAX], int r, int c, int size);
float average(int x[][MAX], int r, int c, int size);
void sort_1Darray(int y[], int size);
void sort_2Darray(int x[][MAX], int size);
float median(int y[], int size);

int main(void)
{
	int input;//input variable
	int y;//check variable
	int option;//variable for user option choice
	int x;//holder for function values
	int r;//variable for row
	int c;//variable for column
	float z;//holder for float functions

	int a[MAX][MAX];//2D array
	int b[MAX];//1D array

	srand(time(NULL));

	printf("Enter the size:");
	scanf("%d", &input);

	y = check_size(input);

	while(y != 1)
	{
		printf("Invalid input enter the size of the array agian:");
		scanf("%d", &input);

		y = check_size(input);
	}

	while(option != 6)
	{
		initialize_2Darray(a, input);

		initialize_1Darray(b, input);

		display_menu();

		printf("\nEnter the operation you want to perform:");
		scanf("%d", &option);

		y = check_option(option);

		while(y != 1)
		{
			printf("Invalid option enter option  again:");
			scanf("%d", &option);

			y = check_option(option);
		}

		switch(option)
		{
			case 1:
			
			printf("\n\n2D array\n");

			print_2Darray(a, input);

			printf("\n\nEnter the row (1-%d):", input);
			scanf("%d", &r);

			printf("\n\nEnter the col (1-%d):", input);
			scanf("%d", &c);

			x = search_max(a, r, c, input);

			printf("\n\nThe largest number present the row %d and col %d is %d\n",r, c, x);
			break;

			
			case 2:

			printf("\n\n2D array\n");

			print_2Darray(a, input);

			printf("\n\nEnter the row (1-%d):", input);
			scanf("%d", &r);

			printf("\n\nEnter the col (1-%d):", input);
			scanf("%d", &c);

			z = average(a, r, c, input);

			printf("\nThe average of the numbers present the row %d and col %d is %.3f\n", r, c, z);

			break;


			case 3:

			printf("\n\n1D Array before sorting\n");

			print_1Darray(b, input);
			
			sort_1Darray(b, input);

			printf("\n\n1D Array after sorting\n");

			print_1Darray(b, input);

			break;


			case 4:
			
			printf("\n\n1D Array\n");

			print_1Darray(b, input);
			
			sort_1Darray(b, input);
			
			z = median(b, input);

			printf("\n\nMedian is %.2f", z);

			break;


			case 5:

			printf("\n\n2D Array before sorting\n");

			print_2Darray(a, input);

			sort_2Darray(a, input);

			printf("\n\n2D Array after sorting\n");

			print_2Darray(a, input);

		}
	}
	printf("\n");

	return 0;
}

void display_menu()
{
	printf("\n\nArray operations, your options are:\n\n1:Search Max\n2:Average\n3:Sort 1D Array\n4:Median\n5:Sort 2D Array\n6:Exit");
}

int check_option(int input)
{
	if (input > 0 && input < 7)
		return 1;

	else
		return 0;
}

int check_size(int input)
{
	if (input > 0  && input < 101)
		return 1;
	else
		return 0;
}

void initialize_2Darray(int x[][MAX], int input)
{
	int i;
	int j;
	int t;

	for(i=0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
			t = rand()%10;
			x[i][j]=t;
		}
	}
}

void print_2Darray(int x[][MAX], int input)
{
	int i;
	int j;


	for(i=0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
			printf("%d ", x[i][j]);
		}

		printf("\n");
	}
}

void initialize_1Darray(int y[], int input)
{
	int i;
	int t;

	for(i=0; i<input; i++)
	{
		t = rand()%10;
		y[i]=t;
	}
}

void print_1Darray(int y[], int input)
{
	int i;

	for(i=0; i<input; i++)
	{
		printf("%d ", y[i]);
	}
}

int search_max(int a[][MAX], int r, int c, int input)
{

	int i;
	int j;
	int max = 0;

	for(j = 0; j<input; j++)
	{
		if(a[r-1][j] > max)
		{
			max = a[r-1][j];
		}
	}

	for (i = 0; i<input; i++)
	{
		if(a[i][c-1] > max)
		{
			max = a[i][c-1];
		}
	}
	return max;
}

float average(int a[][MAX], int r, int c, int input)
{

	int i;
	int j;
	float sum;
	int total = 0;

	for(j = 0; j<input; j++)
	{
		for(i=0; i<input; i++)
		{
		if(i == r-1)
			total += a[i][j];
		}
	}

	for(i = 0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
		if(j == c-1 && i != r-1)
			total += a[i][j];
		}
	}


	sum = (float)total/(input*2-1);

	return sum;
}

void sort_1Darray(int y[], int input)
{
	int i;
	int pass;
	int hold;

	for(pass = 1; pass < input; pass++)
	{
		for(i=0; i<input-1; i++)
		{
			if(y[i]> y[i+1])
			{
				hold = y[i];
				y[i] = y[i+1];
				y[i+1] = hold;
			}
		}
	}
}

void sort_2Darray(int a[][MAX], int input)
{
	int i;
	int j;
	int pass;
	int hold;

	for(pass = 1; pass < input; pass++)
	{
		for(i=0; i<input; i++)
		{
			for(j=0; j<input-1; j++)
			{
				if(a[i][j] > a[i][j+1])
				{
					hold = a[i][j];
					a[i][j] = a[i][j+1];
					a[i][j+1] = hold;
				}
			}
		}
	}
}

float median(int y[], int input)
{
	float median;

	if(input%2 == 0)
	{
		median = (float)((y[input/2])+(y[input/2-1]))/2;
	}

	else 
		median = y[input/2];
	
	return median;
}

