/**
 * \file strchr.h
 *
 * \brief This is a module that compares the results of work strchr and my_strchr.
 */

#ifndef STRCHR_H
#define STRCHR_H

#include <stddef.h>
#include <string.h>
#include "const.h"

/**
 * \brief The function compares the results of work strchr and my_strchr
 * \param count the current count of mismatches between the two functions
 * \param arr_str the string to test the functions on
 * \return int the updated count of mismatches
 */
int all_strchr(int count, char arr_str[]);

#endif // STRCHR_H
