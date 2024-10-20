//the program calculates the movement according
// to the entered initial speed, acceleration and time


//header file connection
#include <stdio.h>

//macro declaration OK
#define OK 0

//main function
int main(void)
{
	//real variables for initial speed, acceleration and time
	double v0, a, t;
	//real variable to move
	double s;
	//input of initial speed, acceleration and time
	printf("Input v0, a, t: ");
	scanf("%lf%lf%lf", &v0, &a, &t);

	//move calculation
	s = v0 * t + a * t * t / 2;

	//move output
	printf("%lf", s);
	return OK;
}
