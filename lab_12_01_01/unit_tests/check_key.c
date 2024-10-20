#include "key_lib.h"
#include <check.h>
#include "const.h"

//фильтр оставляет числа только между минимальным и максимальным (не вкл)
//int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

// pos tests

START_TEST(test_key_array_min_first_max_last)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // min_ind = 0, max_ind = 9
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    int arr_right[] = {2, 3, 4, 5, 6, 7, 8, 9};
    int n_right = sizeof(arr_right) / sizeof(int);
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr_new_end - arr_new_beg, n_right);
    for (int i = 0; i < n_right; i++)
        ck_assert_int_eq(arr_new_beg[i], arr_right[i]);
    free(arr_new_beg);
}
END_TEST

START_TEST(test_key_array_min_last_max_first)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // min_ind = 9, max_ind = 0
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    int arr_right[] = {9, 8, 7, 6, 5, 4, 3, 2};
    int n_right = sizeof(arr_right) / sizeof(int);
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr_new_end - arr_new_beg, n_right);
    for (int i = 0; i < n_right; i++)
        ck_assert_int_eq(arr_new_beg[i], arr_right[i]);
    free(arr_new_beg);
}
END_TEST

START_TEST(test_key_array_min_many)
{
    int arr[] = {1, 2, 3, 1, 4, 5, 4, 3, 2, 1}; // несколько минимальных элементов
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    int arr_right[] = {2, 3, 1, 4};
    int n_right = sizeof(arr_right) / sizeof(int);
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr_new_end - arr_new_beg, n_right);
    for (int i = 0; i < n_right; i++)
        ck_assert_int_eq(arr_new_beg[i], arr_right[i]);
    free(arr_new_beg);
}
END_TEST

START_TEST(test_key_array_max_many)
{
    int arr[] = {1, 2, 3, 5, 4, 3, 5, 3, 2, 4}; // несколько максимальных элементов
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    int arr_right[] = {2, 3};
    int n_right = sizeof(arr_right) / sizeof(int);
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr_new_end - arr_new_beg, n_right);
    for (int i = 0; i < n_right; i++)
        ck_assert_int_eq(arr_new_beg[i], arr_right[i]);
    free(arr_new_beg);
}
END_TEST


START_TEST(test_key_array_min_max_many)
{
    int arr[] = {1, 2, 5, 1, 4, 5, 6, 4, 3, 6}; // несколько минимальных и максимальных элементов
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    int arr_right[] = {2, 5, 1, 4, 5};
    int n_right = sizeof(arr_right) / sizeof(int);
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr_new_end - arr_new_beg, n_right);
    for (int i = 0; i < n_right; i++)
        ck_assert_int_eq(arr_new_beg[i], arr_right[i]);
    free(arr_new_beg);
}
END_TEST

START_TEST(test_key_array_stay_one_elem)
{
    int arr[] = {1, 2, 3, 0, 4, 6, 5, 4, 3, 2}; // после фильтрации останется один элемент
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    int arr_right[] = {4};
    int n_right = sizeof(arr_right) / sizeof(int);
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr_new_end - arr_new_beg, n_right);
    for (int i = 0; i < n_right; i++)
        ck_assert_int_eq(arr_new_beg[i], arr_right[i]);
    free(arr_new_beg);
}
END_TEST

// neg tests

START_TEST(test_key_array_similar_elems)
{
    int arr[] = {3, 3, 3, 3, 3, 3, 3}; // после фильтрации не останется элементов
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_key_array_two_elems)
{
    int arr[] = {1, 5}; // после фильтрации не останется элементов
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_key_array_one_elem)
{
    int arr[] = {1}; // после фильтрации не останется элементов
    int n = sizeof(arr) / sizeof(int);
    int rc;
    int *arr_new_beg;
    int *arr_new_end;
    //фильтр оставляет числа только между минимальным и максимальным (не вкл)
    rc = key(arr, arr + n, &arr_new_beg, &arr_new_end);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции key
    s = suite_create("key");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове key
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_key_array_similar_elems);
    tcase_add_test(tc_neg, test_key_array_two_elems);
    tcase_add_test(tc_neg, test_key_array_one_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // key для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_key_array_min_first_max_last);
    tcase_add_test(tc_pos, test_key_array_min_last_max_first);
    tcase_add_test(tc_pos, test_key_array_min_many);
    tcase_add_test(tc_pos, test_key_array_max_many);
    tcase_add_test(tc_pos, test_key_array_min_max_many);
    tcase_add_test(tc_pos, test_key_array_stay_one_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
