CC=g++
MPI_CC='mpic++'
OUTPUT=out
FLAGS='-fopenmp'
EXECUTABLE=program


build: folder lab_folder
	${CC} ${FLAGS} $(CFLAGS) $(LAB)/*.cpp -o ${OUTPUT}/$(LAB)/${EXECUTABLE}

execute:
	./${OUTPUT}/$(LAB)/program $(ARGS)

run: build execute

mpi_build: folder lab_folder
	${MPI_CC} -g $(LAB)/*.cpp -o ${OUTPUT}/$(LAB)/${EXECUTABLE}

mpi_execute:
	mpirun -n $(THREAD_NUM) ./${OUTPUT}/$(LAB)/program $(ARGS)

mpi_run: mpi_build mpi_execute

folder:
	mkdir -p ${OUTPUT}

lab_folder:
	mkdir -p ${OUTPUT}/$(LAB)

clean:
	rm -r ${OUTPUT}
