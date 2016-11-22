#include <gsl/gsl_linalg.h>
#include <stdio.h>

#define Staticdef(type, var, initialization) \
    static type var = 0; \
    if (!(var)) var = (initialization);

int main() {

    // static variables are initialized when the program starts, before main,
    // so can't initialize them with a nonconstant value

    gsl_vector *x = gsl_vector_alloc (4);
    Staticdef(gsl_vector*, y, gsl_vector_alloc(4));

    for (int i = 0; i < 4; i++) {
        gsl_vector_set (x, i, (double)i);    // [0,1,2,3]
        gsl_vector_set (y, i, (double)i*10); // [0, 10, 20, 30]
    }

    gsl_vector_fprintf (stdout, x, "x: %g");
    gsl_vector_fprintf (stdout, y, "y: %g");

    /*
    x: 0
    x: 1
    x: 2
    x: 3
    y: 0
    y: 10
    y: 20
    y: 30
    */
}