#include "print_mat.h"
#include "const_struct.h"
#include "create_mat.h"
#include "free_mat.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAT 10

// вывод матрицы по строкам
// void print_mat(FILE *file, struct matrix *mat)

// tests

START_TEST(test_print_mat_pos_elems)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = SIZE_MAT, m1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = i + j + 1; // положительные числа
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

START_TEST(test_print_mat_neg_elems)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = SIZE_MAT, m1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = (-1) * i - 1; // отрицательные числа
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

START_TEST(test_print_mat_pos_neg_elems)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = SIZE_MAT, m1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = i - 50; // положительные, отрицательные числа и нуль
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

START_TEST(test_print_mat_similar_elems)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = SIZE_MAT, m1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = 1; // одинаковые числа
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

START_TEST(test_print_mat_one_elem)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = 1, m1 = 1;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = i + 1; // одно число
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

START_TEST(test_print_mat_more_str_elem)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = SIZE_MAT;
    int m1 = SIZE_MAT / 2;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = i + j + 1; // строк больше, чем столбцов
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

START_TEST(test_print_mat_more_col_elem)
{
    FILE* file;
    int fin = OK;
    struct matrix mat;
    int n1 = SIZE_MAT / 2;
    int m1 = SIZE_MAT;
    ck_assert_int_eq(create_mat(&mat, n1, m1), OK);
    mat.n = n1;
    mat.m = m1;
    for (int i = 0; i < mat.n; i++)
        for (int j = 0; j < mat.m; j++)
            mat.arr[i][j] = i + j + 1; // столбцов больше, чем строк
    int x;
    file = fopen("file.txt", "w");
    // вывод матрицы по строкам
    print_mat(file, &mat);
    fclose(file);
    file = fopen("file.txt", "r");
    for (int i = 0; i < mat.n && !fin; i++)
        for (int j = 0; j < mat.m && !fin; j++)
        {
            if (fscanf(file, "%d", &x) == 1)
                ck_assert_int_eq(x, mat.arr[i][j]);
            else
                fin = ERROR;
        }
    ck_assert_int_eq(fin, OK);
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    free_mat(&mat);
    fclose(file);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* print_mat_suite(void)
{
    Suite *s;
    TCase *tc_all;

    // Создадим тестовый набор для тестирования функции print_mat
    s = suite_create("print_mat");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // print_arr для корректных параметров
    tc_all = tcase_create("all_tests");
    // Добавим в tc_all соответствующие функции-тесты
    tcase_add_test(tc_all, test_print_mat_pos_elems);
    tcase_add_test(tc_all, test_print_mat_neg_elems);
    tcase_add_test(tc_all, test_print_mat_pos_neg_elems);
    tcase_add_test(tc_all, test_print_mat_similar_elems);
    tcase_add_test(tc_all, test_print_mat_one_elem);
    tcase_add_test(tc_all, test_print_mat_more_str_elem);
    tcase_add_test(tc_all, test_print_mat_more_col_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_all);

    return s;
}
