#!/bin/bash

count=0

for file in ../data/*; do
	if [ -f "$file" ]; then
		if [[ "${file}" == ../data/pos_??_in.txt ]]; then
			./pos_case.sh  "$file" "${file:0:15}""out.txt"
			count=$((count+$?))
		fi
		if [[ "${file}" == ../data/neg_??_in.txt ]]; then
			./neg_case.sh  "$file" "${file:0:15}""out.txt"
			count=$((count+$?))
		fi
	fi
done

echo $count
