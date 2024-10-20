#include "print.h"

//the function outputs an array
void print(int k[], size_t n)
{
    printf("Result: ");
    for (size_t i = 0; i < n; i++)
        printf(" %d", k[i]);
    printf("\n");
}
