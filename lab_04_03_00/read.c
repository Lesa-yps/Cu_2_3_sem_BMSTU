#include "read.h"

//reading strings
int reading(char arr_str[])
{
    printf("Input string:\n");
    if (!fgets(arr_str, MAX_LEN_STR + 1, stdin) || arr_str[0] == '\n')
        return ERR;
    if (arr_str[strlen(arr_str) - 1] != '\n')
        return ERR_LEN_STR;
    return OK;
}
