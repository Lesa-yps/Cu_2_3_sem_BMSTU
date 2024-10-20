//the program calculates the area of a triangle given
// two sides and the angle between them


//header files connection
#include <stdio.h>
#include <math.h>

//macro declarations
#define OK 0
#define PI 3.1415926535

//main function
int main(void)
{
	//real variables for sides and angle
	long double a, b;
	long double alpha;
	//real variables for area
	long double s;
	//enter sides and angle
	printf("Input a, b, alpha: ");
	scanf("%Lf%Lf%Lf", &a, &b, &alpha);
	
	//convert angle to radians
	alpha *= PI / 180.0;
	//area calculation
	s = a * b * sin(alpha) / 2.0;

	//output area
	printf("%Lf", s);
	return OK;
}
