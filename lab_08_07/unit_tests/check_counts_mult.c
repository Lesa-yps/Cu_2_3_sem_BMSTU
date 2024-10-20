#include "read_counts_mult.h"
#include "const_struct.h"
#include <check.h>
#include <stdio.h>

// читаем два целых неотрицательных числа (с проверками)
//int read_counts_mult(FILE* file, int *p, int *y);

// pos tests

START_TEST(test_read_counts_mult_pos_elems)
{
    FILE* file;
    int right_a = 1, right_b = 2; // положительные 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

START_TEST(test_read_counts_mult_pos_many_spaces_elems)
{
    FILE* file;
    int right_a = 1, right_b = 2; // положительные 2 целых числа несколько пробелов
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d                      %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

START_TEST(test_read_counts_mult_pos_diff_str_elems)
{
    FILE* file;
    int right_a = 1, right_b = 2; // положительные 2 целых числа на разных строчках
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d\n%d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

START_TEST(test_read_counts_mult_pos_many_str_elems)
{
    FILE* file;
    int right_a = 1, right_b = 2; // положительные 2 целых числа через строчку
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d\n\n%d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

START_TEST(test_read_counts_mult_zero_pos_elems)
{
    FILE* file;
    int right_a = 0, right_b = 2; // первое нуль, второе положительное 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

START_TEST(test_read_counts_mult_zero_elems)
{
    FILE* file;
    int right_a = 0, right_b = 0; // оба нули 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

START_TEST(test_read_counts_mult_sim_pos_elems)
{
    FILE* file;
    int right_a = 1, right_b = 1; // одинаковые положительные 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(a, right_a);
    ck_assert_int_eq(b, right_b);
}
END_TEST

// neg tests

START_TEST(test_read_counts_mult_neg_elems)
{
    FILE* file;
    int right_a = -1, right_b = -2; // отрицательные 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_diff1_elems)
{
    FILE* file;
    int right_a = 1, right_b = -2; // первое положительное, второе отрицательные 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_diff2_elems)
{
    FILE* file;
    int right_a = -1, right_b = 2; // первое отрицательное, второе положительное 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_zero_neg_elems)
{
    FILE* file;
    int right_a = -2, right_b = 0; // первое отрицательное, второе нуль 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_sim_neg_elems)
{
    FILE* file;
    int right_a = -1, right_b = -1; // одинаковые отрицательные 2 целых числа через пробел
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %d\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_one_elem)
{
    FILE* file;
    int right_a = -1; // одно число
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d\n", right_a);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_alpha_elems)
{
    FILE* file;
    char right_a = 'a', right_b = 'b'; // в файле буквы
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%c %c\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_alpha_digit_elems)
{
    FILE* file;
    int right_a = 1;
    char right_b = 'b'; // в файле число и буква
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fprintf(file, "%d %c\n", right_a, right_b);
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_counts_mult_empty_elems)
{
    FILE* file; // файл пуст
    int a, b;
    int rc;
    file = fopen("file.txt", "w");
    fclose(file);
    file = fopen("file.txt", "r");
    // читаем два целых неотрицательных числа (с проверками)
    rc = read_counts_mult(file, &a, &b);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* read_counts_mult_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции read_arr
    s = suite_create("read_counts_mult");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове read_counts_mult
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_read_counts_mult_neg_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_diff1_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_diff2_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_zero_neg_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_sim_neg_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_one_elem);
    tcase_add_test(tc_neg, test_read_counts_mult_alpha_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_alpha_digit_elems);
    tcase_add_test(tc_neg, test_read_counts_mult_empty_elems);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // read_arr для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_read_counts_mult_pos_elems);
    tcase_add_test(tc_pos, test_read_counts_mult_pos_many_spaces_elems);
    tcase_add_test(tc_pos, test_read_counts_mult_pos_diff_str_elems);
    tcase_add_test(tc_pos, test_read_counts_mult_pos_many_str_elems);
    tcase_add_test(tc_pos, test_read_counts_mult_zero_pos_elems);
    tcase_add_test(tc_pos, test_read_counts_mult_zero_elems);
    tcase_add_test(tc_pos, test_read_counts_mult_sim_pos_elems);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}

