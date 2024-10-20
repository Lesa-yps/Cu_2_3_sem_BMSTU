//including header files
#include <stdio.h>
#include <stddef.h>
#include <math.h>

//creating macros
#define MAX_N 10
#define OK 0
#define ERR_LEN 1
#define ERR_ELEM 2
#define NO -1

//the function reads the number of array elements and the array elements themselves
int read(int a[], size_t *n)
{
	printf("Input size of list: ");
	if (scanf("%lu", n) != 1 || *n > MAX_N || *n < 1)
		return ERR_LEN;
	printf("Input elements of list (int):\n");
	for (size_t i = 0; i < *n; i++)
		if (scanf("%d", &a[i]) != 1)
			return ERR_ELEM;
	return OK;
}

//function declaration
double sr_geom(int a[], size_t n);

//main function
int main(void)
{
	int a[MAX_N];
	size_t n = 0;
	double geom;
	int ind = read(a, &n);
	if (ind != OK)
	{
		if (ind == ERR_LEN)
			printf("Error with scanf size of list.\n");
		else
			printf("Error with scanf elements of list.\n");
		return ind;
	}
	geom = sr_geom(a, n);
	if (geom < 0)
	{
		printf("No negativ elements in list.\n");
		return NO;
	}
	printf("Result: %f\n", geom);
	return OK;
}

//the function calculates the geometric mean of the elements in the array
double sr_geom(int a[], size_t n)
{
	double res = 1.0;
	size_t count = 0;
	for (size_t i = 0; i < n; i++)
		if (a[i] > 0)
		{
			res *= a[i];
			count++;
		}
	if (count == 0)
		return NO;
	res = pow(res, 1.0 / count);
	return res;
}
