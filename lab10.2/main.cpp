//
// Created by andrew on 27.09.2020.
//

//
// Created by andrew on 27.09.2020.
//

//
// Created by andrew on 27.09.2020.
//
#include <stdio.h>
#include <mpi.h>

void bcast_message(int status, int root, int size) {
  for (int i = 0; i < size; i++) {
    if (i == root) {
      continue;
    }
    MPI_Send(&status, 1, MPI_INT, i, root, MPI_COMM_WORLD);
  }

}


int main(int argc, char *argv[]) {
  int rank1 = 0, size1 = 0;
  MPI_Comm comm1;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  int compete_threads = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank1);
  MPI_Comm_size(MPI_COMM_WORLD, &size1);
  printf("Process #%d from %d process\n", rank1, size1);
  bcast_message(1, rank1, size1);
  int b = -500000;
  for (int i = 0; i < (rank1 + 1) * 100000; i++) {
    b++;
  }
  printf("Process %d. Broadcast complete message\n", rank1);
  for (int i = 0; i < size1; i++) {
    if (i == rank1) {
      continue;
    }
    int complete = 0;
    MPI_Recv(&complete, 1, MPI_INT, i, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    compete_threads += complete;
    printf("Process %d. Receive %d threads\n", rank1, compete_threads);
  }

  printf("Process %d synchronized\n", rank1);

  MPI_Finalize();
}
