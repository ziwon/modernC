#include <stdio.h>

#define sum(max, out) {             \
    int total=0;                    \
    for(int i=0; i <= max; i++)     \
        total += i;                 \
    out = total;                    \
}

int main() {
    int out;
    int total = 5;
    sum(5, out);
    printf("out= %i original total=%i\n", out, total);
}