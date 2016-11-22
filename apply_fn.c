#include <stdio.h>

typedef int (*func)(int, int);

int apply(func f, int a, int b) {
    return f(a, b);
}

int sum(int a, int b) {
    return a + b;
}

int (*call())(int, int);

int (*call())(int, int) {
    return sum;
}

int main() {
    int (*p)(int, int);
    p = call();
    printf("%d\n", (*p)(1, 2)); // 3
    printf("%d\n", apply(sum, 1, 2)); // 3
}
