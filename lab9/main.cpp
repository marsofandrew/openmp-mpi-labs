//
// Created by andrew on 22.09.2020.
//
#include <mpi.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>


enum status_t {
    FAIL,
    SUCCESS
};


int main(int argc, char **argv) {
    std::random_device rd;
    std::mt19937 mt(rd());

    int rank = 0, size = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        std::cout << "at least 2 processors are required to execute the program\n";
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        //John Silver process
        std::uniform_int_distribution<int> dist(1, size);
        int success = dist(mt);

        for (int i = 1; i < size; ++i) {
            status_t status = status_t::FAIL;
            if (i == success) {
                status = status_t::SUCCESS;
            }
            MPI_Send(&status, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }

        for (int j = 1; j < size; ++j) {
            status_t status = {};
            MPI_Recv(&status, 1, MPI_INT, j, j, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            std::cout << "Group " << j << ": status " << status << "\n";
        }
    } else {
        status_t status = {};
        MPI_Recv(&status, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::uniform_int_distribution<int> dist(1000, 1000000000);
        double b = 0;
        for (int i = 0; i < dist(mt); ++i) {
            double a = std::pow(0.95, i);
            b = a * i;
        }
        dist(mt);

        MPI_Send(&status, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
