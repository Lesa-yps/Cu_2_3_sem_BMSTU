#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

//коды возврата
#define OK 0

#define ERROR 1
#define FIN_READ 3
#define MY_ERROR -1
#define ERR_MEM 7

//нумерация переданных аргументов
#define FILE_NAME 1
#define PLACE 2
#define FIND_PLACE 3

//структура
struct film
{
    char *title;
    char *name;
    int year;
};

#endif // CONST_STRUCT_H
