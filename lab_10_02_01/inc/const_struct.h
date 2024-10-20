#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

//коды возврата
#define OK 0
#define ERROR 1

#define SIZE_OF_STRK 5

#define END_OF_STR 3
#define END_OF_STR_NOW 4

typedef struct node node_t;

// структура - элемент односвязного списка
struct node
{
    // указатель на данные
    void *data;
    // указатель на следующий элемент
    node_t *next;
};

// структура - данные об элементе полинома
struct elem
{
    // коэффициент
    int coefficient;
    // степень
    int degree;
};

#endif // CONST_STRUCT_H
