#!/bin/bash

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g -o main.o -c main.c

clang -fsanitize=address -fno-omit-frame-pointer -g -o app.exe main.o -lm
