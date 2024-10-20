#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

//коды возврата
#define OK 0

#define ERROR 1
#define MY_ERROR -1

//нумерация переданных аргументов
#define FILE_NAME 1
#define PLACE 2
#define FIND_PLACE 3

//максимальная длина строки
#define MAX_LEN 25 + 1
//максимальное количество структур
#define MAX_COUNT 15

//минимальное количество аргументов командной строки (без фильтрации)
#define MIN_COUNT_ARGS 3
//максимальное количество аргументов командной строки (с фильтрацией)
#define MAX_COUNT_ARGS 4

//структура
struct film
{
    char title[MAX_LEN];
    char name[MAX_LEN];
    int year;
};

#endif // CONST_STRUCT_H
