#!/bin/bash
set -e

gcc getenv.c -o getenv -lm -g -Wall -O3 -std=gnu11

reps=10 msg="Ha" ./getenv
msg="Ha" ./getenv
reps=20 msg=" " ./getenv
