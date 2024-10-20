#include <stdio.h>

#include "const.h"
#include "process.h"

/**
 * @file main.c
 * @brief Главный файл программы.
 */

int main(void)
{
    long long int count;

    if (process(stdin, &count) == EMPTY)
    {
        printf("Error: empty sequence.\n");
        return EMPTY;
    }
    printf("Result: %lld\n", count);
    return OK;
}

