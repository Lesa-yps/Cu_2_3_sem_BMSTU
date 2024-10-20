#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "check_arr_lib.h"
#include "arr_lib.h"

// arr_go

// сдвиг на 0
START_TEST(test_arr_go_0)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int arr_new[] = {0, 0, 0, 0, 0};
    int k = 0;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
}
END_TEST

// сдвиг на 1
START_TEST(test_arr_go_1)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {2, 3, 4, 5, 1};
    int n = sizeof(arr) / sizeof(int);
    int arr_new[] = {0, 0, 0, 0, 0};
    int k = 1;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
}
END_TEST

// сдвиг на -1
START_TEST(test_arr_go_m1)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {5, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int k = -1;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// сдвиг на 2
START_TEST(test_arr_go_2)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int k = 2;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// сдвиг на -2
START_TEST(test_arr_go_m2)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {4, 5, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int k = -2;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// сдвиг на размер массива
START_TEST(test_arr_go_n)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int k = n;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// сдвиг на 2 отрицательных размера массива
START_TEST(test_arr_go_mn2)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int k = -2 * n;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// сдвиг массива из 1 элемента на 2 влево
START_TEST(test_arr_go_one2)
{
    int arr[] = {1};
    int arr_res[] = {1};
    int n = sizeof(arr) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int k = 2;
    arr_go(arr, n, arr_new, k);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// arr_filtr

// все элементы - полные квадраты
START_TEST(test_arr_filtr_all)
{
    int arr[] = {4, 9, 16, 25, 36};
    int arr_res[] = {4, 9, 16, 25, 36};
    int n = sizeof(arr) / sizeof(int);
    int n_res = sizeof(arr_res) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int n_new = arr_filtr(arr, n, arr_new);
    ck_assert_int_eq(n_new, n_res);
    for (int i = 0; i < n_res; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// половина элементов - полные квадраты (чередуются)
START_TEST(test_arr_filtr_part_alt)
{
    int arr[] = {11, 9, 2, 25, 3, 49};
    int arr_res[] = {9, 25, 49};
    int n = sizeof(arr) / sizeof(int);
    int n_res = sizeof(arr_res) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int n_new = arr_filtr(arr, n, arr_new);
    ck_assert_int_eq(n_new, n_res);
    for (int i = 0; i < n_res; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// половина элементов - полные квадраты (первая половина)
START_TEST(test_arr_filtr_part_first)
{
    int arr[] = {9, 25, 49, -1, 2, -3};
    int arr_res[] = {9, 25, 49};
    int n = sizeof(arr) / sizeof(int);
    int n_res = sizeof(arr_res) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int n_new = arr_filtr(arr, n, arr_new);
    ck_assert_int_eq(n_new, n_res);
    for (int i = 0; i < n_res; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// половина элементов - полные квадраты (вторая половина)
START_TEST(test_arr_filtr_part_last)
{
    int arr[] = {11, -2, 3, 9, 25, 49};
    int arr_res[] = {9, 25, 49};
    int n = sizeof(arr) / sizeof(int);
    int n_res = sizeof(arr_res) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int n_new = arr_filtr(arr, n, arr_new);
    ck_assert_int_eq(n_new, n_res);
    for (int i = 0; i < n_res; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// один элемент - полный квадрат
START_TEST(test_arr_filtr_one)
{
    int arr[] = {11, -2, 3, 9, 5, 7};
    int arr_res[] = {9};
    int n = sizeof(arr) / sizeof(int);
    int n_res = sizeof(arr_res) / sizeof(int);
    int *arr_new = calloc(n, 0);
    int n_new = arr_filtr(arr, n, arr_new);
    ck_assert_int_eq(n_new, n_res);
    for (int i = 0; i < n_res; i++)
        ck_assert_int_eq(arr_new[i], arr_res[i]);
    free(arr_new);
}
END_TEST

// нет полных квадратов
START_TEST(test_arr_filtr_no)
{
    int arr[] = {11, 2, 3, 14, 5};
    int n = sizeof(arr) / sizeof(int);
    int n_res = 0;
    int *arr_new = calloc(n, 0);
    int n_new = arr_filtr(arr, n, arr_new);
    ck_assert_int_eq(n_new, n_res);
    free(arr_new);
}
END_TEST

Suite *arr_lib_suite(void)
{
    Suite *suite = suite_create("arr_lib");

    TCase *tc_all = tcase_create("all_tests");

    // arr_go
    tcase_add_test(tc_all, test_arr_go_0);
    tcase_add_test(tc_all, test_arr_go_1);
    tcase_add_test(tc_all, test_arr_go_m1);
    tcase_add_test(tc_all, test_arr_go_2);
    tcase_add_test(tc_all, test_arr_go_m2);
    tcase_add_test(tc_all, test_arr_go_n);
    tcase_add_test(tc_all, test_arr_go_mn2);
    tcase_add_test(tc_all, test_arr_go_one2);

    // arr_filtr
    tcase_add_test(tc_all, test_arr_filtr_all);
    tcase_add_test(tc_all, test_arr_filtr_part_alt);
    tcase_add_test(tc_all, test_arr_filtr_part_first);
    tcase_add_test(tc_all, test_arr_filtr_part_last);
    tcase_add_test(tc_all, test_arr_filtr_one);
    tcase_add_test(tc_all, test_arr_filtr_no);

    suite_add_tcase(suite, tc_all);
    return suite;
}

