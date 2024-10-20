#include "do_s.h"

int get_number_by_pos(FILE *file, long int i)
{
    int x;
    fseek(file, i * sizeof(int), SEEK_SET);
    fread(&x, sizeof(int), 1, file);
    return x;
}

void put_number_by_pos(FILE *file, long int i, int x)
{
    fseek(file, i * sizeof(int), SEEK_SET);
    fwrite(&x, sizeof(int), 1, file);
}

int do_s(FILE *file)
{
    int x;
    int y;
    int flag;
    long int n = 0;

    while (fread(&x, sizeof(int), 1, file) == 1)
        n++;

    if (n == 0)
        return EMPTY;

    if (! feof(file))
        return NOT_NUM;

    for (long int i = 0; i < (n - 1); i++)
    {
        flag = 1;
        for (long int j = 0; j < (n - 1); j++)
            if ((x = get_number_by_pos(file, j)) > (y = get_number_by_pos(file, j + 1)))
            {
                flag = 0;
                put_number_by_pos(file, j + 1, x);
                put_number_by_pos(file, j, y);
            }
        if (flag)
            break;
    }

    return OK;
}
