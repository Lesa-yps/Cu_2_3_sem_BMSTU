#!/bin/bash

for file in *; do
	if [ -f "$file" ]; then
		if [[ "${file}" != *.sh && "${file}" != *.c ]]; then
			rm "$file"
		fi
	fi
done
