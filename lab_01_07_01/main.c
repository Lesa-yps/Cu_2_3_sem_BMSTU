//the program calculates the Taylor series and the exact value of the sine,
// the absolute and relative error with the entered x and accuracy (0; 1]


//header files connection
#include <stdio.h>
#include <math.h>

//macro declarations
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

//the function calculates the Taylor series for x with an accuracy of e
double series(double x, double e, double f)
{
	int k = 3, minus = -1;
	long int fac = 1;
	double s = x;

	while ((! ((f - s) <= e && (-1) * e <= (f - s))) || (! ((s - f) <= e && (-1) * e <= (s - f))))
	{
		fac *= k * (k - 1);
		s += pow(x, k) / fac * minus;
		k += 2;
		minus = - minus;
	}
	
	return s;
}

//main function
int main(void)
{
	//real variable for input x and precision
	double x, e;
	//real variables for calculated with accuracy e approximate and exact value of the sine
	double s, f;
	//real variables for absolute and relative errors
	double a, q;
	
	//input x and precision with checks
	printf("Input x, e: ");
	if (scanf("%lf%lf", &x, &e) != 2)
	{
		printf("IO error\n");
		return ERR_IO;
	}
	if (e > 1 || e <= 0)
	{
		printf("Error: e does not fall within the gap\n");
		return ERR_RANGE;
	}
	
	//calculating the exact value of the sine for x
	f = sin(x);
	//call a function series to calculate the Taylor series for x with precision E
	s = series(x, e, f);
	//calculation of the modulus of absolute error
	a = f - s;
	if (a < 0)
		a *= -1;
	//calculation of the modulus of relative error
	q = a / f;
	if (q < 0)
		q *= -1;

	//derivation of the Taylor series and the exact values of the sine, absolute and relative errors
	printf("%lf %lf %lf %lf", s, f, a, q);
	return OK;
}

