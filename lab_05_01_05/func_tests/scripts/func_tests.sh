#!/bin/bash

cd "${0%/*}"  || exit

count=0

for file in ../data/*; do
	if [ -f "$file" ]; then
		if [[ "${file}" == ../data/pos_??_in.txt ]]; then
			./pos_case.sh  "$file" "${file:0:15}""out.txt" "${file:0:15}""args.txt"
			if [[ $? == 1 ]]; then
				count=$((count+1))
				echo "${file} ERROR"
			else
				echo "${file} OK"
			fi
		fi
		if [[ "${file}" == ../data/neg_??_in.txt ]]; then
			./neg_case.sh  "$file" "${file:0:15}""args.txt"
			if [[ $? == 1 ]]; then
				count=$((count+1))
				echo "${file} ERROR"
			else
				echo "${file} OK"
			fi
		fi
	fi
done

echo "Failed $count tests."
