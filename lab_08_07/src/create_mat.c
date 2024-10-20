#include "create_mat.h"

// выделяет память под матрицу
int create_mat(struct matrix *mat1, int n_max, int m_max)
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
