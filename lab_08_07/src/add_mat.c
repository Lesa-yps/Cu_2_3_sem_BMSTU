#include "add_mat.h"

// внутренние функции
void add_str(struct matrix *mat1);
void add_col(struct matrix *mat1);
// внутренние функции для функций
int max_str(struct matrix *mat1, int ind_str);
int sr_geom_abs_col(struct matrix *mat1, int ind_col);
// мой реаллок
int my_realloc(struct matrix *mat1, int n_new, int m_new);

// добавляем строки/столбцы до размерности z по определённым правилам (сначала строки потом столбцы)
// (новые столбцы из максимумов по строкам, новые строки из средних геометрических по столбцам)
int add_mat(struct matrix *mat1, int z)
{
    int rc = OK;
    // если матрица не подходит под размер
    if (mat1->n >= z && mat1->m >= z)
        return rc;
    // выделяем память под новый размер и проверяем выделение
    if ((rc = my_realloc(mat1, z, z)) == OK)
    {
        // добавили строки, сколько не хватало
        while (mat1->n < z)
            add_str(mat1);
        // добавили столбцы, сколько не хватало
        while (mat1->m < z)
            add_col(mat1);
    }
    return rc;
}

// функция добавляет строку
void add_str(struct matrix *mat1)
{
    for (int j = 0; j < mat1->m; j++)
        mat1->arr[mat1->n][j] = sr_geom_abs_col(mat1, j);
    (mat1->n)++;
}

// функция добавляет столбец
void add_col(struct matrix *mat1)
{
    for (int i = 0; i < mat1->n; i++)
        mat1->arr[i][mat1->m] = max_str(mat1, i);
    (mat1->m)++;
}

// функция находит максимальный элемент в строке
int max_str(struct matrix *mat1, int ind_str)
{
    int maxi = mat1->arr[ind_str][0];
    for (int i = 1; i < mat1->m; i++)
        if (mat1->arr[ind_str][i] > maxi)
            maxi = mat1->arr[ind_str][i];
    return maxi;
}

// функция находит среднее геометрическое модулей элементов столбца
int sr_geom_abs_col(struct matrix *mat1, int ind_col)
{
    // находим произведение элементов столбца
    int res = 1;
    for (int i = 0; i < mat1->n; i++)
        res *= mat1->arr[i][ind_col];
    // берём модуль произведения
    res = abs(res);
    // вычисляем корень n-ой степени из модуля произведения
    res = (int) pow((double) res, (1.00 / ((double) mat1->n)));
    return res;
}

// переносит данные из старой области в новую при realloc
void transfer_info(struct matrix *mat1, int *data, int m_new)
{
    int i = 0;
    for (; i < mat1->n; i++)
    {
        int j = 0;
        for (; j < mat1->m; j++)
            data[i * m_new + j] = mat1->arr[i][j];
        for (; j < m_new; j++)
            data[i * m_new + j] = 0;
    }
}

// заполняет новую область нулями при realloc
void zero_new(int *data, int i_start, int n_new, int m_new)
{
    for (int i = i_start; i < n_new; i++)
        for (int j = 0; j < m_new; j++)
            data[i * m_new + j] = 0;
}

// мой реаллок
int my_realloc(struct matrix *mat1, int n_new, int m_new)
{
    int rc = OK;

    if (n_new <= mat1->n && m_new <= mat1->m)
        return rc;

    int **tmp;
    int *data;

    tmp = calloc(n_new, sizeof(int*));
    if (tmp == NULL)
        rc = ERROR;
    else
    {
        data = calloc(n_new * m_new, sizeof(int));
        if (data == NULL)
            rc = ERROR;
        else
        {
            transfer_info(mat1, data, m_new);

            zero_new(data, mat1->n, n_new, m_new);

            for (int i = 0; i < n_new; i++)
                tmp[i] = data + i * m_new;

            free_mat(mat1);
            mat1->arr = tmp;
        }
    }
    return rc;
}

