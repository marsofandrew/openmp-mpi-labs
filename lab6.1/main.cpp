//
// Created by andrew on 13.09.2020.
//

#include <omp.h>
#include <string>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    //setup OpenMP
    omp_set_dynamic(0);
    int threads_num = std::stoi(argv[1]);
    std::cout << "Threads = " << threads_num << "\n";
    omp_set_num_threads(threads_num);


    std::string string_a = argv[2];
    std::string string_b = argv[3];

    if (string_a.size() != string_b.size()) {
        std::cout << "Not equivalent\n";
        return 0;
    }

    bool is_equivalent = true;

#pragma omp parallel for
    for (int i = 0; i < string_b.size(); i++) {
        if (string_a[i] != string_b[i]) {
            is_equivalent = false;
        }
    }

    std::cout << "Is strings equivalent - " << (is_equivalent ? "Yes" : "No") << "\n";

    return 0;
}