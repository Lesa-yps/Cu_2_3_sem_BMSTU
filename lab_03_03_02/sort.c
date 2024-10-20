#include "sort.h"

//the function counts the product of the numbers in the array
int proi(int a[], size_t n)
{
    int doub = 1;
    for (size_t i = 0; i < n; i++)
        doub *= a[i];
    return doub;
}

//the function swaps elements in arrays
void change(int a[], int b[], size_t n)
{
    int x;
    for (size_t i = 0; i < n; i++)
    {
        x = a[i];
        a[i] = b[i];
        b[i] = x;
    }
}

//the function sorts the rows in the matrix in ascending order of the product of the elements
void sort(int a[][N_MAX], size_t m, size_t n)
{
    int flag;
    for (size_t i = 0; i < m; i++)
    {
        flag = 0;
        for (size_t j = 1; j < m; j++)
            if (proi(a[j - 1], n) > proi(a[j], n))
            {
                change(a[j - 1], a[j], n);
                flag = 1;
            }
        if (flag == 0)
            break;
    }
}
