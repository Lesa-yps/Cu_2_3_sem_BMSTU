#include "all_for_3D.h"

int create_mat(struct matrix *mat1, int n_max, int m_max, int k_max)
{
    int rc = OK;
    // Объявляем указатель на целочисленный массив data, который будет хранить элементы матрицы.
    int *data;
    // Объявляем указатель на указатель на указатель на целочисленный массив ptrs.
    int ***ptrs;

    // Инициализируем поля структуры mat1 (n, m, k) нулевыми значениями.
    mat1->n = 0;
    mat1->m = 0;
    mat1->k = 0;

    // Выделяем память для массива указателей, который будет хранить указатели на строки матрицы.
    mat1->arr = calloc(n_max, sizeof(int**));

    if (mat1->arr == NULL) // Проверяем, удалось ли выделить память для mat1->arr.
        rc = ERROR;
    else
    {
        // Выделяем память для массива указателей, который будет хранить указатели на столбцы матрицы.
        ptrs = calloc(n_max, sizeof(int**));

        if (ptrs == NULL) // Проверяем, удалось ли выделить память для ptrs.
            rc = ERROR;
        else
        {
            // Выделяем память для данных матрицы (элементов).
            data = calloc(n_max * m_max * k_max, sizeof(int));

            if (data == NULL) // Проверяем, удалось ли выделить память для data.
            {
                rc = ERROR;
                // Освобождаем память, выделенную для mat1->arr.
                free(mat1->arr);
            }
            for (int i = 0; i < n_max && rc == OK; i++)
            {
                // Для каждой строки матрицы (i-й) выделяем память для указателей на столбцы матрицы.
                mat1->arr[i] = calloc(m_max, sizeof(int*));

                if (mat1->arr[i] == NULL) // Проверяем, удалось ли выделить память для mat1->arr[i].
                {
                    rc = ERROR;
                    continue;
                }

                for (int j = 0; j < m_max; j++)
                {
                    // Заполняем указателями на данные (элементы) матрицы, соответствующими i-й строке и j-му столбцу.
                    mat1->arr[i][j] = data + (i * m_max * k_max + j * k_max);
                }
            }
            // Освобождаем память, выделенную для ptrs
            free(ptrs);
        }
    }

    return rc;
}

void free_mat(struct matrix *mat1)
{
    free(mat1->arr[0][0]);
    free(mat1->arr[0]);
    free(mat1->arr);
}

// вывод матрицы
void print_mat(FILE *file, struct matrix mat)
{
    fprintf(file, "\n");
    for (int i = 0; i < mat.k; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            for (int w = 0; w < mat.m; w++)
                fprintf(file, "%d ", mat.arr[j][w][i]);
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
    }
}

// читает целое число из файла в диапазоне
int read_int(FILE *file, int *num, int mini, int maxi)
{
    int rc = OK;
    if (fscanf(file, "%d", num) != 1 || *num < mini || *num > maxi || *num == EOF)
        rc = ERROR;
    return rc;
}

// чтение матрицы и выделение ей памяти
int read_mat(FILE *file, struct matrix *mat1)
{
    int rc = OK;
    // прочитали элементы матрицы и проверили ввод
    //printf("Введите элементы матрицы: ");
    for (int i = 0; (i < mat1->k) && (rc == OK); i++)
        for (int j = 0; (j < mat1->n) && (rc == OK); j++)
            for (int w = 0; (w < mat1->m) && (rc == OK); w++)
            {
                if (fscanf(file, "%d", &(mat1->arr[j][w][i])) != 1)
                    rc = ERROR;
            }
    return rc;
}

int read_mat_all(FILE *file, struct matrix *mat1)
{
    int rc = OK;
    int n1, m1, k1;
    rc = read_int(file, &n1, 1, __INT_MAX__);
    if (rc == OK)
    {
        rc = read_int(file, &m1, 1, __INT_MAX__);
        if (rc == OK)
        {
            rc = read_int(file, &k1, 1, __INT_MAX__);
            if (rc == OK)
            {
                rc = create_mat(mat1, n1, m1, k1);
                if (rc == OK)
                {
                    mat1->n = n1;
                    mat1->m = m1;
                    mat1->k = k1;
                    rc = read_mat(file, mat1);
                }
                else
                    free_mat(mat1);
            }
        }
    }
    return rc;
}
