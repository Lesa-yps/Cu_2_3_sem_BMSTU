#include <stdio.h>
#include <stdint.h>

#include "do_add.h"
#include "do_print.h"
#include "do_sort.h"

#include "do_print_txt.h"
#include "do_add_txt.h"
#include "do_sort_txt.h"

#include "const&struct.h"

/*void print(FILE *file)
{
    printf("Vot:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fread(&x, sizeof(struct tovar), 1, file) == 1)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}

void print_txt(FILE *file)
{
    printf("Vot_txt:\n");
    struct tovar x;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s%s%u%u", x.name, x.maker, &(x.price), &(x.count)) == 4)
        printf("%s %s %u %u\n", x.name, x.maker, x.price, x.count);
}*/

/**
    * @brief Основная функция программы.
    *
    * @param argc количество аргументов командной строки
    * @param argv массив аргументов командной строки
    * @return int статус завершения программы
    */

int main(int argc, char *argv[])
{
    FILE *file_in;
    FILE *file_out;
    int rc;
    //struct tovar tovs[]

    if (argc < 3)
    {
        //printf("What I have to do, Billy?\n");
        return NO_ARGS;
    }

    if (strcmp(argv[1], "fb") == 0)
    {
        if (argc < 4)
        {
            //printf("Error: not enouth args.\n");
            return NO_ARGS;
        }
        file_in = fopen(argv[2], "rb");
        if (file_in == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        //print(file_in);
        //fseek(file_in, 0, SEEK_SET);
        if (do_print(file_in, argv[3]) == EMPTY)
        {
            //printf("Error: not this strings.\n");
            fclose(file_in);
            return EMPTY;
        }
        fclose(file_in);
    }
    else if (strcmp(argv[1], "ab") == 0)
    {
        file_in = fopen(argv[2], "r+b");
        if (file_in == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        //print(file_in);
        if (do_add(file_in) == ERR_READ)
        {
            //printf("Error with reading new struct.\n");
            return ERR_READ;
        }
        //print(file_in);
        fclose(file_in);
    }
    else if (strcmp(argv[1], "sb") == 0)
    {
        if (argc < 4)
        {
            //printf("Error: not enouth args.\n");
            return NO_ARGS;
        }
        file_in = fopen(argv[2], "rb");
        if (file_in == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        file_out = fopen(argv[3], "wb");
        if (file_out == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        fclose(file_out);
        file_out = fopen(argv[3], "r+b");
        if (file_out == NULL)
        {
            printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        /*printf("file_in:\n");
        print(file_in);
        fseek(file_in, 0, SEEK_SET);
        printf("file_out:\n");
        print(file_out);
        fseek(file_out, 0, SEEK_SET);*/
        do_sort(file_in, file_out);
        /*printf("file_in:\n");
        print(file_in);
        printf("file_out:\n");
        print(file_out);*/
        fclose(file_in);
        fclose(file_out);
    }
    else if (strcmp(argv[1], "ft") == 0)
    {
        if (argc < 4)
        {
            //printf("Error: not enouth args.\n");
            return NO_ARGS;
        }
        file_in = fopen(argv[2], "r");
        if (file_in == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        //print_txt(file_in);
        //fseek(file_in, 0, SEEK_SET);
        if (do_print_txt(file_in, argv[3]) == EMPTY)
        {
            //printf("Error: not this strings.\n");
            fclose(file_in);
            return EMPTY;
        }
        fclose(file_in);
    }
    else if (strcmp(argv[1], "at") == 0)
    {
        file_in = fopen(argv[2], "r+");
        if (file_in == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        //print_txt(file_in);
        //fseek(file_in, 0, SEEK_SET);
        rc = do_add_txt(file_in);
        if (rc == ERR_READ)
        {
            //printf("Error with reading new struct.\n");
            return ERR_READ;
        }
        if (rc == ERR_N)
        {
            //printf("Error: too many structs.\n");
            return ERR_N;
        }
        //print_txt(file_in);
        fclose(file_in);
    }
    else if (strcmp(argv[1], "st") == 0)
    {
        if (argc < 4)
        {
            //printf("Error: not enouth args.\n");
            return NO_ARGS;
        }
        file_in = fopen(argv[2], "r");
        if (file_in == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        file_out = fopen(argv[3], "w");
        if (file_out == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        /*printf("file_in:\n");
        print_txt(file_in);
        fseek(file_in, 0, SEEK_SET);
        printf("file_out:\n");
        print_txt(file_out);*/
        fclose(file_out);
        file_out = fopen(argv[3], "r+");
        if (file_out == NULL)
        {
            //printf("What with my file, Billy?\n");
            return NO_OPEN;
        }
        do_sort_txt(file_in, file_out);
        /*printf("file_in:\n");
        print_txt(file_in);
        printf("file_out:\n");
        print_txt(file_out);*/
        fclose(file_in);
        fclose(file_out);
    }
    else
    {
        //printf("Error: programm don't knew this comand.\n");
        return NO_ARGS;
    }

    return OK;
}
