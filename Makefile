CC=g++
OUTPUT=out
FLAGS='-fopenmp'
EXECUTABLE=program


build: folder
	mkdir -p ${OUTPUT}/$(LAB)
	${CC} ${FLAGS} $(LAB)/*.cpp -o ${OUTPUT}/$(LAB)/${EXECUTABLE}

execute:
	./${OUTPUT}/$(LAB)/program $(ARGS)

folder:
	mkdir -p ${OUTPUT}

clean:
	rm -r ${OUTPUT}
