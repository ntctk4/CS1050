#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int array[100]={0};

int check_size(int);
void initialize_array(int);
void print_array(int);
int find_max(int);

int main(void)
{
	int x;
	int y;
	int index;
	
	srand(time(NULL));

	printf("Enter the size of the input:");
	scanf("%d", &x);
	
	y = check_size(x);

	while(y != 1){
		printf("Invalid input enter the size of the input again:");
		scanf("%d", &x);


		y = check_size(x);

}
	initialize_array(x);

	print_array(x);

	index=find_max(x);

	printf("\n\nLargest number present in the array is %d at the index %d\n", array[index], index);
}

int check_size(int x) {

	if (x> 0 && x<101)
		return 1;

	else 
		return 0;
}

void initialize_array(int x){

	int i;
	int t;

	for(i=0; i<x; i++){ 
		t=rand()%10;
		array[i]=t;
	}

}

void print_array(int x) {

	int i;

	printf("\nInput array\n");

	for(i=0; i<x; i++)
		printf("%d ", array[i]);  
}

int find_max(int x){

	int i;
	int index;
	int m=0;

	for(i=0; i<x; i++){
		if (array[i] > m){
		m= array[i];
		index=i;
		}
	}
	return index;
}	
