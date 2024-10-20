#include "pos.h"

struct tovar get_by_pos(FILE *file, long int i, int *err)
{
    *err = 0;
    struct tovar x;
    fseek(file, i * sizeof(struct tovar), SEEK_SET);
    if (fread(&x, sizeof(struct tovar), 1, file) != 1)
        *err = 1;
    return x;
}

void put_by_pos(FILE *file, long int i, struct tovar x)
{
    fseek(file, i * sizeof(struct tovar), SEEK_SET);
    fwrite(&x, sizeof(struct tovar), 1, file);
}
