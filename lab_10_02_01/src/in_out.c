#include "in_out.h"

int read_pair(FILE *file, int *coef, int *deg);

// чтение полинома
int read_polyn(FILE *file, node_t **head)
{
    int flag = 0;
    int fin = 1;
    int rc = OK;
    int rc_scanf = OK;
    int coef;
    int deg;
    int deg_old;
    *head = NULL;
    node_t *cursor;
    //printf("cur = %p head = %p", (void *) *head, (void *) cursor);
    //printf("Введите полином в формате 'коэффициент1 число1 коэффициент2 число2 ...':\n");

    // Считываем строку с полиномом
    while (fin && (rc_scanf = read_pair(file, &coef, &deg)) != ERROR && (rc_scanf != END_OF_STR_NOW))
    {
        //printf("rc_scanf = %d\n", rc_scanf);
        if (flag)
        {
            //printf("old = %d deg = %d\n", deg_old, deg);
            if (deg_old < deg)
                rc = ERROR;
        }
        if (rc == OK)
        {
            deg_old = deg;
            rc = create_one(&cursor, coef, deg);
            //printf("1 = %d = %d 2 = %d = %d head = %p cur = %p\n", ((struct elem *)(cursor->data))->coefficient, coef, ((struct elem *)(cursor->data))->degree, deg, (void *) *head, (void *) cursor);
            //sleep(3);
            if (rc == ERROR)
            {
                //printf("free head\n");
                free_all(head);
            }
            else
                insert(head, cursor, NULL);
        }
        flag = 1;
        if (rc_scanf == END_OF_STR)
            fin = 0;
    }
    if ((! flag) || (rc_scanf == ERROR))
    {
        rc = ERROR;
        if (rc_scanf == ERROR)
            free_all(head);
    }
    //printf("free buffer rc = %d\n", rc);
    return rc;
}

// вывод членов многочлена
void print_polyn(node_t *head)
{
    if (head != NULL)
    {        
        node_t *cursor = head;
        struct elem *elem1;
        while (cursor != NULL)
        {
            elem1 = (struct elem*) cursor->data;
            printf("%d %d ", elem1->coefficient, elem1->degree);
            cursor = cursor->next;
        }
        printf("L\n");
    }
}

//чтение числа
int read_int(FILE *file, int *num)
{
    int rc = OK;
    int minus = 1;
    //прочитали символ
    char a = fgetc(file);
    while (a == ' ')
        a = fgetc(file);
    if (a == '-')
    {
        minus = -1;
        a = fgetc(file);
    }
    else if (a == '+')
        a = fgetc(file);
    //обозначает что хоть одну цифру прочитали
    int flag = 1;
    *num = 0;
    // пока символ - цифра
    while (isdigit(a))
    {
        flag = 0;
        //добавляем её к числу
        *num = (a - '0') + *num * 10;
        //считали символ
        a = fgetc(file);
    }
    *num *= minus;
    //если не прочитали ни одной цифры или последний считанный символ - не конец файла или перевод строки или пробел - ошибка
    if (flag || (! ((a == '\n') || (a == EOF) || (a == ' '))))
        rc = ERROR;
    else if ((a == '\n') || (a == EOF))
        rc = END_OF_STR;
    //вернули код ошибки
    return rc;
}

int read_pair(FILE *file, int *coef, int *deg)
{
    int rc = read_int(file, coef);
    if (rc == END_OF_STR)
        rc = END_OF_STR_NOW;
    if (rc == OK)
        rc = read_int(file, deg);
    return rc;
}
