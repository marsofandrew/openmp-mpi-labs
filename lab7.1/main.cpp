//
// Created by andrew on 17.09.2020.
//

#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif

#define NMAX 11

double a[NMAX];


int main(void) {

    a[0] = 1;
    double f = 2.0;
# pragma omp parallel for
    for (int i = 1; i < NMAX; i++) {
        a[i] = f * a[i - 1];
    }

    return 0;
}
