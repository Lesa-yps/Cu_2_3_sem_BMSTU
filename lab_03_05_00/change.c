#include "change.h"

//the function checks whether the number is prime
int checker(int x)
{
    if (x <= 1)
        return NO;
    for (int q = 2; q < (x / 2 + 1); q++)
        if (x % q == 0)
            return NO;
    return OK;
}

//the function expands the array
void reverse(int k[], size_t n)
{
    int x;
    for (size_t i = 0; i < (n / 2); i++)
    {
        x = k[i];
        k[i] = k[n - i - 1];
        k[n - i - 1] = x;
    }
}

//the function writes the prime numbers in the matrix in reverse order using an array
int change(int a[][N_MAX], size_t m, size_t n)
{
    int k[N_MAX * M_MAX];
    size_t lenk = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            if (checker(a[i][j]) == OK)
                k[lenk++] = a[i][j];
    }
    if (lenk == 0)
        return NO;
    reverse(k, lenk);
    lenk = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            if (checker(a[i][j]) == OK)
                a[i][j] = k[lenk++];
    }
    return OK;
}
