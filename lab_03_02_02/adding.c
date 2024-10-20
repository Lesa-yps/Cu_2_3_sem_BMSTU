#include "adding.h"

//the function checks the sum of digits in a number for odd
int summa(int x)
{
    int sum = 0;
    if (x < 0)
        x = - x;
    while (x > 0)
    {
        sum += (x % 10);
        x = x / 10;
    }
    return sum % 2;
}

//the function checks if there are at least 2 elements in the array with an odd sum of digits
int checker(int a[], size_t n)
{
    size_t count = 0;
    for (size_t j = 0; j < n; j++)
    {
        count += summa(a[j]);
        if (count == 2)
            return OK;
    }
    return NO;
}

//the function adds rows of -1 in matrix after rows that have at least 2 elements with an odd sum of digits
void adding(int a[][N_MAX], size_t *m, size_t n)
{
    size_t k = 0;
    for (size_t i = 0; i < *m; i++)
        if (checker(a[i], n) == OK)
            k += 1;
    *m += k;
    size_t i = *m - 1;
    while (i > 0)
    {
        for (size_t j = 0; j < n; j++)
            a[i][j] = a[i - k][j];
        if (checker(a[i], n) == OK)
        {
            for (size_t j = 0; j < n; j++)
                a[i - 1][j] = -1;
            i--;
            k--;
        }
        if (i == 0)
            break;
        i--;
    }
}
