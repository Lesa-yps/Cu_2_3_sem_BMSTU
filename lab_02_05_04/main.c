//including header files
#include <stdio.h>
#include <stddef.h>
#include <math.h>

//creating macros
#define OK 0
#define ERR_LEN 1
#define ERR_ELEM 2

#define N_MAX 10

//function declarations
int read(int *pa, size_t *n);
size_t kolvo(int *pa, int *pend);

//main function
int main(void)
{
	int a[N_MAX];
	size_t n;
	int x = read(a, &n);
	if (x != OK)
	{
		if (x == ERR_LEN)
			printf("Error with scanf size of list.\n");
		else
			printf("Error with scanf elements of list.\n");
		return x;
	}
	size_t count = kolvo(a, a + n);
	printf("Number of Unique Items: %lu\n", count);
	return OK;
}

//the function returns the number of unique elements
size_t kolvo(int *pa, int *pend)
{
	size_t count = 0;
	for (int *pi = pa; pi < pend; pi++)
	{
		size_t flag = 1;
		for (int *pj = pi - 1; pj >= pa; pj--)
			if (*pj == *pi)
				flag = 0;
		count += flag;
	}
	return count;
}

//the function reads the number of array elements and the array elements themselves
int read(int *pa, size_t *n)
{
	printf("Input size of list: ");
	if ((scanf("%lu", n) != 1) || *n > N_MAX || *n < 1)
		return ERR_LEN;
	printf("Input elements of list (int):\n");
	for (size_t i = 0; i < *n; i++)
		if (scanf("%d", pa + i) != 1)
		return ERR_ELEM;
	return OK;
}
