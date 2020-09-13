CC=g++
OUTPUT=out
FLAGS='-fopenmp'
EXECUTABLE=program


build: folder
	mkdir -p ${OUTPUT}/$(lab)
	${CC} ${FLAGS} $(lab)/*.cpp -o ${OUTPUT}/$(lab)/${EXECUTABLE}

execute:
	./${OUTPUT}/$(lab)/program

folder:
	mkdir -p ${OUTPUT}

clean:
	rm -r ${OUTPUT}
