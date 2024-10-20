#include "del_mat.h"

// внутренние функции
void del_str(struct matrix *mat1, int ind_str);
int del_col(struct matrix *mat1, int ind_col);
// находит индексы первого минимального элемента в матрице
void find_min(struct matrix *mat1, int *ind_i, int *ind_j);

// удаляет строки/столбцы с минимальным первым элементом при обходе по столбцам пока матрица не квадратная
int del_mat(struct matrix *mat1)
{
    int rc = OK;
    int ind_i;
    int ind_j;
    // пока матрица не квадратная повторяем
    while (mat1->n != mat1->m && rc == OK)
    {
        find_min(mat1, &ind_i, &ind_j);
        // если строк больше чем столбцов, удаляем строку с минимальным элементом
        if (mat1->n > mat1->m)
            del_str(mat1, ind_i);
        // иначе столбец
        else
            rc = del_col(mat1, ind_j);
    }
    return rc;
}

// удаляем строку по индексу
void del_str(struct matrix *mat1, int ind_str)
{
    (mat1->n)--;
    for (int i = ind_str; i < mat1->n; i++)
        for (int j = 0; j < mat1->m; j++)
            mat1->arr[i][j] = mat1->arr[i + 1][j];
}

// удаляем столбец по индексу
int del_col(struct matrix *mat1, int ind_col)
{
    int rc = OK;
    int count = 0;
    int *data = calloc(mat1->m * mat1->n, sizeof(int));
    if (data == NULL)
        rc = ERROR;
    else
    {
        for (int i = 0; i < mat1->n; i++)
            for (int j = 0; j < mat1->m; j++)
                if (j != ind_col)
                {
                    data[count] = mat1->arr[i][j];
                    count++;
                }
        (mat1->m)--;
        for (int i = 0; i < mat1->n; i++)
            for (int j = 0; j < mat1->m; j++)
                mat1->arr[i][j] = data[i * mat1->m + j];
        free(data);
    }

    return rc;
}

// находит индексы первого минимального элемента в матрице
void find_min(struct matrix *mat1, int *ind_i, int *ind_j)
{
    // начальный минимальный элемент - первый
    int mini = mat1->arr[0][0];
    // индекс начального минимального = 0
    *ind_i = 0;
    *ind_j = 0;
    // начинаем проход по столбцам со второго элемента и находим первый минимальный элемент (запоминаем его номер)
    for (int j = 0; j < mat1->m; j++)
        for (int i = 0; i < mat1->n; i++)
            if (mat1->arr[i][j] < mini)
            {
                mini = mat1->arr[i][j];
                *ind_i = i;
                *ind_j = j;
            }
}
