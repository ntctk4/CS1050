/*
*ntctk4
*Lab 2
*Lab code: Lab2
*
*
**/

#include<stdio.h>

int main(void)
{

	float s;//total distance traveled in miles
	int t;// time
	int u;// initial speed
	int a;// acceleration
	float n;// total distance traveled in meters

	printf("Enter the initial velocity: ");//enter velocity in miles per hour
	scanf("%d", &u );

	if (u <= 0) {
		printf("Invalid number enter the number again:");//fix velocity number
		scanf("%d", &u);
	}

	printf("Enter the acceleration:");// enter acceleration in miles per hour squared
	scanf("%d",&a);

	if (a < 0) {
		printf("Invalid number enter the number again: ");//fix acceleration number 
		scanf("%d", &a);
	}

	printf("Enter the time:");// enter time in seconds
	scanf("%d", &t);

	if (t < 0) {
		printf("Invalid number enter the number again: ");//fix time number
		scanf("%d", &t);
	}
	
	s = (u *((float)t/3600)) + ((float)(a *((float)t/3600*(float)t/3600))) / 2;//equation to find distance traveled in miles

	n = s * 1600;//conversion equation to get from miles traveled to meters traveled 

	printf("total distance traveled by the vehicle in %d second is %.3f miles or %.3f meters", t, s, n);//tells the user the time, miles, and meters
}
