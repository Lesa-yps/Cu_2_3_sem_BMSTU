#include "read_mat_all.h"

// читает целое число из файла в диапазоне
int read_int(FILE *file, int *num, int mini);
// чтение матрицы и выделение ей памяти
int read_mat(FILE *file, struct matrix *mat1);

// вызывает функции чтения размерностей, выделения памяти под матрицу и чтения элементов матрицы с проверками
int read_mat_all(FILE *file, struct matrix *mat1)
{
    int rc = OK;
    int n1, m1;
    if ((rc = read_int(file, &n1, 1)) == OK)
        if ((rc = read_int(file, &m1, 1)) == OK)
            if ((rc = create_mat(mat1, n1, m1)) == OK)
            {
                mat1->n = n1;
                mat1->m = m1;
                if ((rc = read_mat(file, mat1)) == ERROR)
                    free_mat(mat1);
            }
    return rc;
}

// читает целое число из файла в диапазоне
int read_int(FILE *file, int *num, int mini)
{
    int rc = OK;
    if (fscanf(file, "%d", num) != 1 || *num < mini || *num == EOF)
        rc = ERROR;
    return rc;
}

// чтение матрицы и выделение ей памяти
int read_mat(FILE *file, struct matrix *mat1)
{
    int rc = OK;
    // прочитали элементы матрицы по строкам и проверили ввод
    for (int i = 0; (i < mat1->n) && (rc == OK); i++)
        for (int j = 0; (j < mat1->m) && (rc == OK); j++)
            if (fscanf(file, "%d", &(mat1->arr[i][j])) != 1)
                rc = ERROR;
    return rc;
}
