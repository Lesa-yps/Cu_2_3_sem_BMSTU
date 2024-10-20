#include "print.h"

//the function outputs the elements of the matrix
void print(int a[][N_MAX], size_t m, size_t n)
{
    printf("Result: \n");
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            printf("%7d ", a[i][j]);
        printf("\n");
    }
}
