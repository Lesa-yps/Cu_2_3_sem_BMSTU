#include "my_snprintf.h"
#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#define SIZE_OF_BUF 50

// pos tests

// только строки

//- 01 - "%s"
START_TEST(test_str_only)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%s", strk);
    rc = snprintf(buffer, sizeof(buffer), "%s", strk);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 02 - " %s "
START_TEST(test_str_spaces)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), " %s ", strk);
    rc = snprintf(buffer, sizeof(buffer), " %s ", strk);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 03 - "%s%s"
START_TEST(test_str2_solid)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!";
    char strk2[] = " I come in!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%s%s", strk1, strk2);
    rc = snprintf(buffer, sizeof(buffer), "%s%s", strk1, strk2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 04 - " %s %s\n"
START_TEST(test_str2_spaces)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!";
    char strk2[] = " I come in!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), " %s %s\n", strk1, strk2);
    rc = snprintf(buffer, sizeof(buffer), " %s %s\n", strk1, strk2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 05 - "abc%scds%s erf2"
START_TEST(test_str2_alphas)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!";
    char strk2[] = " I come in!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "abc%scds%s erf2", strk1, strk2);
    rc = snprintf(buffer, sizeof(buffer), "abc%scds%s erf2", strk1, strk2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 06 - "\n%s\n%s erf2"
START_TEST(test_str2_alphas_spaces)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!";
    char strk2[] = " I come in!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "\n%s\n%s erf2", strk1, strk2);
    rc = snprintf(buffer, sizeof(buffer), "\n%s\n%s erf2", strk1, strk2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

// только числа

//- 07.1 - "%ld" (положительное число)
START_TEST(test_num_only_pos)
{
    int rc, rc_my;
    long int num = 345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld", num);
    rc = snprintf(buffer, sizeof(buffer), "%ld", num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 07.2 - "%ld" (отрицательное число)
START_TEST(test_num_only_neg)
{
    int rc, rc_my;
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld", num);
    rc = snprintf(buffer, sizeof(buffer), "%ld", num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 07.3 - "%ld" (нуль)
START_TEST(test_num_only_zero)
{
    int rc, rc_my;
    long int num = 0;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld", num);
    rc = snprintf(buffer, sizeof(buffer), "%ld", num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 07.4 - "%ld" (max)
START_TEST(test_num_max)
{
    int rc, rc_my;
    long int num = LONG_MAX;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld", num);
    rc = snprintf(buffer, sizeof(buffer), "%ld", num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 07.5 - "%ld" (min)
START_TEST(test_num_min)
{
    int rc, rc_my;
    long int num = LONG_MIN;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld", num);
    rc = snprintf(buffer, sizeof(buffer), "%ld", num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 08 - " %ld "
START_TEST(test_num_spaces)
{
    int rc, rc_my;
    long int num = -23;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld", num);
    rc = snprintf(buffer, sizeof(buffer), "%ld", num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 09.1 - "%ld%ld" (положительные числа)
START_TEST(test_num2_solid_pos)
{
    int rc, rc_my;
    long int num1 = 345;
    long int num2 = 21;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld%ld", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), "%ld%ld", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 09.2 - "%ld%ld" (отрицательные числа)
START_TEST(test_num2_solid_neg)
{
    int rc, rc_my;
    long int num1 = -345;
    long int num2 = -21;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld%ld", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), "%ld%ld", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 09.3 - "%ld%ld" (положительное и отрицательное числа)
START_TEST(test_num2_solid_pos_neg)
{
    int rc, rc_my;
    long int num1 = 345;
    long int num2 = -21;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld%ld", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), "%ld%ld", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 09.4 - "%ld%ld" (отрицательное и положительное числа)
START_TEST(test_num2_solid_neg_pos)
{
    int rc, rc_my;
    long int num1 = -21;
    long int num2 = 345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld%ld", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), "%ld%ld", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 10 - " %ld %ld\n"
START_TEST(test_num2_spaces)
{
    int rc, rc_my;
    long int num1 = -21;
    long int num2 = 345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), " %ld %ld\n", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), " %ld %ld\n", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 11 - "abc%ldcds%ld erf2"
START_TEST(test_num2_alphas)
{
    int rc, rc_my;
    long int num1 = 345;
    long int num2 = -21;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "abc%ldcds%ld erf2", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), "abc%ldcds%ld erf2", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 12 - "\n%ld\n%ld erf2"
START_TEST(test_num2_alphas_spaces)
{
    int rc, rc_my;
    long int num1 = -21;
    long int num2 = 345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "\n%ld\n%ld erf2", num1, num2);
    rc = snprintf(buffer, sizeof(buffer), "\n%ld\n%ld erf2", num1, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

// числа и строки
//- 13 - " %s %ld "
START_TEST(test_num_str_spaces_str_num)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), " %s %ld ", strk, num);
    rc = snprintf(buffer, sizeof(buffer), " %s %ld ", strk, num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 14 - " %ld %s\n"
START_TEST(test_num_str_spaces_num_str)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), " %ld %s\n", num, strk);
    rc = snprintf(buffer, sizeof(buffer), " %ld %s\n", num, strk);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 15 - "%s%ld"
START_TEST(test_num_str_solid_str_num)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%s%ld", strk, num);
    rc = snprintf(buffer, sizeof(buffer), "%s%ld", strk, num);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 16 - "%ld%s"
START_TEST(test_num_str_solid_num_str)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%ld%s", num, strk);
    rc = snprintf(buffer, sizeof(buffer), "%ld%s", num, strk);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 17 - "\n%ld %s %ld "
START_TEST(test_num_str_spaces_num_str_num)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    long int num1 = -345, num2 = 2007;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "\n%ld %s %ld ", num1, strk, num2);
    rc = snprintf(buffer, sizeof(buffer), "\n%ld %s %ld ", num1, strk, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 18 - "%s %ld\n%s\n"
START_TEST(test_num_str_spaces_str_num_str)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!", strk2[] = " I'm coming)";
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "%s %ld\n%s\n", strk1, num, strk2);
    rc = snprintf(buffer, sizeof(buffer), "%s %ld\n%s\n", strk1, num, strk2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 19 - "a%sbc%ldcds%s erf%ld2"
START_TEST(test_num_str_alpha_str_num_str_num)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!", strk2[] = " I'm coming)";
    long int num1 = -345, num2 = 2;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "a%sbc%ldcds%s erf%ld2", strk1, num1, strk2, num2);
    rc = snprintf(buffer, sizeof(buffer), "a%sbc%ldcds%s erf%ld2", strk1, num1, strk2, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 20 - "%ld%s\n%ld\n%s erf2"
START_TEST(test_num_str_alpha_num_str_num_str)
{
    int rc, rc_my;
    char strk1[] = "Hello, World!", strk2[] = " I'm coming)";
    long int num1 = -345, num2 = 2;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "a%sbc%ldcds%s erf%ld2", strk1, num1, strk2, num2);
    rc = snprintf(buffer, sizeof(buffer), "a%sbc%ldcds%s erf%ld2", strk1, num1, strk2, num2);
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

//- 21 - в строке форматирования нет вставок
START_TEST(test_no_proc)
{
    int rc, rc_my;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, sizeof(buffer_my), "a34edt \ns bcSewredrfcty!cds    erf hd 2");
    rc = snprintf(buffer, sizeof(buffer), "a34edt \ns bcSewredrfcty!cds    erf hd 2");
    ck_assert_str_eq(buffer, buffer_my);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

// neg tests
//- 01 - строка в буфер не влазит
START_TEST(test_str_few_size)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, strlen(strk) - 3, "%s", strk);
    rc = snprintf(buffer, strlen(strk) - 3, "%s", strk);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST
//- 02 - число в буфер не влазит
START_TEST(test_num_few_size)
{
    int rc, rc_my;
    long int num = -1234115;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, 3, "%ld", num);
    rc = snprintf(buffer, 3, "%ld", num);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST
//- 03 - строка и число в буфер не влазят
START_TEST(test_num_str_few_buf)
{
    int rc, rc_my;
    char strk[] = "Hello, World!";
    long int num = -345;
    char buffer[SIZE_OF_BUF], buffer_my[SIZE_OF_BUF];
    rc_my = my_snprintf(buffer_my, strlen(strk), "%ld%s", num, strk);
    rc = snprintf(buffer, strlen(strk), "%ld%s", num, strk);
    ck_assert_int_eq(rc, rc_my);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    // Создадим тестовый набор для тестирования функций
    s = suite_create("my_snprintf");

    // Создадим тестовый случай из функций-тестов
    tc_pos = tcase_create("pos_tests");
    tc_neg = tcase_create("neg_tests");
    // Добавим соответствующие функции-тесты

    // pos_tests

    //только строки
    //- 01 - "%s"
    tcase_add_test(tc_pos, test_str_only);
    //- 02 - " %s "
    tcase_add_test(tc_pos, test_str_spaces);
    //- 03 - "%s%s"
    tcase_add_test(tc_pos, test_str2_solid);
    //- 04 - " %s %s\n"
    tcase_add_test(tc_pos, test_str2_spaces);
    //- 05 - "abc%scds%s erf2"
    tcase_add_test(tc_pos, test_str2_alphas);
    //- 06 - "\n%s\n%s erf2"
    tcase_add_test(tc_pos, test_str2_alphas_spaces);

    // только числа
    //- 07.1 - "%ld" (положительное число)
    tcase_add_test(tc_pos, test_num_only_pos);
    //- 07.2 - "%ld" (отрицательное число)
    tcase_add_test(tc_pos, test_num_only_neg);
    //- 07.3 - "%ld" (нуль)
    tcase_add_test(tc_pos, test_num_only_zero);
    //- 07.4 - "%ld" (max)
    tcase_add_test(tc_pos, test_num_max);
    //- 07.5 - "%ld" (min)
    tcase_add_test(tc_pos, test_num_min);
    //- 08 - " %ld "
    tcase_add_test(tc_pos, test_num_spaces);
    //- 09.1 - "%ld%ld" (положительные числа)
    tcase_add_test(tc_pos, test_num2_solid_pos);
    //- 09.2 - "%ld%ld" (отрицательные числа)
    tcase_add_test(tc_pos, test_num2_solid_neg);
    //- 09.3 - "%ld%ld" (положительное и отрицательное числа)
    tcase_add_test(tc_pos, test_num2_solid_pos_neg);
    //- 09.4 - "%ld%ld" (отрицательное и положительное числа)
    tcase_add_test(tc_pos, test_num2_solid_neg_pos);
    //- 10 - " %ld %ld\n"
    tcase_add_test(tc_pos, test_num2_spaces);
    //- 11 - "abc%ldcds%ld erf2"
    tcase_add_test(tc_pos, test_num2_alphas);
    //- 12 - "\n%ld\n%ld erf2"
    tcase_add_test(tc_pos, test_num2_alphas_spaces);

    // числа и строки
    //- 13 - " %s %ld "
    tcase_add_test(tc_pos, test_num_str_spaces_str_num);
    //- 14 - " %ld %s\n"
    tcase_add_test(tc_pos, test_num_str_spaces_num_str);
    //- 15 - "%s%ld"
    tcase_add_test(tc_pos, test_num_str_solid_str_num);
    //- 16 - "%ld%s"
    tcase_add_test(tc_pos, test_num_str_solid_num_str);
    //- 17 - "\n%ld %s %ld "
    tcase_add_test(tc_pos, test_num_str_spaces_num_str_num);
    //- 18 - "%s %ld\n%s\n"
    tcase_add_test(tc_pos, test_num_str_spaces_str_num_str);
    //- 19 - "a%sbc%ldcds%s erf%ld2"
    tcase_add_test(tc_pos, test_num_str_alpha_str_num_str_num);
    //- 20 - "%ld%s\n%ld\n%s erf2"
    tcase_add_test(tc_pos, test_num_str_alpha_num_str_num_str);

    //- 21 - в строке форматирования нет вставок
    tcase_add_test(tc_pos, test_no_proc);

    // neg tests
    //- 01 - строка в буфер не влазит
    tcase_add_test(tc_neg, test_str_few_size);
    //- 02 - число в буфер не влазит
    tcase_add_test(tc_neg, test_num_few_size);
    //- 03 - строка и число в буфер не влазят
    tcase_add_test(tc_neg, test_num_str_few_buf);

    // Добавим сформированные тестовые случаи в тестовый набор
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}