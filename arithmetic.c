#include <stdio.h>

int main() {
    int evens[5] = {0, 2, 4, 6, 8};
    printf("The first even number is, of course, %i\n", *evens); // evens[0]
    int *positive_evens = &evens[1]; // the address of element 1 assigned to a new pointer
    printf("The first positive even number is %i\n", positive_evens[0]);
    printf("The last positive even number is %i\n", positive_evens[3]);

    printf("The length of evens array is %i\n",  (int)(sizeof(evens) / sizeof(evens[0]))); // 5
    printf("The size of evens array is %i\n",  (int)(sizeof(evens))); // 20

    printf("The length of positive_evens pointer %i\n",  (int)(sizeof(positive_evens) / sizeof(positive_evens[0]))); // 2
    printf("The size of positive_evens pointer is %i\n",  (int)(sizeof(positive_evens))); // 8
}