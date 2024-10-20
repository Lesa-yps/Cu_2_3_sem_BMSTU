#ifndef DO_SORT_H
#define DO_SORT_H

#include <stdio.h>
#include <stdint.h>

#include "const&struct.h"
#include "pos.h"

/**
    * @file do_sort.h
    * @brief Sorts the items in the input file by price and count and writes them to the output file.
    *
    * @param file_in A pointer to the input file.
    * @param file_out A pointer to the output file.
    * @return void This function does not return a value.
    */

void do_sort(FILE *file_in, FILE *file_out);

#endif // DO_SORT_H
