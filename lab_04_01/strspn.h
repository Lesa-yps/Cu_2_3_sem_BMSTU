/**
 * \file strspn.h
 *
 * \brief This is a module that compares the results of work strspn and my_strspn.
 */

#ifndef STRSPN_H
#define STRSPN_H

#include <string.h>
#include "const.h"
#include <stddef.h>

/**
 * \brief The function compares the results of work strspn and my_strspn
 * \param count the current count of mismatches between the two functions
 * \param arr_str the string to test the functions on
 * \return int the updated count of mismatches
 */
int all_strspn(int count, char arr_str[]);

#endif // STRSPN_H
