#!/bin/bash

# link1=/home/lumos/c_prog/lab_10/lab_10_03_01
# link2=/home/lumos/c_prog/lab_10/lab_10_03_02
# target=/home/lumos/c_prog/lab_10/lab_10_03_common

link1=../lab_10_03_01
link2=../lab_10_03_02
target=../../lab_10_03_common

symlink="-s"

ln $symlink $target/inc/associative_array.h $link1/inc/associative_array.h
ln $symlink $target/inc/associative_array.h $link2/inc/associative_array.h

ln $symlink $target/inc/check_func_1.h $link1/inc/check_func_1.h
ln $symlink $target/inc/check_func_1.h $link2/inc/check_func_1.h

ln $symlink $target/unit_tests/check_func_1.c $link1/unit_tests/check_func_1.c
ln $symlink $target/unit_tests/check_func_1.c $link2/unit_tests/check_func_1.c

ln $symlink $target/unit_tests/check_main.c $link1/unit_tests/check_main.c
ln $symlink $target/unit_tests/check_main.c $link2/unit_tests/check_main.c

ln $symlink $target/unit_tests/readme.md $link1/unit_tests/readme.md
ln $symlink $target/unit_tests/readme.md $link2/unit_tests/readme.md
