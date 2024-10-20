#include "read.h"

//the function reads the dimensions and elements of the matrix
int read(int a[][M_MAX], size_t *m)
{
    size_t n;
    printf("Input m: ");
    if (scanf("%zu", m) != 1 || *m > M_MAX || *m <= 0)
        return ERR_SIZE;
    printf("Input n: ");
    if (scanf("%zu", &n) != 1 || n > M_MAX || n <= 0 || n != *m)
        return ERR_SIZE;
    printf("Input elements: \n");
    for (size_t i = 0; i < *m; i++)
    {
        printf("new string: \n");
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ERR_ELEM;
    }
    return OK;
}
