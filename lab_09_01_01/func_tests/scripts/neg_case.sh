#!/bin/bash

touch file.txt
file_contents=$(cat "$1")
# shellcheck disable=SC2086
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet \
./app.exe $file_contents > file.txt
a=$?
if [[ $a != 0 ]]; then
	exit 0
else
	exit 1
fi
