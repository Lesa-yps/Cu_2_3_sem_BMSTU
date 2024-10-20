/**
 * \file strchr.h
 *
 * \brief This is a module that compares the results of work strchr and my_strchr.
 */

#ifndef STRRCHR_H
#define STRRCHR_H

#include <stddef.h>
#include <string.h>
#include "const.h"

/**
 * \brief The function compares the results of work strchr and my_strrchr
 * \param count the current count of mismatches between the two functions
 * \param arr_str the string to test the functions on
 * \return int the updated count of mismatches
 */
int all_strrchr(int count, char arr_str[]);

#endif // STRRCHR_H
