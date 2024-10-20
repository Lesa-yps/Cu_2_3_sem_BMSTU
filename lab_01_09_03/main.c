//Based on the entered non-empty sequence up to the first negative element,
// the program calculates the value of the formula:
//g(x) = exp(1/((x1 + 1) * (x2 + 2) * ... * (xn + n)))


//header files connection
#include <stdio.h>
#include <math.h>

//macro declarations
#define OK 0
#define ERR_IO 1
#define ERR_ZERO 2

//function calculates g = exp(1 / x)
long double rever(long double x)
{
	long double g = exp(1 / x);
	return g;
}

//main function
int main(void)
{
	//real variables for the elements of the input sequence
	// and their ordinal number (from 1)
	long double x; 
	long int k = 1;
	//real variables for the product in the denominator and the result of the formula
	long double mult = 1, g;
	
	//entering the elements of a sequence with verification and calculating the product 
	//in the denominator of the formula up to the first negative number
	printf("Input x: ");
	
	if (scanf("%Lf", &x) != 1)
	{
		printf("Error with scanf.\n");
		return ERR_IO;
	}
	
	if (x < 0)
	{
		printf("Error: first element is negativ.\n");
		return ERR_ZERO;
	}

	while (x >= 0)
	{
		mult *= (x + k);
		k += 1;
		printf("Input next x: ");
		if (scanf("%Lf", &x) != 1)
		{
			printf("Error with scanf.\n");
			return ERR_IO;
		}
	}
	
	//function rever call for calculation g = exp(1 / mult)
	g = rever(mult);
	
	//displaying the result of formula calculation
	printf("%Lf", g);
	return OK;
}
