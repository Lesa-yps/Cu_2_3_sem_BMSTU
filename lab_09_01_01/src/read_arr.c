#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include "read_arr.h"
#include "work_with_mem.h"

// чтение года
int read_year(FILE *file, int *year);
// чтение строки
int read_str(char *str, FILE *file);
// вставка элемента на нужное место в массиве (сортировка после ввода каждого элемента)
static int input_sort(size_t n, char *what, struct film *one, struct film *films, int len_str);
// чтение структуры об одном фильме и выделение под него памяти
int read_one(struct film *one, FILE *file, int len_str);
// читает количество фильмов-структур в файле
int find_count_films(size_t *n, FILE *file, int len_str);
// обмен структур
int swap(struct film *one, struct film *two, int len_str);
// находит максимальную длину строки
int find_max_len_str(FILE *file);

// функция читает информацию о фильмах из файла
int read_arr(FILE *file, struct film **films, size_t *n, char *what)
{
    struct film one;
    // ищем максимальную строку в файле
    int len_str = find_max_len_str(file);
    // считакм количество фильмов в файле
    int rc = find_count_films(n, file, len_str);
    if (rc == OK)
    {
        // создаём масcив
        rc = create_arr(films, *n, len_str);
        if (rc == OK)
            for (size_t i = 0; i < *n && !rc; i++)
            {
                // читаем фильмы по одному
                read_one(&one, file, len_str);
                // сортируем фильмы по одному
                rc = input_sort(i, what, &one, *films, len_str);
                // освобождаем временную переменную
                free_one(&one);
            }
        else
            rc = ERROR;
    }
    // вернули код ошибки
    return rc;
}

// чтение года
int read_year(FILE *file, int *year)
{
    int rc = OK;
    // прочитали символ
    char a = fgetc(file);
    // обозначает что хоть одну цифру прочитали
    int flag = 1;
    *year = 0;
    // пока символ - цифра
    while (isdigit(a))
    {
        flag = 0;
        // добавляем её к году
        *year = (a - '0') + *year * 10;
        // считали символ
        a = fgetc(file);
    }
    // если не прочитали ни одной цифры или последний считанный символ - не конец файла или перевод строки - ошибка
    if (flag || (!((a == '\n') || (a == EOF))))
        rc = ERROR;
    // вернули код ошибки
    return rc;
}

// чтение строки
int read_str(char *str, FILE *file)
{
    // код ошибки
    int rc = OK;
    char a;
    size_t i = 0;
    // если не конец файла, иначе код возврата MY_ERROR
    while (((a = fgetc(file)) != EOF) && (a != '\n'))
    {
        str[i] = a;
        i++;
    }
    str[i] = '\0';
    if (i == 0)
        rc = ERROR;
    // вернули код ошибки
    return rc;
}

// считает количество символов в строке
int read_count_chars(FILE *file)
{
    int count = 0;
    char a = fgetc(file);
    while (a != '\n' && a != EOF)
    {
        a = fgetc(file);
        count++;
    }
    return count + 1;
}

// находит максимальную длину строки
int find_max_len_str(FILE *file)
{
    int maxi = 0;
    int count;
    while (!feof(file))
    {
        count = read_count_chars(file);
        if (count > maxi)
            maxi = count;
    }
    fseek(file, 0, SEEK_SET);
    return maxi;
}

// чтение структуры об одном фильме и выделение под него памяти
int read_one(struct film *one, FILE *file, int len_str)
{
    int rc = create_one(one, len_str);
    if (rc == OK)
    {
        // чтение названия
        rc = read_str(one->title, file);
        if (rc == ERROR)
            rc = FIN_READ;
        else if (rc == OK)
        {
            // чтение имени автора
            rc = read_str(one->name, file);
            if (rc == OK)
            {
                // чтение года
                rc = read_year(file, &one->year);
            }
        }
    }
    return rc;
}

// читает количество фильмов-структур в файле
int find_count_films(size_t *n, FILE *file, int len_str)
{
    int rc = OK;
    struct film one;
    *n = 0;
    while ((rc = read_one(&one, file, len_str)) == OK)
    {
        (*n)++;
        free_one(&one);
    }
    if (rc != ERR_MEM)
    {
        if (rc == FIN_READ)
        {
            if ((*n) == 0)
                rc = ERROR;
            else
                rc = OK;
        }
        free_one(&one);
    }
    else
        rc = ERROR;
    if (fgetc(file) == '\n')
        rc = ERROR;
    fseek(file, 0, SEEK_SET);
    return rc;
}

// скопирует данные из второй структуры в первую
void copy_one_to(struct film *one, struct film *two)
{
    strcpy(one->name, two->name);
    strcpy(one->title, two->title);
    one->year = two->year;
}

// функция сравнивает переданные структуры по переданному полю
// работает аналогично strcmp
int struct_strcmp(char *what, struct film film1, struct film film2)
{
    int res = 0;
    if (strcmp(what, "title") == 0)
        res = strcmp(film1.title, film2.title);
    if (strcmp(what, "name") == 0)
        res = strcmp(film1.name, film2.name);
    if (strcmp(what, "year") == 0)
        res = film1.year - film2.year;
    return res;
}

// вставляем считанный элемент на верное место в массив (сортировка)
// пример: 6
// 1 2 3 5 6
// 1. 1 2 3 4 6
// 2. 1 2 3 4 5
// 3. 1 2 3 4 5 6
static int input_sort(size_t n, char *what, struct film *one, struct film *films, int len_str)
{
    int rc = OK;
    for (size_t j = 0; j < n && !rc; j++)
    {
        // доходим до первого элемента большего вставляемого и вставляем, а остальные элементы массива сдвигаем на 1 вправо
        if (struct_strcmp(what, *one, films[j]) < 0)
            rc = swap(one, films + j, len_str);
    }
    if (rc == OK)
        copy_one_to(&(films[n]), one);
    return rc;
}

// обмен структур
int swap(struct film *one, struct film *two, int len_str)
{
    struct film help;
    int rc = create_one(&help, len_str);
    if (rc == OK)
    {
        copy_one_to(&help, one);
        copy_one_to(one, two);
        copy_one_to(two, &help);
        free_one(&help);
    }
    else
        rc = ERROR;
    return rc;
}
