#include "find_key.h"
#include <check.h>
#include "const_struct.h"
#include <stddef.h>

// бинарный поиск элемента, возвращает индекс или MY_ERROR (если не найден)
// int find_key(struct film *films, size_t n, char *what, char *key, int *res);

// pos tests

START_TEST(test_find_key_year)
{
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},\
    {.title = "Fish-girl", .name = "Andersen", .year = 1902},\
    {.title = "King Lion", .name = "Who is know?", .year = 2004}};
    size_t n = 3;
    int rc;
    int right_ind = 1;
    int ind;
    char *key = "1902";
    char *what = "year";
    // бинарный поиск элемента, возвращает индекс или MY_ERROR (если не найден)
    rc = find_key(films, n, what, key, &ind);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(ind, right_ind);
}
END_TEST

START_TEST(test_find_key_name)
{
    struct film films[3] = {{.title = "Fish-girl", .name = "Andersen", .year = 1902},\
    {.title = "Lord of Rings", .name = "Tolkien", .year = 1887},\
    {.title = "King Lion", .name = "Who is know?", .year = 2004}};
    size_t n = 3;
    int rc;
    size_t right_ind = 2;
    int ind;
    char *key = "Who is know?";
    char *what = "name";
    // бинарный поиск элемента, возвращает индекс или MY_ERROR (если не найден)
    rc = find_key(films, n, what, key, &ind);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(ind, right_ind);
}
END_TEST

START_TEST(test_find_key_title)
{
    struct film films[3] = {{.title = "King Lion", .name = "Who is know?", .year = 2004},\
    {.title = "Lord of Rings", .name = "Tolkien", .year = 1887},\
    {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    size_t n = 3;
    int rc;
    size_t right_ind = 0;
    int ind;
    char *key = "King Lion";
    char *what = "title";
    // бинарный поиск элемента, возвращает индекс или MY_ERROR (если не найден)
    rc = find_key(films, n, what, key, &ind);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(ind, right_ind);
}
END_TEST

START_TEST(test_find_key_not_found)
{
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},\
    {.title = "Fish-girl", .name = "Andersen", .year = 1902},\
    {.title = "King Lion", .name = "Who is know?", .year = 2004}};
    size_t n = 3;
    int rc;
    int ind;
    char *key = "1912";
    char *what = "year";
    // бинарный поиск элемента, возвращает индекс или MY_ERROR (если не найден)
    rc = find_key(films, n, what, key, &ind);
    ck_assert_int_eq(rc, MY_ERROR);
}
END_TEST

// neg tests

START_TEST(test_find_key_error_place)
{
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},\
    {.title = "Fish-girl", .name = "Andersen", .year = 1902},\
    {.title = "King Lion", .name = "Who is know?", .year = 2004}};
    size_t n = 3;
    int rc;
    int ind;
    char *key = "1902";
    char *what = "yeat";
    // бинарный поиск элемента, возвращает индекс или MY_ERROR (если не найден)
    rc = find_key(films, n, what, key, &ind);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite* find_key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции find_key
    s = suite_create("find_key");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове find_key
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_find_key_error_place);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // find_key для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_find_key_name);
    tcase_add_test(tc_pos, test_find_key_title);
    tcase_add_test(tc_pos, test_find_key_year);
    tcase_add_test(tc_pos, test_find_key_not_found);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
