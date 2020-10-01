/*
 *Nathaniel Callahan
 *ntctk4
 *lab code: Monday, Lab-5
 *lab 5
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check_size(int);
void initialize_array(int);
void print_array(int);
int max(int);
int min(int);
float average(int);
void compute_stats(int);
int search(int, int);
int count_number(int, int);

	int array[100]={0};//global array

int main(void)
{
	int x;
	int y;
	int z;
	float  index;
	int c;

	srand(time(NULL));

	printf("Enter the size of the input:");
	scanf("%d", &x);

	y = check_size(x);

	while(y != 1) 
	{
		printf("Invalid input enter the size of the input again:");
		scanf("%d", &x);

		y = check_size(x);
	}

	initialize_array(x);

	print_array(x);

	compute_stats(x);

	
	
	printf("\n\nEnter the number you want to search:");
	scanf("%d", &z);

	index = search(x, z);
	
	
	if(index ==  -1)
		printf("The number %d is not present in the array", z);
		
	else 
		printf("The number %d is present at the index %d", z,index);

	
	
	printf("\n\nEnter the number you want to count:");
	scanf("%d", &z);

	 c = count_number(x, z);


	if(index == 0)
		printf("The number %d is not present in the array", z);

	else
		printf("The number %d is present %d times in the array",z,c);


	return 0;
}	

void compute_stats(int x)
{
	int index;
	float ave;

	index = max(x);

	printf("\n\nLargest number is %d", array[index]);

	index = min(x);

	printf("\nSmallest number is %d", array[index]);

	ave  = average(x);

	printf("\nAverage of numbers is %.3f", ave);

}

int check_size( int x)
{
	if (x > 0 && x < 101)
		return 1;

	else
		return 0;
}

void initialize_array(int x)
{
	int i;
	int t;

	for(i=0; i<x; i++)
	{
		t=rand() %10;
		array[i]=t;
	}
}

void print_array(int x)
{
	int i;

	printf("\nInput array\n");

	for (i=0; i<x; i++)
		printf("%d ", array[i]);
}

int max(int x)
{
	int i;
	int index;
	int m=0;

	for(i=0; i<x; i++)
	{
		if (array[i] > m)
		{
			m = array[i];
			index = i;
		}
	}
	return index;
}

int min(int x)
{
	int i;
	int index;
	int m=100;

	for(i=0; i<x; i++)
	{
		if (array[i] < m)
		{
			m = array[i];
			index = i;
		}
	}
	return index;
}

float average(int x)
{
	float sum;
	int total=0;
	int i;

	for(i=0; i<x; i++)
	{
		total += array[i];

	}

	
	sum = (float)total/x;
	
	return sum;
}

int search(int x, int z)
{
	int i;
	int index;

	for(i=0; i<x; i++)
	{
		if(array[i] == z)
			return i;
	
	}

	return -1;
}

int count_number(int x, int z)
{

	int i;
	int index=0;

	for(i=0; i<x; i++)
	{
		if(array[i] == z)
		{
			++index;
		}

	}

	return index;

}
