#include "bek.h"

//the function writes numbers to the go bull matrix from the lower right corner
void bek(int a[][N_MAX], size_t m, size_t n)
{
    int way = -1;
    int k = 1;
    for (long long int j = (n - 1); j >= 0; j--)
    {
        if (way > 0)
            for (size_t i = 0; i < m; i++)
                a[i][j] = k++;
        else
            for (long long int i = (m - 1); i >= 0; i --)
                a[i][j] = k++;
        way = -way;
    }
}
