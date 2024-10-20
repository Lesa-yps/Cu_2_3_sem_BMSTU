#include "work_with_mem.h"

int create_one(struct film *one, int len_str)
{
    int rc = OK;
    one->name = calloc(len_str, sizeof(char));
    one->title = calloc(len_str, sizeof(char));
    one->year = 0;
    if ((one->name == NULL) || (one->title == NULL))
    {
        free_one(one);
        rc = ERR_MEM;
    }
    return rc;
}

int create_arr(struct film **films, size_t n, int len_str)
{
    int rc = OK;
    *films = calloc(n, sizeof(struct film));
    if (*films == NULL)
        rc = ERR_MEM;
    else
    {
        for (size_t i = 0; i < n && !rc; i++)
        {
            rc = create_one(*films + i, len_str);
            if (rc == ERR_MEM)
            {
                free_arr(*films, i);
                break;
            }
        }
    }
    return rc;
}

void free_one(struct film *one)
{
    if (one)
    {
        free(one->name);
        free(one->title);
        one->name = NULL;
        one->title = NULL;
    }
}

void free_arr(struct film films[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        free_one(films + i);
    free(films);
}
