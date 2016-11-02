#!/bin/bash
set -e
gcc stddev_bugged.c -o stddev_bugged -fprofile-arcs -ftest-coverage -lm -g -Wall -O3 -std=gnu11

