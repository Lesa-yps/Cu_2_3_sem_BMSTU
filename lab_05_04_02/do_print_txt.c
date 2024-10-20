#include "do_print_txt.h"

/*void print_txt(FILE *file)
{
    printf("Vot_txt:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s%s%u%u", x.name, x.maker, &(x.price), &(x.count)) == 4)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

int do_print_txt(FILE *file_in, char under_str[])
{
    struct tovar arr[MAX_STRUCT];
    int flag = 1;
    int len_str;
    long int i = 0;
    int len_under = strlen(under_str);

    while (fscanf(file_in, "%s%s%u%u", arr[i].name, \
    arr[i].maker, &(arr[i].price), &(arr[i].count)) == 4)
        i++;

    for (long int j = 0; j < i; j++)
    {
        len_str = strlen(arr[j].name);
        //printf("%s %s\n", x.name + len_str - len_under, under_str);
        if (strstr(arr[j].name + len_str - len_under, under_str))
        {
            if (flag)
            {
                printf("Result:\n");
                flag = 0;
            }
            printf("%s\n%s\n%u\n%u\n", arr[j].name, arr[j].maker, arr[j].price, arr[j].count);
        }
    }
    if (flag)
        return EMPTY;

    return OK;
}
