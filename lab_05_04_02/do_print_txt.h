#ifndef DO_PRINT_TXT_H
#define DO_PRINT_TXT_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "const&struct.h"

/**
    * @file do_print_txt.h
    * @brief Prints all items from the text file that contain a certain string at the end of their name.
    *
    * @param file_in A pointer to the input text file.
    * @param under_str The string to search for at the end of the names.
    * @return int Returns OK if at least one matching item was found and printed or EMPTY if no matching items were found.
    */

int do_print_txt(FILE *file_in, char under_str[]);

#endif // DO_PRINT_TXT_H
