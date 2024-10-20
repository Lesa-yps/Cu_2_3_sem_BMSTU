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
 * @brief This function reads a string from standard input.
 *
 * This function reads a string from standard input and stores it in the
 * character array arr_str. The maximum length of the input string is defined
 * as MAX_LEN_STR.
 *
 * @param arr_str The character array in which to store the input string.
 * @return 0 if the input string is successfully read, -1 otherwise.
 */
int reading(char arr_str[]);

#endif // READ_H
