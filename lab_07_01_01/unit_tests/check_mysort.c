#include "mysort.h"
#include <check.h>

//сортирует элементы массива выбором
//void mysort(void *arr, size_t n, size_t size, int (*compare)(const void *, const void *));

// Компаратор сравнения двух целых чисел
int comparator(const void *a, const void *b)
{
    const int *int_a = (const int *)a;
    const int *int_b = (const int *)b;

    return *int_a - *int_b;
}

// tests

START_TEST(test_mysort_right_order)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // массив уже отсортирован в правильном порядке
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

START_TEST(test_mysort_wrong_order)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // массив уже отсортирован в обратном порядке
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

START_TEST(test_mysort_random_order)
{
    int arr[] = {10, 2, 8, 6, 3, 5, 4, 1, 9, 7}; // произвольный порядок элементов
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

START_TEST(test_mysort_neg_elems)
{
    int arr[] = {-10, -2, -8, -6, -3, -5, -4, -1, -9, -7}; // отрицательные элементы
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

START_TEST(test_mysort_neg_pos_elems)
{
    int arr[] = {-1, 2, 0, -3, 4, -5, 10, 6, -7, -8, 9}; // отрицательные, положительные элементы и нуль
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {-8, -7, -5, -3, -1, 0, 2, 4, 6, 9, 10};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

START_TEST(test_mysort_similar_elems)
{
    int arr[] = {3, 3, 3, 3, 3}; // одинаковые элементы
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {3, 3, 3, 3, 3};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

START_TEST(test_mysort_one_elem)
{
    int arr[] = {1}; // 1 элемент
    int n = sizeof(arr) / sizeof(int);
    int arr_right[] = {1};
    //сортирует элементы массива выбором
    mysort(arr, n, sizeof(int), comparator);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_right[i]);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_all;

    // Создадим тестовый набор для тестирования функции key
    s = suite_create("mysort");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове key
    tc_all = tcase_create("tests");

    // Добавим в tc_all соответствующие функции-тесты
    tcase_add_test(tc_all, test_mysort_right_order);
    tcase_add_test(tc_all, test_mysort_wrong_order);
    tcase_add_test(tc_all, test_mysort_random_order);
    tcase_add_test(tc_all, test_mysort_neg_elems);
    tcase_add_test(tc_all, test_mysort_neg_pos_elems);
    tcase_add_test(tc_all, test_mysort_similar_elems);
    tcase_add_test(tc_all, test_mysort_one_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_all);

    return s;
}
