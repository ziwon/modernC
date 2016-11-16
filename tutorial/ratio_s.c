#include <stdio.h>

typedef struct {
    int numerator, denominator;
    double value;
} ratio_s;

ratio_s new_ratio(int num, int den) {
    return (ratio_s){.numerator=num, .denominator=den, .value=num/(double)den};
}

void print_ratio(ratio_s  r){
    printf("%i/%i = %g\n", r.numerator, r.denominator, r.value);
}

ratio_s ratio_add(ratio_s left, ratio_s right){
    return (ratio_s){
        .numerator=left.numerator*right.denominator
            + right.numerator*left.denominator,
            .denominator=left.denominator * right.denominator,
            .value=left.value + right.value
    };
}

int main(){
    ratio_s r1 = new_ratio(2, 3);
    ratio_s r2 = new_ratio(1, 4);
    print_ratio(r1);
    print_ratio(r2);
    print_ratio(ratio_add(r1, r2));
}
