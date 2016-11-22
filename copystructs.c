#include <assert.h>

typedef struct {
    int a, b;
    double c, d;
    int *efg;
} demo_s;

int main() {
    demo_s d1 = {.b=1, .c=2, .d=3, .efg=(int[]){4, 5, 6}};
    demo_s d2 = d1; // a copy of a pointer still points to the original data

    d1.b=14;
    d1.c=41;
    d1.efg[0]=7; // when we change d1.efg[0], the change also affects the copy of a pointer d2.efg
    assert(d2.a==0);
    assert(d2.b==1);
    assert(d2.c==2);
    assert(d2.d==3);
    assert(d2.efg[0]==7);
}