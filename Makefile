CC=g++
OUTPUT=out
FLAGS='-fopenmp'
EXECUTABLE=program


build: folder
	mkdir -p ${OUTPUT}/$(LAB)
	${CC} ${FLAGS} $(CFLAGS) $(LAB)/*.cpp -o ${OUTPUT}/$(LAB)/${EXECUTABLE}

execute:
	./${OUTPUT}/$(LAB)/program $(ARGS)

run: folder build execute

folder:
	mkdir -p ${OUTPUT}

clean:
	rm -r ${OUTPUT}
