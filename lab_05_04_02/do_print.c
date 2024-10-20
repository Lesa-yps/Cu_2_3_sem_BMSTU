#include "do_print.h"

/*void print(FILE *file)
{
    printf("Vot:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fread(&x, sizeof(struct tovar), 1, file) == 1)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

int do_print(FILE *file_in, char under_str[])
{
    struct tovar x;
    int flag = 1;
    int len_str;
    int len_under = strlen(under_str);

    while (fread(&x, sizeof(struct tovar), 1, file_in) == 1)
    {
        len_str = strlen(x.name);
        //printf("%s %s\n", x.name + len_str - len_under, under_str);
        if (strstr(x.name + len_str - len_under, under_str))
        {
            if (flag)
            {
                printf("Result:\n");
                flag = 0;
            }
            printf("%s\n%s\n%u\n%u\n", x.name, x.maker, x.price, x.count);
        }
    }
    if (flag)
        return EMPTY;
    return OK;
}
