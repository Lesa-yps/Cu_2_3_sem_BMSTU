#!/bin/bash

touch file.txt
file_contents=$(<"$2")
../../app.exe "$file_contents"  < "$1" > file.txt
a=$?
if [[ $a != 0 ]]; then
	exit 0
else
	exit 1
fi
