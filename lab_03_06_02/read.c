#include "read.h"

//the function reads the dimensions of the matrix
int read(size_t *m, size_t *n)
{
    printf("Input m: ");
    if (scanf("%zu", m) != 1 || *m > M_MAX || *m <= 0)
        return ERR_M;
    printf("Input n: ");
    if (scanf("%zu", n) != 1 || *n > N_MAX || *n <= 0)
        return ERR_N;
    return OK;
}
