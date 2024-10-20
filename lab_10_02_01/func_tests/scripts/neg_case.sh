#!/bin/bash

./app.exe < "$1"
a=$?
if [[ $a != 0 ]]; then
	exit 0
else
	exit 1
fi
