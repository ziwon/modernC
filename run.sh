#!/bin/bash

set -e

usage(){
    echo "Usage: $0 filename.c"
    exit 1
}

[[ $# -eq 0 ]] && usage

gcc $1 -o ${1%.c} -lm -g -Wall -O3 -std=gnu11

./${1%.c}
