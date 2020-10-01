/*
 *Nathaniel Callahan
 *ntctk4
 *Lab code:Use pointer notation
 *Lab 7
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void initialiaze_array(int *, int);
void print_array(int *, int size);
int count_even(int *, int);
int max(int *, int);
int min(int *, int);
int count_duplicate(int *, int);


int main(int argc, char *argv[])
{


	int *aPtr;
	int n;
	int y;
	int x;
	int z;
	int b[MAX];
	int q;

	aPtr = b;

	srand(time(NULL));

	if (argc != 2)
	{
		printf("\n Not enough arguments\n");
		return 0;
	}

	n = atoi(argv[1]);


	initialiaze_array(aPtr, n);

	printf("\nInput array\n");

	print_array(aPtr, n);

	x = max(aPtr, n);

	y = min(aPtr, n);
	
	z = count_even(aPtr, n);

	q = count_duplicate(aPtr, n);

	if( z == 0)
		printf("\n\nThere are no even numbers in the array\n");
	else
		printf("\n\nThere are %d even numbers present in the array\n", z);

	printf("Largest number present in the array is %d at the index %d\n", *(aPtr+x), x);

	printf("Smallest number present in the array is %d at the index %d\n", *(aPtr+y), y);

	printf("There are %d duplicate numbers present in the array", q);

	
	return 0;
}

void initialiaze_array(int *aPtr, int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		*aPtr=rand()%10;
		aPtr++;
	}
}

void print_array(int *aPtr, int n)
{
	int i;
	
	for(i=0; i<n; i++)
	{
		printf("%d ", *aPtr);
		aPtr++;
	}
}

int count_even(int *aPtr, int n)
{
	int i;
	int frequency=0;

	for(i=0; i<n; i++)
	{
		if(*aPtr %2 == 0)
		{
			++frequency;
		}

		aPtr++;
	}
	return frequency;
}

int max(int *aPtr, int n)
{

	int i;
	int max = 0;
	int index = 0;

	for(i=0; i<n; i++)
	{
		if(*aPtr > max)
		{
			max = *aPtr;
			index = i;
		}

		aPtr++;
	}
	return index;
}

int min(int *aPtr, int n)
{

	int i;
	int min = 10;
	int index = 0;

	for(i=0; i<n; i++)
	{
		if(*aPtr < min)
		{
			min = *aPtr;
			index = i;
		}

		aPtr++;
	}
	return index;
}

int count_duplicate(int *aPtr, int n)
{
	int i;
	int j;
	int index = 0;
	int count = 0;

	for(j=0; j<10;j++)
	{
		for(i=0; i<n; i++)
		{
			if(*aPtr == j)
			{
			++count;
			}

			aPtr++;
		}
	

		if(count > 1)
			++index;
	
	}


	return index;
}


