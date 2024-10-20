#!/bin/bash

# export CK_RUN_SUITE=
# export CK_RUN_CASE=
# export CK_INCLUDE_TAGS=
# export CK_EXCLUDE_TAGS=

if [[ -z $NO_MEM_CHECK ]]; then
    # If NO_MEM_CHECK is not defined or is empty
    export CK_FORK=no
    ./unit_tests.exe
    if [[ $? -eq 0 ]]; then
        valgrind --quiet --leak-check=full --show-leak-kinds=all --track-origins=yes ./unit_tests.exe
    fi
else
    # If NO_MEM_CHECK is defined and not empty
    ./unit_tests.exe
fi
