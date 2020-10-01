#include<stdio.h>

void display_menu(void);
int check_option(int);

int main(void)
{

	int x;
	int y;

	display_menu();

	printf("\n\nPlease make a selection:");
	scanf("%d",&x);

	y= check_option(x);

	while (y != 1) {
		printf("Invalid choice enter the choice again:");
		scanf("%d", &x);
	
		y= check_option(x);
	}

	if (x == 1) {
		printf("\nYou have selected checking account type.");
		}

	else if (x==2) {
		printf("\nYou have selected saving account type.");
		}

	else if (x==3) {
		printf("\nYou have selected fixed account type.");
		}

return 0;
}

void display_menu() {

	printf("\nBank account type\n(1)Checking\n(2)Saving\n(3)Fixed Deposit");

}

int check_option(int z) {

	if (z > 0 && z < 4)
		return 1;

	else 
		return 0;
	}
