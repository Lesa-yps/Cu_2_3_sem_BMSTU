#!/bin/bash

touch file.txt
../../app.exe < "$1" > file.txt
a=$?
if [[ $a != 0 ]]; then
	exit 1
else
	./comparator.sh file.txt "$2"
	exit $?
fi
