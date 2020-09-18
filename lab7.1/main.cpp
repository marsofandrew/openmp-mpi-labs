//
// Created by andrew on 17.09.2020.
//

#include <iostream>
#include <cmath>

#ifdef _OPENMP
#include <omp.h>
#endif

#define NMAX 16

double a[NMAX];


int main(int argc, char* argv[]) {

    a[0] = 1;
    double f = 2.0;
# pragma omp parallel for
    for (int i = 1; i < NMAX; i++) {
        //a[i] = f * a[i - 1]; wouldn't be parallel because of data race
        a[i] = std::pow(f, i);
    }

    for (int i = 0; i < NMAX; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
