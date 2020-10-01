/*
 *Nathaniel Callahan
 *ntctk4
 *HW4
 *
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct
{
	int id;
	int grade;
} data;

data student[MAX];

int loadArray(char* filename);
void printArray(int size);
int updateArray(char* filename, int n);
int findHighestgrade(int size);
int findLowestgrade(int size);
float averageClassgrade(int n);
int writeContent(char* filename, int size, int i, int j, float ave);

int main(int argc, char** argv)
{

	int q;
	int size;
	int i;
	int j;
	float avg;

	if(argc != 4)
	{
		printf("\ninsufficient arguments \n");
		return 0;
	}


	size = loadArray(argv[1]);

	if(size == 0)
	{
		printf("\n Unable to open the input file \n");
		return 0;
	}

	printf("\nStudent record\n");

	printArray(size);

	printf("\nStudent Statistics\n");

	i = findHighestgrade(size);

	printf("The student with the highest grade has the id %d with the grade %d\n",student[i].id, student[i].grade);


	j = findLowestgrade(size);

	printf("The student with the lowest grade has the id %d with the grade %d \n", student[j].id, student[j].grade);

	avg = averageClassgrade(size);

	printf("The average grade for the class %.2f \n", avg);
	

	size = updateArray(argv[2], size);

	if(size == 0)
	{
		printf("\n Unable to open the update file\n");
	}

	printf("\nUpdated student record\n");

	printArray(size);

	i = findHighestgrade(size);
	j = findLowestgrade(size);
	avg = averageClassgrade(size);

	printf("\nStudent Statistics after the update operation\n");
	
	printf("The student with the highest grade has the id %d with the grade %d\n", student[i].id, student[i].grade);

	printf("The student with the lowest grade has the id %d with the grade %d \n", student[j].id, student[j].grade);

	printf("The average grade for the class %.2f \n", avg);

	q = writeContent(argv[3], size, j, i, avg);

	return 0;

}

int loadArray(char* filename)
{
	int i = 0;
	FILE* file=fopen(filename,"r");
	int size;
	
	if(file==NULL)
	{
		return 0;
	}

	fscanf(file,"%d", &size);

	for(i=0; i<size; i++)
	{
		fscanf(file,"\n%d %d", &student[i].id, &student[i].grade);
	}
	
	fclose(file);

	return size;
}

void printArray(int size)
{

	int i;

	printf("ID    Grade");

	for(i=0; i<size; i++)
	{
		printf("\n%d    %d", student[i].id, student[i].grade);
	}
	printf("\n");
}

int updateArray(char* filename, int n)
{
	int i;
	FILE* file=fopen(filename, "r");
	int size;

	int q;

	fscanf(file, "%d", &q);

	size = n+q;

	if(file==NULL)
	{
		return 0;
	}
	

	for(i=n; i<size; i++)
	{
		fscanf(file,"%d	   %d", &student[i].id, &student[i].grade);
	}

	fclose(file);
	return size;

}

int findHighestgrade(int size)
{
	int i;
	int max = 0;
	int index = 0;

	for(i=0; i<size; i++)
	{
		if(student[i].grade > max)
		{
			max = student[i].grade;
			index = i;
		}
	}
	return index;
}

int findLowestgrade(int size)
{
	int i;
	int min = 101;
	int index = 0;

	for(i=0; i<size; i++)
	{
		if(student[i].grade < min)
		{
			min = student[i].grade;
			index = i;
		}
	}
	return index;
}

float averageClassgrade(int size)
{
	int i;
	float sum;
	int total =0;

	for(i=0; i<size; i++)
	{
		total += student[i].grade;
	}

	sum = (float)total/size;

	return sum;
}

int writeContent(char* filename, int size, int low, int high, float avg)
{
	int i;
	FILE* file=fopen(filename, "w");

	if(file==NULL)
	{
		return 0;
	}

	for(i=0; i<size; i++)
	{
		fprintf(file,"%d    %d\n",student[i].id, student[i].grade);
	}

	fprintf(file, "\nStudent with the highest grade has the id %d and the grade %d",student[high].id, student[high].grade);

	fprintf(file, "\nStudent with the lowest grade has the id %d and the grade %d", student[low].id, student[low].grade);

	fprintf(file, "\nAverage Class grade is %.2f", avg);
	

	fclose(file);

	return 1;
}

