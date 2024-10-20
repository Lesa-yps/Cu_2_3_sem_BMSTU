//the program in the entered number swaps even and odd bits in pairs


//header files connection
#include <stdio.h>
#include <stdint.h>

//macro declarations
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

#define MAX_LEN 0xFFFFFFFF

//function swaps pairs of bits in a number
uint32_t change(uint32_t x_l)
{
	uint32_t x = 0;
	long int k = 0;
    
	while (x_l > 0)
	{
		if (x_l & 1)
			x |= 1 << (k + 1);
		if (x_l & 2)
			x |= 1 << k;
		k += 2;
		x_l = x_l >> 2;
	}
	return x;
}

//main function
int main(void)
{
	//unsigned integer variable for input number
	uint32_t x;
	//integer variable to check the input number
	int64_t x_l;
	//variable for the length of the input number in binary form
	
	//entering a number and checking it
	printf("Input x: ");
	
	if (scanf("%li", &x_l) != 1)
	{
		printf("Error: problem with scanf.\n");
		return ERR_IO;
	}
	
	if (x_l > (int64_t) MAX_LEN)
	{
		printf("Error: digit is wrong size.\n");
		return ERR_RANGE;
	}
	
	//calling a function change
	x = change(x_l);
	
	//output in binary form
	printf("Result: ");
	for (int j = 31; j >= 0; j--)
		printf("%d", (x >> j) & 1);
	printf("\n");

	return OK;
}
