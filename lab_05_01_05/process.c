#include "process.h"

int process(FILE *file, long long int *count)
{
    int a;
    int a_old = INT_MAX;
    int a_h = a_old;
    int k = 1;
    *count = 1;

    printf("Input numbers:\n");
    if (fscanf(file, "%d", &a_old) == 0)
        return EMPTY;
    if (feof(file))
    {
        if (a_h == a_old)
            return EMPTY;
        else
        {
            *count = 1;
            return OK;
        }
    }

    if (fscanf(file, "%d", &a) == 0)
    {
        *count = 1;
        return OK;
    }
    if (a_old == a)
        k++;
    a_old = a;
    while (fscanf(file, "%d", &a) != 0 && ! feof(file))
    {
        if (a_old == a)
        {
            k++;
            if (k > *count)
                *count = k;
        }
        else
            k = 1;
        a_old = a;
    }
    return OK;
}
