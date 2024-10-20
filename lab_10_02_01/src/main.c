#include <stdio.h>
#include <string.h>

// подключение внутренних модулей-функций
#include "const_struct.h"

#include "calc_a.h"
#include "differ.h"
#include "sum_2_lists.h"
#include "diff_even_odd.h"

// вызывает соответствующую функцию в зависимости от количества аргументов и обрабатывает результат
int controller();
// читает одну из конкретных строк из задания
int read_str(char *strk);

int main(void)
{
    // код ошибки программы
    int rc = OK;
    char strk[SIZE_OF_STRK] = "\0\0\0\0";
    // читаем что делать
    //printf("val|dxx|sum|dvd: ");
    rc = read_str(strk);
    if (rc == OK)
        // вызывает соответствующую функцию в зависимости от значения строки
        rc = controller(strk);
    //printf("Итого rc = %d\n", rc);
    // возврат кода ошибки
    return rc;
}

// вызывает соответствующую функцию в зависимости от значения строки
int controller(char *str)
{
    // код ошибки
    int rc = OK;
    // вычисляет полином для переданного значения
    if (strcmp(str, "val") == OK)
        rc = calc_a();
    // находит производную полинома
    else if (strcmp(str, "ddx") == OK)
        rc = differ();
    // складывает два полинома
    else if (strcmp(str, "sum") == OK)
        rc = sum_2_lists();
    // разделяет полином на чётные/нечётные степени
    else
        rc = diff_even_odd();
    // возврат кода ошибки
    return rc;
}

// читает одну из конкретных строк из задания
int read_str(char *strk)
{
    int rc = OK;
    if (fgets(strk, SIZE_OF_STRK * sizeof(char), stdin) == NULL)
        rc = ERROR;
    else
    {
        //printf("!%s!", strk);
        if (strk[strlen(strk) - 1] != '\n')
            rc = ERROR;
        else
        {
            strk[strlen(strk) - 1] = '\0';
            if (strcmp(strk, "val") != 0 && strcmp(strk, "ddx") != 0 && strcmp(strk, "sum") != 0 && strcmp(strk, "dvd") != 0)
                rc = ERROR;
        }
    }
    return rc;
}
