#!/bin/bash

touch file.txt
file_contents=$(<"$3")
../../app.exe "$file_contents" < "$1" > file.txt
a=$?

if [[ $a != 0 ]]; then
	exit 1
else
	./comparator.sh file.txt "$2"
	exit $?
fi
