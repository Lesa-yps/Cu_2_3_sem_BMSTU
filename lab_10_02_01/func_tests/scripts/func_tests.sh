#!/bin/bash

count_pos=0
count_neg=0
count_pos_fail=0
count_neg_fail=0
for file in ./func_tests/data/*; do
	if [ -f "$file" ]; then
		if [[ "${file}" == ./func_tests/data/pos_??_in.txt ]]; then
			#echo "${file:0:25}""out.txt"
			#echo "${file}"
                        ./func_tests/scripts/pos_case.sh "${file:0:25}""out.txt" "${file}"
			if [[ $? == 1 ]]; then
                                count_pos_fail=$((count_pos_fail+1))
				echo "${file} ERROR"
			else
				echo "${file} OK"
			fi
                        count_pos=$((count_pos+1))
		fi
		if [[ "${file}" == ./func_tests/data/neg_??_in.txt ]]; then
                        ./func_tests/scripts/neg_case.sh "${file}"
			if [[ $? == 1 ]]; then
                                count_neg_fail=$((count_neg_fail+1))
				echo "${file} ERROR"
			else
				echo "${file} OK"
			fi
                        count_neg=$((count_neg+1))
		fi
	fi
done

echo "Failed $count_pos_fail/$count_pos POS and $count_neg_fail/$count_neg NEG tests."
