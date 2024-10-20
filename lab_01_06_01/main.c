//the program calculates the area of a triangle from the entered coordinates of the vertices


//header files connection
#include <stdio.h>
#include <math.h>

//macro declarations
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
//constant
#define EPS 0.00001

//function on the coordinates of two vertices calculates the length of the side
double side(double x1, double y1, double x2, double y2)
{
	double a;
	a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return a;
}

//the function will return the modulus of the difference of two numbers
double absol(double x, double y) 
{
	if (x >= y)
	{
		return x - y;
	}
	else
	{
		return y - x;
	}
}

//main function
int main(void)
{
	//real variables for vertex coordinates
	double xa, ya, xb, yb, xc, yc;
	//real variables for side lengths
	double a, b, c;
	//real variables for semi=perimeter and area of a triangle
	double s;
	double p;
	
	//input of vertex coordinates with checks
	printf("Input xa, ya, xb, yb, xc, yc: ");
	if (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
	{
		printf("Error with scanf");
		return ERR_IO;
	}
	else if ((absol(xa, xb) < EPS) && (absol(xb, xc) < EPS) && (absol(ya, yb) < EPS) && (absol(yb, yc) < EPS))
	{
		printf("Error: it is point");
		return ERR_RANGE;
	}
	else if (absol((xa - xb) / (xc - xb), (ya - yb) / (yc - yb)) < EPS)
	{
		printf("Error: it is line");
		return ERR_RANGE;
	}
	else
	{
		//call a function side to calculate the lengths of the sides
		a = side(xa, ya, xb, yb);
		b = side(xb, yb, xc, yc);
		c = side(xa, ya, xc, yc);
		//semi-perimeter calculation
		p = (a + b + c) / 2;
		//calculating the area of a triangle
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		
		//derivation of the area of a triangle
		printf("%lf", s);
		return OK;
	}
}
