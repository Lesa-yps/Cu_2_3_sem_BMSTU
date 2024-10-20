/**
 * @file check_data.h
 *
 * @brief This is a module that checks if the date is correct.
 */

#ifndef CHECK_DATA_H
#define CHECK_DATA_H

#include "const.h"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/**
 * @brief Function that checks if the date is correct
 * @param arr_word[in] - an array of words
 * @return 1 if the date is correct, otherwise 0
 */
int check_data(char arr_word[][MAX_LEN_WORD + 1]);

#endif // CHECK_DATA_H
