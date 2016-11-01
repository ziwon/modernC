#!/usr/bin/env c99sh

int main(int argc, char *argv[])
{
    long long niter = argc > 1 ? atof(argv[1]) : 100000;
    long long count = 0;

    #pragma omp parallel
    {
        unsigned int seed = omp_get_thread_num();

        #pragma omp for reduction(+: count) schedule(static)
        for (long long i = 0; i < niter; ++i) {
            const double x = rand_r(&seed) / (double) RAND_MAX;
            const double y = rand_r(&seed) / (double) RAND_MAX;
            count += sqrt(x*x + y*y) < 1;
        }

    }

    printf("%lld: %g\n", niter, M_PI - 4*(count / (double) niter));
}
