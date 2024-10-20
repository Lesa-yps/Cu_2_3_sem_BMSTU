#!/bin/bash

for file in func_tests/data/*.bin; do
	xxd -p -r "$file" > "${file%.*}.txt";
done
