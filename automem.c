#include <stdio.h>

typedef struct powers {
    double base, square, cube;
} powers;

powers get_power(double in) {
    powers out = {.base = in,
                .square = in*in,
                .cube = in*in*in};
    return out; // a copy of the local, automatically allocated `out` is made, then the local copy is destroyed
}

int *get_even(int count){
    int out[count];
    for (int i = 0; i < count; i++)
        out[i] = 2*i;
    return out; // invalid. a copy of the pointer to `out` gets made. once the autoallocated memory is destroyed, the pointer is now pointing to bad data.
}

int main() {
    powers threes = get_power(3);
    int *evens = get_even(3);
    printf("threes: %g\t%g\t%g\n", threes.base, threes.square, threes.cube);
    printf("evens: %i\t%i\t%i\n", evens[0], evens[1], evens[2]); // Segmentation faulit, `even` is a valid pointer to int, but it is pointing to already freed data.
}
