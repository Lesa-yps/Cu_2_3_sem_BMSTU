#include "all_for_2D.h"

void free_2Dmat(struct matrix_2D *mat1)
{
    free(mat1->arr[0]);
    free(mat1->arr);
}

int create_2Dmat(struct matrix_2D *mat1, int n_max, int m_max)
{
    int rc = OK;
    int *data;
    mat1->n = 0;
    mat1->m = 0;
    mat1->arr = calloc(n_max, sizeof(int*));
    if (mat1->arr == NULL)
        rc = ERROR;
    else
    {
        data = calloc(n_max * m_max, sizeof(int));
        if (data == NULL)
        {
            rc = ERROR;
            free(mat1->arr);
        }
        else
            for (int i = 0; i < n_max; i++)
                mat1->arr[i] = data + i * m_max;
    }

    return rc;
}

int made_2Dmat(struct matrix_2D *mat_2D, struct matrix mat)
{
    int rc = OK;
    int sum;
    if ((rc = create_2Dmat(mat_2D, mat.n, mat.m)) == OK)
    {
        for (int i = 0; i < mat.n; i++)
            for (int j = 0; j < mat.m; j++)
            {
                sum = 0;
                for (int w = 0; w < mat.k; w++)
                    sum += mat.arr[i][j][w];
                mat_2D->arr[i][j] = sum;
            }
        mat_2D->n = mat.n;
        mat_2D->m = mat.m;
    }
    return rc;
}

// вывод матрицы по строкам
void print_2Dmat(FILE *file, struct matrix_2D mat)
{
    fprintf(file, "\n");
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
            fprintf(file, "%d ", mat.arr[i][j]);
        fprintf(file, "\n");
    }
}
