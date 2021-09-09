GCC = gcc

FLAGS = -lm

BUILD = build

.PHONY: all

all: jq

bst.o: bst.c bst.h
	${GCC} -c bst.c -o bst.o

object.o: object.c object.h
	${GCC} -c object.c -o object.o

main.o: main.c
	${GCC} -c main.c -o main.o

jq: bst.o main.o
	${GCC} main.o bst.o ${FLAGS} -o ${BUILD}/jq

test: test.o test_bst.o test_object.o object.o bst.o
	${GCC} test.o test_bst.o test_object.o object.o bst.o ${FLAGS} -o ${BUILD}/test
	./build/test

test.o: ./test/main.c
	${GCC} -c ./test/main.c -o test.o

test_bst.o: ./test/test_bst.c
	${GCC} -c ./test/test_bst.c -o test_bst.o

test_object.o: ./test/test_object.c
	${GCC} -c ./test/test_object.c ${FLAGS} -o test_object.o

clean:
	@rm *.o
	@rm -rf ${BUILD}
