/*
 *Nathaniel Callahan
 *ntctk4
 *Lab code: 1804289383
 *Lab 6
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int check_size(int);
void initialize_2Darray(int [][MAX], int);
void print_2Darray(int[][MAX], int);
float column_average(int[][MAX], int, int);
void average_scores(int [][MAX], int);
char compute_grade(int [][MAX], int size, int i);

int main(void)
{

	int input;
	int y;
	int student;
	char grade;

	int array[MAX][MAX];
	
	srand(time(NULL));

	printf("Enter the size of the array:");
	scanf("%d", &input);

	y = check_size(input);

	while(y != 1)
	{
		printf("Invalid input enter the size of the array again:");
		scanf("%d", &input);

		y = check_size(input);
	}

	initialize_2Darray(array, input);

	print_2Darray(array, input);

	average_scores(array, input);

	printf("\n\nEnter student number (1-%d):", input);
	scanf("%d", &student);

	grade = compute_grade(array, input, student);

	printf("\nOverall grade for %dth student is %c", student, grade);


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
			t = rand()%100;
			array[i][j]=t;
		}
	}
}

void print_2Darray(int array[][MAX], int input)
{
	int i;
	int j;

	printf("\nInput 2D array\n\n");

	for(i=0; i<input; i++)
	{
		for(j=0; j<input; j++)
		{
			printf("%d ", array[i][j]);
		}

		printf("\n");
	}
}

void average_scores(int array[][MAX], int input)
{

	int i;
	float sum;

	for(i=0; i<input; i++)
	{

	sum = column_average(array, input, i);

		printf("\nCourse %d average score is %.2f", i+1, sum);

	}
}

float column_average(int array[][MAX], int input, int m)
{

	float sum;
	int total = 0;
	int i;

		for(i=0; i<input; i++)
		{
			total += array[i][m];
		}

	sum = (float)total/input;

	return sum;
}

char compute_grade(int array[][MAX], int input, int student)
{

	int j;
	int total = 0;
	int sum;
	char x;

		for(j=0; j<input; j++)
		{
			total += array[student-1][j];
		}

		sum = total/input;

		if(sum >= 90)
			x = 'A';

		if(sum < 90 && sum >= 80)
		       x = 'B';

		if(sum < 80 && sum >= 70)
			x = 'C';

		if (sum < 70 && sum >= 60)
			x = 'D';

		if (sum < 60)
			x = 'F';
	return x;
}	
