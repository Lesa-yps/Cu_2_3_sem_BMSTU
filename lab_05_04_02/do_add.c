#include "do_add.h"

/*void print(FILE *file)
{
    printf("Vot:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fread(&x, sizeof(struct tovar), 1, file) == 1)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

int do_add(FILE *file_in)
{
    long int i = 0;
    int err;
    struct tovar x = read(&err);
    if (err == 1)
        return ERR_READ;
    struct tovar y = get_by_pos(file_in, i, &err);
    if (err == 1)
        fwrite(&x, sizeof(struct tovar), 1, file_in);

    while ((x.price < y.price) || ((x.price == y.price) && (x.count < y.count)))
    {
        i++;
        y = get_by_pos(file_in, i, &err);
        if (err == 1)
            break;
    }

    while (! err)
    {
        put_by_pos(file_in, i, x);
        x = y;
        y = get_by_pos(file_in, i + 1, &err);
        i++;
    }
    put_by_pos(file_in, i, x);
    return OK;
}
