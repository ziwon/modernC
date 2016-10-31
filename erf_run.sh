#/bin/bash
set -e

gcc erf.c -o erf -lm -g -Wall -O3 -std=gnu11

# clang: C99, gcc: C89
#
# compiling POSIX standard (C99)
# c99 erf.c -o erf -lm -g -Wall[-w1] -O3[-O0]

./erf
