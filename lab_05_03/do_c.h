#ifndef DO_C_H
#define DO_C_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/time.h>
#include <time.h>

#include "const.h"

/**
    * @brief Function fills the file with random integers.
    *
    * @param file Pointer to a file.
    * @param arg String argument from the command line.
    * @return int Returns an integer indicating the status of the program.
    */

int do_c(FILE *file, char num[]);

#endif // DO_C_H
