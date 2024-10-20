#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

//коды возврата
#define OK 0
#define ERROR 1

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

//структура
struct this_day
{
    int day;
    int month;
    int year;
};

#endif // CONST_STRUCT_H
