//the program calculates the quotient and remainder when dividing
// the entered positive numbers, not using integer division operations.


//header file connection
#include <stdio.h>

//macro declarations
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

//integer divide function
long int del(long int a, long int d)
{
	long int q = 0;
	
	while (a >= d)
	{
		q += 1;
		a -= d;
	}

	return q;
}

//main function
int main(void)
{
	//integer variables for the input numbers, over
	// which the division will be performed
	long int a, d;
	//integer variables for quotient and remainder
	long int q, r;

	//entering the numbers to be divided and checking them
	printf("Input a, d: ");

	if (scanf("%ld%ld", &a, &d) != 2)
	{
		printf("Error with scanf\n");
		return ERR_IO;
	}
	else if (a <= 0 || d <= 0)
	{
		printf("Error: input digit is not in interval\n");
		return ERR_RANGE;
	}
	else
	{
		//calling a function del and calculating the quotient and remainder
		q = del(a, d);
		r = a - q * d;

		//quotient and remainder output
		printf("%ld %ld", q, r);
		return OK;
	}
}
	
