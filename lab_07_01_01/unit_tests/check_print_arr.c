#include "print_arr.h"
#include <check.h>
#include <stdio.h>

#define OK 0

// вывод массива в файл
// int print_arr(FILE* file, int *arr_beg, int *arr_end)

// pos tests

START_TEST(test_print_arr_pos_elems)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // положительные числа
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int i = 0;
    int x;
    int arr_new[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    file = fopen("file.txt", "w");
    //вывод массива в файл
    rc = print_arr(file, arr_new, arr_new + n);
    ck_assert_int_eq(rc, OK);
    fclose(file);
    file = fopen("file.txt", "r");
    while ((fscanf(file, "%d", &x) == 1) && (i < n))
    {
        ck_assert_int_eq(x, arr[i]);
        i++;
    }
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    fclose(file);
}
END_TEST

START_TEST(test_print_arr_neg_elems)
{
    FILE* file;
    int arr[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}; // отрицательные числа
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int i = 0;
    int x;
    int arr_new[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    file = fopen("file.txt", "w");
    //вывод массива в файл
    rc = print_arr(file, arr_new, arr_new + n);
    ck_assert_int_eq(rc, OK);
    fclose(file);
    file = fopen("file.txt", "r");
    while (fscanf(file, "%d", &x) == 1 && i < n)
    {
        ck_assert_int_eq(x, arr[i]);
        i++;
    }
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    fclose(file);
}
END_TEST

START_TEST(test_print_arr_pos_neg_elems)
{
    FILE* file;
    int arr[] = {-1, -2, 3, -4, 5, 6, -7, 0, 9, -10}; // положительные, отрицательные числа и нуль
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int i = 0;
    int x;
    int arr_new[] = {-1, -2, 3, -4, 5, 6, -7, 0, 9, -10};
    file = fopen("file.txt", "w");
    //вывод массива в файл
    rc = print_arr(file, arr_new, arr_new + n);
    ck_assert_int_eq(rc, OK);
    fclose(file);
    file = fopen("file.txt", "r");
    while (fscanf(file, "%d", &x) == 1 && i < n)
    {
        ck_assert_int_eq(x, arr[i]);
        i++;
    }
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    fclose(file);
}
END_TEST

START_TEST(test_print_arr_similar_elems)
{
    FILE* file;
    int arr[] = {3, 3, 3, 3, 3}; // одинаковые числа
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int i = 0;
    int x;
    int arr_new[] = {3, 3, 3, 3, 3};
    file = fopen("file.txt", "w");
    //вывод массива в файл
    rc = print_arr(file, arr_new, arr_new + n);
    ck_assert_int_eq(rc, OK);
    fclose(file);
    file = fopen("file.txt", "r");
    while (fscanf(file, "%d", &x) == 1 && i < n)
    {
        ck_assert_int_eq(x, arr[i]);
        i++;
    }
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    fclose(file);
}
END_TEST

START_TEST(test_print_arr_one_elem)
{
    FILE* file;
    int arr[] = {1}; // одно число
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int i = 0;
    int x;
    int arr_new[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    file = fopen("file.txt", "w");
    //вывод массива в файл
    rc = print_arr(file, arr_new, arr_new + n);
    ck_assert_int_eq(rc, OK);
    fclose(file);
    file = fopen("file.txt", "r");
    while (fscanf(file, "%d", &x) == 1 && i < n)
    {
        ck_assert_int_eq(x, arr[i]);
        i++;
    }
    ck_assert_int_eq(fscanf(file, "%d", &x), EOF);
    fclose(file);
}
END_TEST

// neg tests

START_TEST(test_print_arr_wrong_mode)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int rc;
    file = fopen("file.txt", "r"); // файл открыт только на чтение
    //вывод массива в файл
    rc = print_arr(file, arr, arr + n);
    ck_assert_int_eq(rc, ERROR);
    fclose(file);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* print_arr_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции print_arr
    s = suite_create("print_arr");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове print_arr
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_print_arr_wrong_mode);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // print_arr для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_print_arr_pos_elems);
    tcase_add_test(tc_pos, test_print_arr_neg_elems);
    tcase_add_test(tc_pos, test_print_arr_pos_neg_elems);
    tcase_add_test(tc_pos, test_print_arr_similar_elems);
    tcase_add_test(tc_pos, test_print_arr_one_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
