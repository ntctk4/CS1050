/*
 *Nathaniel Callahan
 *ntctk4
 *Labcode: July 21
 *lab 8
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
int searchArray(int size, int id, int ngrade);
void writeContent(char* filename, int size);
int loadArray(char* filename);
void printArray(int size);

int main(int argc, char** argv)
{
	int x;
	int y;
	int z;

	if(argc != 3)
	{
		printf("\n Insufficient Arguments \n");
		return 0;
	}
	
	int size = loadArray(argv[1]);

	if(size==0)
	{
		printf("\n Unable to open the input file\n");
		return 0;
	}

	printf("\nStudent record\n");
	printArray(size);

	printf("\n\nEnter the ID of the student to search:");
	scanf("%d", &x);

	printf("\n\nEnter a grade for the student:");
	scanf("%d", &y);

	z = searchArray(size, x, y);

	if(z == 0)
	{
		printf("\n\nStudent with id %d is not present in the class\n", x);
	}

	if(z == 1)
	{

		printf("\nUpdated student record\n");
		printArray(size);
	}
	
	writeContent(argv[2], size);

	return 0;
}

int loadArray(char* filename)
{
	int i=0;
	FILE* file=fopen(filename, "r");

	if(file==NULL)
	{
		return 0;
	}
	
	int size;

	fscanf(file, "%d", &size);

	for(i=0; i<size; i++)
	{

		fscanf(file,"%d %d", &student[i].id, &student[i].grade);
	}

	fclose(file);
	return size;
}

void printArray(int size)
{
	int i;

	printf("ID Grade");

	for(i=0; i<size; i++)
	{
		printf("\n%d %d", student[i].id, student[i].grade);
	}
	printf("\n");
}

int searchArray(int size, int id, int ngrade)
{
	int i;
	
	for(i=0; i<size; i++)
	{
		if(id == student[i].id)
		{
			
			student[i].grade = ngrade;
			return 1;
			
		}
 	}

	return 0;
}


void writeContent(char* filename, int size)
{
	int i;
	FILE* file=fopen(filename, "w");

	if(file==NULL)
	{
		return;
	}

	for(i=0; i<size; i++)
	{
		fprintf(file,"%4d %-3d \n", student[i].id, student[i].grade);
	}

	fclose(file);


}

