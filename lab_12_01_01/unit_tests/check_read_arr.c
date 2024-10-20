#include "read_arr_lib.h"
#include <check.h>
#include <stdio.h>

#define OK 0
#define COUNT_TEST 10

//чтение массива из файла
//int read_arr(FILE* file, int *arr_beg, int *arr_end)

// pos tests

START_TEST(test_read_arr_pos_elems)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // положительные числа
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr[i]);
}
END_TEST

START_TEST(test_read_arr_neg_elems)
{
    FILE* file;
    int arr[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}; // отрицательные числа
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr[i]);
}
END_TEST

START_TEST(test_read_arr_pos_neg_elems)
{
    FILE* file;
    int arr[] = {-1, -2, 3, -4, 5, 6, -7, 0, 9, -10}; // положительные, отрицательные числа и нуль
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr[i]);
}
END_TEST

START_TEST(test_read_arr_similar_elems)
{
    FILE* file;
    int arr[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; // одинаковые числа
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr[i]);
}
END_TEST

START_TEST(test_read_arr_one_elem)
{
    FILE* file;
    int arr[] = {1}; // одно число
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr[i]);
}
END_TEST

// neg tests

START_TEST(test_read_arr_wrong_n)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%d ", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n + 1); // n больше чем реальное количество чисел в файле
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_arr_alpha_digit)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n / 2; i++)
        fprintf(file, "%d %c\n", arr[i], 'a' + i); // числа в файле вперемешку с буквами
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_arr_alpha)
{
    FILE* file;
    int rc;
    int n = COUNT_TEST;
    int arr_new[COUNT_TEST];
    file = fopen("file.txt", "w");
    for (int i = 0; i < n; i++)
        fprintf(file, "%c\n", 'a' + i); // в файле только буквы
    fclose(file);
    file = fopen("file.txt", "r");
    //чтение массива из файла
    rc = read_arr(file, arr_new, arr_new + n);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* read_arr_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции read_arr
    s = suite_create("read_arr");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове read_arr
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_read_arr_wrong_n);
    tcase_add_test(tc_neg, test_read_arr_alpha_digit);
    tcase_add_test(tc_neg, test_read_arr_alpha);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // read_arr для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_read_arr_pos_elems);
    tcase_add_test(tc_pos, test_read_arr_neg_elems);
    tcase_add_test(tc_pos, test_read_arr_pos_neg_elems);
    tcase_add_test(tc_pos, test_read_arr_similar_elems);
    tcase_add_test(tc_pos, test_read_arr_one_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}

