#!/bin/bash

for file in func_tests/data/*.txt; do
	xxd -b "$file" "${file%.*}.bin";
done
