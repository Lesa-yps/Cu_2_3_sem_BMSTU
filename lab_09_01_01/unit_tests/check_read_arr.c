#include "read_arr.h"
#include "const_struct.h"
#include "work_with_mem.h"
#include <check.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// функция читает информацию о фильмах из файла
// int read_arr(FILE *file, struct film **films, size_t *n, char *what);

// pos tests

START_TEST(test_read_arr_year)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    struct film films_sort[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                                 {.title = "Fish-girl", .name = "Andersen", .year = 1902},
                                 {.title = "King Lion", .name = "Who is know?", .year = 2004}};
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "year";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n == n_read, 1);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(((strcmp((films_sort[i]).name, (films_read[i]).name) == 0) &&
                          (strcmp((films_sort[i]).title, (films_read[i]).title) == 0) && ((films_sort[i]).year == (films_read[i]).year)),
                         1);
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
}
END_TEST

START_TEST(test_read_arr_title)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    struct film films_sort[3] = {
        {.title = "Fish-girl", .name = "Andersen", .year = 1902},
        {.title = "King Lion", .name = "Who is know?", .year = 2004},
        {.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
    };
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "title";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n == n_read, 1);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_int_eq(strncmp(films_sort[i].name, films_read[i].name, strlen(films_sort[i].name)), 0);
        ck_assert_int_eq(strncmp((films_sort[i]).title, (films_read[i]).title, strlen(films_sort[i].title)), 0);
        ck_assert_int_eq(films_sort[i].year, (films_read[i]).year);
    }
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
}
END_TEST

START_TEST(test_read_arr_name)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    struct film films_sort[3] = {{.title = "Fish-girl", .name = "Andersen", .year = 1902},
                                 {.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                                 {.title = "King Lion", .name = "Who is know?", .year = 2004}};
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "name";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n == n_read, 1);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_int_eq(strncmp(films_sort[i].name, films_read[i].name, strlen(films_sort[i].name)), 0);
        ck_assert_int_eq(strncmp((films_sort[i]).title, (films_read[i]).title, strlen(films_sort[i].title)), 0);
        ck_assert_int_eq(films_sort[i].year, (films_read[i]).year);
    }
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
}
END_TEST

// neg tests

START_TEST(test_read_arr_error_eof)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "name";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
    fprintf(file, "\n\n");
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_arr_neg_year)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = -2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "name";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_arr_float_year)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "name";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
    {
        fprintf(file, "%s\n%s\n", (films[i]).title, (films[i]).name);
        if (i < (n - 1))
            fprintf(file, "%d\n", (films[i]).year);
    }
    fprintf(file, "34.657\n");
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(test_read_arr_empty_str)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "", .year = 1902}};
    size_t n = 3;
    int rc;
    struct film *films_read;
    size_t n_read;
    char *what = "name";
    file = fopen("file.txt", "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%s\n%s\n%d\n", (films[i]).title, (films[i]).name, (films[i]).year);
    fclose(file);
    file = fopen("file.txt", "r");
    // функция читает и сортирует массив
    rc = read_arr(file, &films_read, &n_read, what);
    if (rc == OK)
        free_arr(films_read, n_read);
    fclose(file);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite *read_arr_suite(void)
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
    tcase_add_test(tc_neg, test_read_arr_neg_year);
    tcase_add_test(tc_neg, test_read_arr_float_year);
    tcase_add_test(tc_neg, test_read_arr_error_eof);
    tcase_add_test(tc_neg, test_read_arr_empty_str);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // read_arr для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_read_arr_title);
    tcase_add_test(tc_pos, test_read_arr_name);
    tcase_add_test(tc_pos, test_read_arr_year);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
