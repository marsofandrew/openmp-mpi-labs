//
// Created by andrew on 27.09.2020.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int rank1, size1, rank2, size2;
  int value;
  MPI_Comm comm1;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank1);
  MPI_Comm_size(MPI_COMM_WORLD, &size1);
  printf("Мой ранг в MPI_COMM_WORLD %d \n", rank1);
  printf("Всего в MPI_COMM_WORLD %d процесоов\n", size1);
  MPI_Comm_split(MPI_COMM_WORLD, (rank1 % 2 == 0) ? 0 : 1, 0, &comm1);
  MPI_Comm_rank(comm1, &rank2);
  MPI_Comm_size(comm1, &size2);
  if ((rank2 == 0) && (rank1 % 2)) value = 777;
  if ((rank2 == 0) && !(rank1 % 2)) value = 666;
  MPI_Bcast(&value, 1, MPI_INT, 0, comm1);
  printf("Мой ранг в MPI_COMM_WORLD %d,Мой ранг в MPI_COMM_WORLD %d, broadcasted message %d", rank1, rank2, value);
  MPI_Finalize();
}