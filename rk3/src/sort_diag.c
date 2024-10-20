#include "sort_diag.h"

void swap(int *a, int *b);

void sort_diag(struct matrix_2D *mat_2D)
{
    int flag = 1;
    int min_nm = mat_2D->n;
    if (mat_2D->n > mat_2D->m)
        min_nm = mat_2D->m;
    for (int i = 0; i < min_nm && flag; i++)
    {
        flag = 0;
        for (int j = 1; j < min_nm - i; j++)
            if (mat_2D->arr[j - 1][j - 1] > mat_2D->arr[j][j])
            {
                flag = 1;
                swap(&(mat_2D->arr[j - 1][j - 1]), &(mat_2D->arr[j][j]));
            }
    }
}

void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}
