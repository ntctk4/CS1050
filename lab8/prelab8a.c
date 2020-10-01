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

int main(int argc, char** argv)
{

	if(argc != 2)
	{
		printf("\n insufficient arguments \n");
		return 0;
	}
	int size=loadArray(argv[1]);

	if(size==0)
	{
		printf("\n Unable to open the input file\n");
		return 0;
	}

	printf("\nStudent record\n\n");
	printArray(size);


	return 0;
}

int loadArray(char* filename)
{
	int i=0;
	FILE* file=fopen(filename,"r");
	
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

	printf("ID	Grade");	
	
	for(i=0; i<size; i++)
	{
		printf("\n%d	%d", student[i].id, student[i].grade);
	}
}

