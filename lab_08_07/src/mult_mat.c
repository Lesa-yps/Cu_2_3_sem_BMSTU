#include "mult_mat.h"

// внутренние функции
int multy_self_mat(struct matrix *mat, int x);
void one_mat(struct matrix *mat);
void multy_mats(struct matrix *mat_res, struct matrix *mat1, struct matrix *mat2);
int multy_str_col(struct matrix *mat_str, int ind_str, struct matrix *mat_col, int ind_col);

// перемножает матрицы нужное количество раз на себя и друг с другом
int mult_mat(struct matrix *res, struct matrix *mat1, struct matrix *mat2, int p, int y)
{
    int rc = OK;
    if ((rc = multy_self_mat(mat1, p)) == OK)
        if ((rc = multy_self_mat(mat2, y)) == OK)
        {
            res->n = mat1->n;
            res->m = mat2->m;
            multy_mats(res, mat1, mat2);
        }
    return rc;
}

// создается копия матрицы
int copy_mat(struct matrix *mat_copy, struct matrix *mat)
{
    int rc = OK;
    rc = create_mat(mat_copy, mat->n, mat->m);
    mat_copy->m = mat->m;
    mat_copy->n = mat->n;
    if (rc == OK)
        for (int i = 0; i < mat_copy->n; i++)
            for (int j = 0; j < mat_copy->m; j++)
                mat_copy->arr[i][j] = mat->arr[i][j];
    return rc;
}

// перемножает матрицу на себя нужное количество (если х = 0, то матрица становится единичной)
int multy_self_mat(struct matrix *mat, int x)
{
    int rc = OK;
    struct matrix mat1, mat2;
    if (x == 0)
        one_mat(mat);
    if (x > 1)
        if ((rc = copy_mat(&mat2, mat)) == OK)
        {
            for (int i = 1; i < x && (rc == OK); i++)
                if ((rc = copy_mat(&mat1, mat)) == OK)
                {
                    multy_mats(mat, &mat1, &mat2);
                    free_mat(&mat1);
                }
            free_mat(&mat2);
        }
    return rc;
}

// заполнение единичной матрицы
void one_mat(struct matrix *mat)
{
    for (int i = 0; i < mat->n; i++)
        for (int j = 0; j < mat->m; j++)
            mat->arr[i][j] = (i == j);
}

// перемножение двух матриц друг на друга
void multy_mats(struct matrix *mat_res, struct matrix *mat1, struct matrix *mat2)
{
    for (int i = 0; i < mat1->n; i++)
        for (int j = 0; j < mat2->m; j++)
        {
            mat_res->arr[i][j] = multy_str_col(mat1, i, mat2, j);
        }
}

// функция находит произведение строки на столбец матрицы
int multy_str_col(struct matrix *mat_str, int ind_str, struct matrix *mat_col, int ind_col)
{
    int res = 0;
    for (int i = 0; i < mat_str->m; i++)
        res += (mat_str->arr[ind_str][i] * mat_col->arr[i][ind_col]);
    return res;
}
