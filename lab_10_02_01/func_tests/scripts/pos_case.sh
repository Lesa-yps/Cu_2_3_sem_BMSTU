#!/bin/bash

touch ./func_tests/scripts/file.txt
./app.exe < "$2" > ./func_tests/scripts/file.txt
a=$?
#echo "$a"
#echo "itogo"
#cat ./func_tests/scripts/file.txt
#echo "right res"
#cat "$1"
if [[ $a != 0 ]]; then
	exit 1
else
        ./func_tests/scripts/comparator.sh ./func_tests/scripts/file.txt "$1"
	exit $?
fi
