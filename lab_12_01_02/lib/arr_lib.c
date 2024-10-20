#include "arr_lib.h"

void arr_go(int *arr, int n, int *arr_new, int k)
{
    if (arr_new == NULL)
        return;
    for (int i = 0; i < n; i++)
    {
        int i_new = i - k;
        if (i_new >= n)
            i_new %= n;
        while (i_new < 0)
            i_new = n + i_new;
        //printf("i = %d i_new = %d k = %d\n", i, i_new, k);
        arr_new[i_new] = arr[i];
    }
}

int diff_double(double num1, double num2)
{
    return ((num1 - num2) < EPS && (num1 - num2) > -EPS);
}

int is_square(int num)
{
    int rc = 1;
    if (num < 0)
        rc = 0;
    else
    {
        double sq_num = sqrt(num);
        double round_sq_num = round(sq_num);
        rc = diff_double(round_sq_num, sq_num);
        //printf("rc = %d %d %f %f\n", rc, num, sq_num, round_sq_num);
    }
    return rc;
}

int arr_filtr(int *arr, int n, int *arr_new)
{
    int i_new = 0;
    for (int i = 0; i < n; i++)
        if (is_square(arr[i]))
        {
            arr_new[i_new] = arr[i];
            i_new++;
        }
    return i_new;
}