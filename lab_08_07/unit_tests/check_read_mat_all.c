#include "read_mat_all.h"
#include "const_struct.h"
#include "create_mat.h"
#include "free_mat.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

// чтение матрицы и выделение ей памяти
// int read_mat_all(FILE *file, struct matrix *mat1)

// pos tests

#define SIZE_MAT 10

START_TEST(test_read_mat_all_pos_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1; // положительные числа
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_neg_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = (-1) * i - 1; // отрицательные числа
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_pos_neg_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i - 50; // положительные, отрицательные числа и нуль
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_similar_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = (int) 3; // одинаковые числа
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_one_elem)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int m1 = 1, n1 = 1;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = (int) i + 1; // одно число
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_more_str_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int n1 = SIZE_MAT;
    int m1= SIZE_MAT / 2; // строк больше, чем столбцов
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = (int) i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_more_col_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int n1 = SIZE_MAT / 2;
    int m1 = SIZE_MAT; // столбцов больше, чем строк
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = (int) i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

START_TEST(test_read_mat_all_one_str_elems)
{
    FILE* file;
    struct matrix mat;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d ", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]); // все числа и размерности записаны в одной строке
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(mat_right.n, mat.n);
    ck_assert_int_eq(mat_right.m, mat.m);
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            ck_assert_int_eq(mat.arr[i][j], mat_right.arr[i][j]);
    free_mat(&mat_right);
    free_mat(&mat);
}
END_TEST

// neg tests

START_TEST(test_read_mat_all_wromg_n)
{
    FILE* file;
    struct matrix mat;
    mat.arr = NULL;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n * 2, mat_right.m * 2); // записаны размерности больше, чем на самом деле
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
    free_mat(&mat_right);
}
END_TEST

START_TEST(test_read_mat_all_alpha_n)
{
    FILE* file;
    struct matrix mat;
    mat.arr = NULL;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "a b\n"); // вместо размерностей буквы
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
    free_mat(&mat_right);
}
END_TEST

START_TEST(test_read_mat_all_neg_n)
{
    FILE* file;
    struct matrix mat;
    mat.arr = NULL;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", (-1) * mat_right.n,  (-1) * mat_right.m); // размерности отрицательные
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
    free_mat(&mat_right);
}
END_TEST

START_TEST(test_read_mat_all_zero_n)
{
    FILE* file;
    struct matrix mat;
    mat.arr = NULL;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "0 0\n"); // размерности нулевые
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d ", mat_right.arr[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
    free_mat(&mat_right);
}
END_TEST

START_TEST(test_read_mat_all_alpha_elems)
{
    FILE* file;
    struct matrix mat;
    mat.arr = NULL;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n,  mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%c ", 'a' + (i * mat_right.m + j) % SIZE_MAT); // вместо элементов буквы
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
    free_mat(&mat_right);
}
END_TEST

START_TEST(test_read_mat_all_no_spaces)
{
    FILE* file;
    struct matrix mat;
    mat.arr = NULL;
    struct matrix mat_right;
    int m1 = SIZE_MAT, n1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat_right, n1, m1), OK);
    mat_right.n = n1;
    mat_right.m = m1;
    for (int i = 0; i < mat_right.n; i++)
        for (int j = 0; j < mat_right.m; j++)
            mat_right.arr[i][j] = i + 1;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", mat_right.n, mat_right.m);
    for (int i = 0; i < mat_right.n; i++)
    {
        for (int j = 0; j < mat_right.m; j++)
            fprintf(file, "%d", mat_right.arr[i][j]); // числа записаны без пробелов
        fprintf(file, "\n");
    }
    fclose(file);
    file = fopen("file.txt", "r");
    // чтение матрицы и выделение ей памяти
    rc = read_mat_all(file, &mat);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
    free_mat(&mat_right);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* read_mat_all_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции read_mat_all
    s = suite_create("read_mat_all");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове read_mat_all
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_read_mat_all_wromg_n);
    tcase_add_test(tc_neg, test_read_mat_all_alpha_n);
    tcase_add_test(tc_neg, test_read_mat_all_neg_n);
    tcase_add_test(tc_neg, test_read_mat_all_zero_n);
    tcase_add_test(tc_neg, test_read_mat_all_alpha_elems);
    tcase_add_test(tc_neg, test_read_mat_all_no_spaces);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // read_mat_allдля корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_read_mat_all_pos_elems);
    tcase_add_test(tc_pos, test_read_mat_all_neg_elems);
    tcase_add_test(tc_pos, test_read_mat_all_pos_neg_elems);
    tcase_add_test(tc_pos, test_read_mat_all_similar_elems);
    tcase_add_test(tc_pos, test_read_mat_all_one_elem);
    tcase_add_test(tc_pos, test_read_mat_all_more_str_elems);
    tcase_add_test(tc_pos, test_read_mat_all_more_col_elems);
    tcase_add_test(tc_pos, test_read_mat_all_one_str_elems);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}

