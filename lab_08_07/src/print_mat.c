#include "print_mat.h"

// вывод матрицы по строкам
void print_mat(FILE *file, struct matrix *mat)
{
    for (int i = 0; i < mat->n; i++)
    {
        for (int j = 0; j < mat->m; j++)
            fprintf(file, "%d ", mat->arr[i][j]);
        fprintf(file, "\n");
    }
}
