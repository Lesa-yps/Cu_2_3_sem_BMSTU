#include "find_key.h"

//функция сравнивает переданную структуру с искомой строкой по переданному полю
int find_strcmp(char *what, struct film film1, char *key);

//бинарный поиск
int find_key(struct film *films, int n, char *what, char *key, int *res)
{
    //проверка на корректность поля поиска
    if ((strcmp(what, "title") * strcmp(what, "name") * strcmp(what, "year")) != 0)
        return ERROR;

    //результат
    *res = -1;
    //код ошибки
    int rc = OK;
    //левая граница
    int left = 0;
    //правая граница
    int right = n - 1;
    //середина
    int middle;
    //пока границы не пересеклись
    while ((right >= left) && (*res == -1))
    {
        //вычисляем середину
        middle = left + (right - left) / 2;
        //если нашли элемент, возвращаем его индекс
        if (find_strcmp(what, films[middle], key) == 0)
            *res = middle;
        //если середина больше искомого, сдвигаем правую границу
        else if (find_strcmp(what, films[middle], key) > 0)
            right = middle - 1;
        //если середина меньше искомого, сдвигаем левуую границу
        else
            left = middle + 1;
    }
    //если границы пересеклись, то искомого элемента нет
    if (*res == -1)
        rc = MY_ERROR;
    //возврат кода ошибки
    return rc;
}

//функция сравнивает переданную структуру с искомой строкой по переданному полю
int find_strcmp(char *what, struct film film1, char *key)
{
    int res = 0;
    if (strcmp(what, "title") == 0)
        res = strcmp(film1.title, key);
    if (strcmp(what, "name") == 0)
        res = strcmp(film1.name, key);
    if (strcmp(what, "year") == 0)
        res = film1.year - strtol(key, NULL, 10);
    return res;
}
