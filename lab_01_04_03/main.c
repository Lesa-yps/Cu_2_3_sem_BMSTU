//the program multiplies the numbers in the entered three-digit number


//header file connection
#include <stdio.h>

//macro declaration OK
#define OK 0

//main function
int main(void)
{
	//integer variable for the entered three-digit number
	int x;
	//integer variable of the result of
	// multiplying the digits in the entered number
	int mult;
	//enter a three-digit integer
	printf("Input x: ");
	scanf("%d", &x);

	//calculation of the product of digits in the entered three-digit number
	mult = (x / 100) * (x % 100 / 10) * (x % 10);

	if (mult < 0)
		mult *= -1;
	
	//displaying the product of digits in a number
	printf("%d", mult);
	return OK;
}
