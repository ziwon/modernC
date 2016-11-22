#include <stdio.h>

long long int fibonacchi() {
    static long long int first = 0;
    static long long int second = 1;
    long long int out = first + second;
    first = second;
    second = out;
    return out;
}

int main() {
    for (int i = 0; i < 50; i++)
        printf("%lli\n", fibonacchi());
}