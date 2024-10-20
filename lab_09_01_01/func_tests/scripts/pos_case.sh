#!/bin/bash

touch file.txt
file_contents=$(cat "$2")
# shellcheck disable=SC2086
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet \
./app.exe $file_contents > file.txt
#echo "My result:\n"
#cat file.txt
#echo "Right result:\n"
#cat "$1"
a=$?
if [[ $a != 0 ]]; then
	exit 1
else
	./func_tests/scripts/comparator.sh file.txt "$1"
	exit $?
fi
