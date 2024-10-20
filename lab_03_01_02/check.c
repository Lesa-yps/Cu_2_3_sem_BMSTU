#include "check.h"

//the function checks whether the elements in the array alternate by sign
int check(int a[][N_MAX], size_t m, size_t i)
{
    if (m == 1)
        return 0;
    for (size_t j = 1; j < m; j++)
    {
        if (a[j][i] * a[j - 1][i] >= 0)
            return 0;
    }
    return 1;
}
