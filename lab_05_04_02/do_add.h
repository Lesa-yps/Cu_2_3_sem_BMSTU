#ifndef DO_ADD_H
#define DO_ADD_H

#include <stdio.h>
#include <stdint.h>

#include "const&struct.h"
#include "pos.h"
#include "read.h"

/**
    * @file do_add.h
    * @brief Adds a new item to the binary file, maintaining the order by price and count.
    *
    * @param file_in A pointer to the input file.
    * @return int Returns OK if the item was successfully added or ERR_READ if there was an error reading input.
    */

int do_add(FILE *file);

#endif // DO_ADD_H
