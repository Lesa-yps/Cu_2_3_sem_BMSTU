#include <stdio.h>

#include "do_c.h"
#include "do_p.h"
#include "do_s.h"

#include "const.h"

/**
    * @brief Main function that takes command line arguments and performs different
    *  operations based on the arguments.
    *
    * @param argc Number of arguments in the command line.
    * @param argv Array of arguments in the command line.
    * @return int Returns an integer indicating the status of the program.
    */

int main(int argc, char *argv[])
{
    FILE *file;
    int rc;

    if (argc < 3)
        return NO_ARGS;

    if (strcmp(argv[1], "c") == 0)
    {
        if (argc != 4)
            return NO_ARGS;

        file = fopen(argv[3], "wb");
        if (do_c(file, argv[2]) == NOT_NUM)
        {
            fclose(file);
            return NOT_NUM;
        }
        fclose(file);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        if (argc != 3)
            return NO_ARGS;
        file = fopen(argv[2], "rb");
        if (file == NULL)
            return NO_OPEN;
        rc = do_p(file);
        if (rc != OK)
        {
            fclose(file);
            return rc;
        }
        fclose(file);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        if (argc != 3)
            return NO_ARGS;
        file = fopen(argv[2], "r+b");
        if (file == NULL)
            return NO_OPEN;
        rc = do_s(file);
        if (rc != OK)
        {
            fclose(file);
            return rc;
        }
        fclose(file);
    }
    else
        return ERR_DO;
    return OK;
}
