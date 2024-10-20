#ifndef CONST_H
#define CONST_H

/**
    * @file const&struct.h
    * @brief Store constants and definition struct tovar.
    */

#define OK 0
#define EMPTY 53
#define NO_ARGS 53
#define NO_OPEN 53
#define ERR_READ -5
#define ERR_N -1

#define MAX_NAME 30
#define MAX_MAKER 15
#define MAX_STRUCT 10

#include <stdint.h>

struct tovar
{
    char name[MAX_NAME + 1];
    char maker[MAX_MAKER + 1];
    uint32_t price;
    uint32_t count;
};

#endif // CONST_H
