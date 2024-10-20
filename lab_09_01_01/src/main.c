#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

// подключение моих модулей-функций
#include "const_struct.h"
#include "read_arr.h"
#include "print_arr.h"
#include "find_key.h"
#include "work_with_mem.h"

// проверка на корректность искомого года
int check_year(char *strk);

// вызывает соответствующую функцию в зависимости от количества аргументов и обрабатывает результат
int controller(int argc, char **argv, struct film *films, size_t n);

int main(int argc, char **argv)
{
    FILE *file;
    // массив хранит все фильмы из файла
    struct film *films = NULL;
    // количество элементов в массиве
    size_t n = 0;
    // код ошибки программы
    int rc = OK;
    //printf("проверка аргументов\n");
    // проверка на количество переданных аргументов
    if (argc < FIND_PLACE || argc > (FIND_PLACE  + 1))
        rc = ERROR;
    // проверка на корректность поля поиска
    else if ((strcmp(argv[PLACE], "title") * strcmp(argv[PLACE], "name") * strcmp(argv[PLACE], "year")) != 0)
        rc = ERROR;
    else
    {
        //printf("открытие файла и его проверка\n");
        // открытие файла и его проверка
        file = fopen(argv[FILE_NAME], "rt");
        if (file == NULL)
            rc = ERROR;
        // чтение файла в массив и попутная сортировка массива при вставке КАЖДОГО элемента + проверка на всякие ошибки
        else
        {
            //printf("чтение файла и опять грёбаная проверка\n");
            if ((rc = read_arr(file, &films, &n, argv[PLACE])) == OK)
            {
                //printf("48 films[n].title = %s films[n].name = %s films[n].year = %d films[%d]\n", (films[0]).title, (films[0]).name, (films[0]).year, 0);
                //printf("успешно прочитали - ушли в контроллер\n");
                // вызывает соответствующую функцию в зависимости от количества аргументов и обрабатывает результат
                rc = controller(argc, argv, films, n);
                //printf("освободили масиив\n");
                free_arr(films, n);
            }
            fclose(file);
        }
    }
    //printf("Итого rc = %d\n", rc);
    // возврат кода ошибки
    return rc;
}

// проверка на корректность искомого года
int check_year(char *strk)
{
    // код возврата
    int rc = OK;
    size_t i = 0;
    // если плюс - пропускаем его
    if (strk[0] == '+')
        i = 1;
    // проходимся по длине переданной строки и проверяем, что все элементы в ней цифры
    for (; (i < strlen(strk)) && (!rc); i++)
        // если встретилась не цифра, возвращаем ошибку
        if ((strk[i] > '9') || (strk[i] < '0'))
            rc = ERROR;
    // возвращаем код ошибки
    return rc;
}

// вызывает соответствующую функцию в зависимости от количества аргументов и обрабатывает результат
int controller(int argc, char **argv, struct film *films, size_t n)
{
    // код ошибки
    int rc = OK;
    int rc2;
    // результат поиска элемента (индекс), если поиск будет
    int res;
    // вывод отсортированного массива, если не указан искомый элемент
    if (argc == 3)
        print_arr(stdout, films, n);
    // если указан искомый элемент, вызывается функция поиска, возвращающая индекс или -1 при его отсутствии
    else
    {
        // проверка искомого года, если ищется год
        if ((strcmp(argv[PLACE], "year") == 0) && (check_year(argv[FIND_PLACE]) == ERROR))
            rc = ERROR;
        else
        {
            // сам поиск
            rc2 = find_key(films, n, argv[PLACE], argv[FIND_PLACE], &res);
            // если поле поиска неверное - ошибка
            if (rc2 == ERROR)
                rc = ERROR;
            // не найден => вывод сообщения об этом
            else if (rc2 == MY_ERROR)
                fprintf(stdout, "Not found\n");
            // найден => вывод информации об искомом фильме
            else
                fprintf(stdout, "%s\n%s\n%d\n", (films[res]).title, (films[res]).name, (films[res]).year);
        }
    }
    // возврат кода ошибки
    return rc;
}


