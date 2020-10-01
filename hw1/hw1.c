/*
 *Nathaniel Callahan
 *ntctk4
 *HW1
 *
 *
 * */

#include<stdio.h>

int main(void)
{

	int n = 1;
	int x;
	int y;
	int z;
	float total;
	int max;
	int min;

	while(n == 1){

		
		printf("Enter the midterm1 grade:");
		scanf("%d", &x);

		while(x<0 || x>100) {
			printf("Invalid grade enter the grade again: ");
			scanf("%d", &x);
		}	

		printf("\nEnter the midterm2 grade:");
		scanf("%d", &y);

		while(y<0 || y>100) {
			printf("Invalid grade enter the grade again:");
			scanf("%d", &y);
		}

		printf("\nEnter the final grade:");
		scanf("%d", &z);

		while(z<0 || z>100) {
			printf("Invalid grade enter the grade agian:");
			scanf("%d", &z);
		}

	

		if(x>y && x>z)
			printf("\nHighest grade for the student is %d in midterm1\n", x);

		else if(y>x && y>z)
			printf("\nHighest grade for the student is %d in midterm2\n", y);

		else if (z>x && z>y)
			printf("\nHighest grade for the student is %d in the final\n", z);


	

		if(x<y && x<z)
			printf("\nLowest grade for the student is %d in midterm1\n", x);

		else if(y<x && y<z)
			printf("\nLowest grade for the student is %d in midterm2\n", y);

		else if (z<x && z<y)
			printf("\nLowest grade for the student is %d in the final\n", z);


	
		total =	(float)(x+y+z)/3;


	
		if(total >= 90)
			printf("\nStudents total is %.2f and overall grade in the course is A\n", total);

		else if (total < 90 && total >= 80)
			printf("\nStudents total is %.2f and overall grade in the course is B\n", total);

		else if (total < 80 && total >= 70)
			printf("\nStudents total is %.2f and overall grade in the course is C\n", total);

		else if (total < 70 && total >= 60)
			printf("\nStudents total is %.2f and overall grade in the course is D\n", total);

		else if (total < 60)
			printf("\nStudents total is %.2f and overall grade in the course is F\n", total);

	
	
		printf("\nDo you want to continue (enter 1 to continue and 0 to exit):");
		scanf("%d", &n);
	}

	return 0;
}
