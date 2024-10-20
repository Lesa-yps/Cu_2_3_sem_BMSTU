#ifndef DO_ADD_TXT_H
#define DO_ADD_TXT_H

#include <stdio.h>
#include <stdint.h>

#include "const&struct.h"
#include "read.h"

/**
    * @file do_add_txt.h
    * @brief Adds a new item to the text file, maintaining the order by price and count.
    *
    * @param file_in A pointer to the input text file.
    * @return int Returns OK if the item was successfully added or ERR_READ if there was an error reading input.
    */

int do_add_txt(FILE *file);

#endif // DO_ADD_TXT_H
