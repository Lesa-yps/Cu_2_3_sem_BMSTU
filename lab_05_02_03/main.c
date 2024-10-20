#include <stdio.h>

#include "const.h"
#include "calc.h"

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
    double mean;
    double stdev;
    int res;
    int rc;
    long int n;

    if (argc < 2)
    {
        printf("Where is my file, Billy?\n");
        return NO_FILE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("What with my file, Billy?\n");
        return NO_OPEN;
    }

    rc = calc_mean_n(file, &mean, &n);
    if (rc == ERR_NUM)
    {
        printf("Error: file have error numders.\n");
        return ERR_NUM;
    }
    else if (rc == EMPTY)
    {
        printf("Error: file is empty.\n");
        return EMPTY;
    }
    else if (rc == ONLY1)
    {
        printf("Error: file has only one number, programm can't calc.\n");
        return ONLY1;
    }

    fseek(file, 0, SEEK_SET);

    stdev = calc_stdev(file, mean, n, &rc);

    fseek(file, 0, SEEK_SET);

    if (rc == NULL_STDEV)
        res = 0;
    else
        res = calc_res(file, mean, stdev, n);

    printf("Result: %d\n", res);
    return OK;
}

