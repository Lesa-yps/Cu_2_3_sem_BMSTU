/**
 * @file read.h
 *
 * @brief This is a module that reads a string from standard input.
 */

#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <string.h>

#include "const.h"

/**
 * @brief Function that reads the string from the standard input stream
 * @param arr_str[out] - the string to be read
 * @return OK if the string was read successfully, ERR otherwise
 */
int reading(char arr_str[]);

#endif // READ_H
