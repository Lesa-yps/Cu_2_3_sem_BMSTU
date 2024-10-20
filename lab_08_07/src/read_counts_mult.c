#include "read_counts_mult.h"

// читаем два целых неотрицательных числа (с проверками)
int read_counts_mult(FILE* file, int *p, int *y)
{
    int rc = OK;
    if (fscanf(file, "%d", p) != 1 || (*p < 0) || (*p == EOF))
        rc = ERROR;
    else if (fscanf(file, "%d", y) != 1 || (*y < 0) || (*y == EOF))
        rc = ERROR;
    return rc;
}
