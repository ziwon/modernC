#!/bin/bash
set -e
gcc gsl_erf.c -o gsl_erf -g -Wall -O3 -std=gnu11 `pkg-config --cflags --libs gsl`
