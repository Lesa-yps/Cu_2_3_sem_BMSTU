#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "const&struct.h"

/**
    * @file read.h
    * @brief Prompts the user to input a new item and returns it.
    *
    * @param err A pointer to the error flag.
    * @return struct tovar The new item.
    */

struct tovar read(int *err);

#endif // READ_H
