/*
 * http://ehpub.co.kr/nan-nanf-nanl-%ED%95%A8%EC%88%98/
 *
 * 실수에서 아무수도 아닌 수를 nan이라 부릅니다. 그리고 무한대는 inf로 부르고 있습니다.
 * double 형식은 첫번째 비트가 부호 비트이고 이후 11개의 비트는 지수부, 나머지는 가수부입니다.
 * 특히 nan이나 inf는 특수한 값으로 약속하고 있습니다.
 * nan은 부호 비트가 0이고 지수부는 모두 1이며 가수부는 첫번째 비트는 1, 나머지는 0입니다.
 * 16진수로 표현하면 0x7FF8000000000000 입니다. 그리고 inf는 부호 비트가 0이고 지수부는 모두 1이며
 * 가수부는 모두 0입니다. 16진수로 표현하면 0x7FF0000000000000 입니다.
 * 부호 비트가 1일 때는 -nan과 -inf입니다.
 * 다음 예제는 nan과 inf가 메모리에 어떻게 저장하고 있는지 테스트하는 코드입니다.
 **/

#include <math.h>
#include <stdio.h>
typedef union {
    unsigned char buf[8];
    double dval;
}Test;

int main() {
    Test t;
    int temp = 0;
    int i;

    t.dval = nan("test"); // nan을 반환
    printf("%f is ", t.dval);

    for(i = 7; i >= 0; i--) {
        printf("%02X ", t.buf[i]);
    }
    printf("\n");

    t.dval = 1.0 / temp; // inf
    printf("%f is ", t.dval);
    for (i = 7; i >= 0; i--) { // little endian 시스템이므로
        printf("%02X ", t.buf[i]);//16진수로 출력
    }
    printf("\n");

    return 0;
}