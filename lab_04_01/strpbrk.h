/**
 * \file strpbrk.h
 *
 * \brief This is a module that compares the results of work strpbrk and my_strpbrk.
 */

#ifndef STRPBRK_H
#define STRPBRK_H

#include <string.h>
#include "const.h"
#include <stddef.h>

/**
 * \brief The function compares the results of work strpbrk and my_strpbrk
 * \param count the current count of mismatches between the two functions
 * \param arr_str the string to test the functions on
 * \return int the updated count of mismatches
 */
int all_strpbrk(int count, char arr_str[]);

#endif // STRPBRK_H
