P=gsl_vector
OBJECTS=
CFLAGS=`pkg-config --cflags gsl` -g -Wall -O3 -std=gnu11
LDLIBS=`pkg-config --libs gsl`
CC=gcc

$(P): $(P:=.o)

run: $(P)
	./run.sh

clean:
	rm -f $(P) $(P:=.o)

.PHONY: clean
