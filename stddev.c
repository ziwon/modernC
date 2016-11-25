#include <math.h>
#include <stdio.h>

typedef struct meanvar { double mean, var;} meanvar;

meanvar mean_and_var(const double *data) {
    long double avg = 0,
         avg2 = 0;
    long double ratio;
    size_t cnt = 0;
    for (size_t i = 0; !isnan(data[i]); i++) {
        ratio = cnt/(cnt + 1.0);
        cnt ++;
        avg  *= ratio;
        avg2 *= ratio;
        avg  += data[i]/(cnt +0.0);
        avg2 += pow(data[i], 2)/(cnt + 0.0);
    }
    return (meanvar){.mean = avg, .var = avg2 - pow(avg, 2)};
}

int main() {
    double d[] = { 34124.75, 34124.48,
        34124.90, 34125.31,
        34125.05, 34124.98, NAN};

    meanvar mv = mean_and_var(d);
    printf("mean: %.10g var: %.10g\n", mv.mean, mv.var*6/5.);

    double d2[] = { 4.75, 4.48,
        4.90, 5.31,
        5.05, 4.98, NAN};
    mv = mean_and_var(d2);
    mv.var *= 6./5;

    printf("mean: %.10g var: %.10g\n", mv.mean, mv.var);
}