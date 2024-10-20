#include "do_c.h"

int str_to_num(char num[], long int *n)
{
    long int lena = strlen(num);

    for (long int i = 0; i < lena; i++)
        if (num[i] < '0' || num[i] > '9')
            return NOT_NUM;

    *n = atoi(num);

    return OK;
}

int do_c(FILE *file, char num[])
{
    int x;
    long int n;
    if (str_to_num(num, &n) == NOT_NUM)
        return NOT_NUM;
    srand(time(NULL));
    for (long int i = 0; i < n; i++)
    {
        x = (rand() % (MAX - MIN + 1)) + MIN;
        fwrite(&x, sizeof(int), 1, file);
    }
    return OK;
}
