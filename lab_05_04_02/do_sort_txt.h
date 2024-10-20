#ifndef DO_SORT_TXT_H
#define DO_SORT_TXT_H

#include <stdio.h>
#include <stdint.h>

#include "const&struct.h"

/**
    * @file do_sort_txt.h
    * @brief Sorts the items in the input text file by price and count and writes them to the
    * output text file.
    *
    * @param file_in A pointer to the input text file.
    * @param file_out A pointer to the output text file.
    * @return void This function does not return a value.
    */

void do_sort_txt(FILE *file_in, FILE *file_out);

#endif // DO_SORT_TXT_H
