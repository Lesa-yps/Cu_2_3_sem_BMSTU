#define _POSIX_C_SOURCE 200809L

#include "print_arr.h"
#include "const_struct.h"
#include "work_with_mem.h"
#include <check.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// вывод массива в файл
// void print_arr(FILE *file, struct film *films, int n);

int read_str_for_check(char **data, FILE *f)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, f);
    if (nread == -1)
    {
        free(line);
        line = NULL;
        return ERROR;
    }
    if (line[nread - 1] == '\n')
    {
        line[nread - 1] = '\0';
        nread--;
    }
    if (nread == 0)
    {
        free(line);
        line = NULL;
        return ERROR;
    }

    *data = line;

    return OK;
}

// чтение структуры фильм
static int read_film(struct film *x, FILE *file)
{
    int ok1 = read_str_for_check(&x->title, file);
    int ok2 = read_str_for_check(&x->name, file);
    int ok3 = fscanf(file, "%d", &x->year);
    char tmp[2];
    fgets(tmp, sizeof(tmp), file);
    if (ok1 || ok2 || ok3)
        return ERROR;
    return OK;
}
// сравнение структур-фильмов
static int cmp_film(struct film a, struct film b)
{
    if ((strcmp(a.name, b.name) == 0) && (strcmp(a.title, b.title) == 0) && (a.year == b.year))
        return OK;
    return ERROR;
}

// tests

START_TEST(test_print_arr)
{
    FILE *file;
    struct film films[3] = {{.title = "Lord of Rings", .name = "Tolkien", .year = 1887},
                            {.title = "King Lion", .name = "Who is know?", .year = 2004},
                            {.title = "Fish-girl", .name = "Andersen", .year = 1902}};
    size_t n = 3;
    size_t i = 0;
    struct film x;
    file = fopen("file.txt", "w");
    // вывод массива в файл
    print_arr(file, films, n);
    fclose(file);
    file = fopen("file.txt", "r");
    int rc = ERROR;
    while (((rc = read_film(&x, file)) == OK) && (i < n))
    {
        ck_assert_int_eq(cmp_film(x, films[i]), OK);
        free_one(&x);
        i++;
    }
    free_one(&x);
    ck_assert_int_eq(rc, ERROR);
    fclose(file);
}
END_TEST

// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite *print_arr_suite(void)
{
    Suite *s;
    TCase *tc_all;

    // Создадим тестовый набор для тестирования функции print_arr
    s = suite_create("print_arr");

    // Создадим тестовый случай из функций-тестов, которые проверяют вызов print_arr
    tc_all = tcase_create("all_tests");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_all, test_print_arr);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_all);

    return s;
}
