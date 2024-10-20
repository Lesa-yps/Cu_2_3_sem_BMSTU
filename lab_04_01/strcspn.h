/**
 * \file strcspn.h
 *
 * \brief This is a module that compares the results of work strcspn and my_strcspn.
 */

#ifndef STRCSPN_H
#define STRCSPN_H

#include <string.h>
#include "const.h"
#include <stddef.h>

/**
 * \brief The function compares the results of work strcspn and my_strcspn
 * \param count the current count of mismatches between the two functions
 * \param arr_str the string to test the functions on
 * \return int the updated count of mismatches
 */
int all_strcspn(int count, char arr_str[]);

#endif // STRCSPN_H
