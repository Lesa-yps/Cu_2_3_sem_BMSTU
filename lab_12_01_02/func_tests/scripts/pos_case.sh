#!/bin/bash

touch file.txt
python3 ./check.py < "$2" > file.txt
a=$?
if [[ $a != 0 ]]; then
	exit 1
else
    ./func_tests/scripts/comparator.sh file.txt "$1"
	exit $?
fi
