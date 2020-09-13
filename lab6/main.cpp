#include <omp.h>
#include <iostream>

int main(int argc, char **argv) {
    omp_set_dynamic(0);
    int count = omp_get_thread_num();
    if (count > 4) {
        count = 4;
    }
    omp_set_num_threads(count);
#pragma omp parallel
    {
        int thread_num = omp_get_thread_num();
        int ItsMe = omp_get_num_threads();

#pragma omp critical
        printf("Hello, OpenMP! I am %d of %d\n", thread_num, ItsMe);
    }
    return 0;
}
