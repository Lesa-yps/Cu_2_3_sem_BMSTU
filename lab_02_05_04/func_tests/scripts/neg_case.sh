#!/bin/bash

touch file.txt
../../app.exe < "$1" > file.txt
a=$?
if [[ $a != 0 ]]; then
	exit 0
else
	exit 1
fi
