#include <omp.h>
#include <iostream>
int main(int argc, char** argv)
{
    omp_set_dynamic(0);
    omp_set_num_threads(4);
#pragma omp parallel
    {
        int count=omp_get_thread_num();
        int ItsMe=omp_get_num_threads();
#pragma omp critical
        printf("Hello, OpenMP! I am %d of %d\n", count,ItsMe);
    }
    return 0;
}
