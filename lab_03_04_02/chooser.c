#include "chooser.h"

//the function return abs of x
int abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}

//the function finds the maximum element ending in 5 under the side diagonal in a square matrix
int chooser(int a[][M_MAX], size_t m)
{
    int max5 = 10;
    for (size_t i = 1; i < m; i++)
        for (size_t j = (m - i); j < m; j++)
            if (abs(a[i][j]) % 10 == 5 && (a[i][j] > max5 || max5 == 10))
                max5 = a[i][j];
    return max5;
}
