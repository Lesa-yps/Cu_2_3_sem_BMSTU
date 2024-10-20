#include "count_num.h"
#include <check.h>
#include <stdio.h>

#define OK 0
#define COUNT_TEST 10

//считает количество чисел в файле
//int count_num(FILE* file, int *n)

// pos tests

START_TEST(test_count_num_pos_elems)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // положительные числа
    int n_right = sizeof(arr) / sizeof(int);
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < n_right; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n, n_right);
}
END_TEST

START_TEST(test_count_num_neg_elems)
{
    FILE* file;
    int arr[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}; // отрицательные числа
    int n_right = sizeof(arr) / sizeof(int);
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < n_right; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n, n_right);
}
END_TEST

START_TEST(test_count_num_pos_neg_elems)
{
    FILE* file;
    int arr[] = {-1, -2, 3, -4, 5, 6, -7, 0, 9, -10}; // положительные, отрицательные числа и нуль
    int n_right = sizeof(arr) / sizeof(int);
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < n_right; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n, n_right);
}
END_TEST

START_TEST(test_count_num_similar_elems)
{
    FILE* file;
    int arr[] = {3, 3, 3, 3, 3}; // одинаковые числа
    int n_right = sizeof(arr) / sizeof(int);
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < n_right; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n, n_right);
}
END_TEST

START_TEST(test_count_num_one_elem)
{
    FILE* file;
    int arr[] = {1}; // одно число
    int n_right = sizeof(arr) / sizeof(int);
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < n_right; i++)
        fprintf(file, "%d\n", arr[i]);
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n, n_right);
}
END_TEST

// neg tests

START_TEST(test_count_num_alpha_digit)
{
    FILE* file;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n_right = sizeof(arr) / sizeof(int);
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < n_right; i++)
        fprintf(file, "%d %c\n", arr[i], 'a' + i); // числа в файле вперемешку с буквами
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_count_num_alpha)
{
    FILE* file;
    int rc;
    int n;
    file = fopen("file.txt", "w");
    for (int i = 0; i < COUNT_TEST; i++)
        fprintf(file, "%c\n", 'a' + i); // в файле только буквы
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_count_num_empty)
{
    FILE* file;
    int rc;
    int n;
    file = fopen("file.txt", "w"); // файл пуст
    fclose(file);
    file = fopen("file.txt", "r");
    //считает количество чисел в файле
    rc = count_num(file, &n);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* count_num_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции count_num
    s = suite_create("count_num");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове count_num
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_count_num_alpha_digit);
    tcase_add_test(tc_neg, test_count_num_alpha);
    tcase_add_test(tc_neg, test_count_num_empty);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // count_num для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_count_num_pos_elems);
    tcase_add_test(tc_pos, test_count_num_neg_elems);
    tcase_add_test(tc_pos, test_count_num_pos_neg_elems);
    tcase_add_test(tc_pos, test_count_num_similar_elems);
    tcase_add_test(tc_pos, test_count_num_one_elem);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
