GCC = gcc

FLAGS = -lm

.PHONY: all

all: jq

bst.o: bst.c bst.h
	${GCC} -c bst.c -o bst.o

object.o: object.c object.h
	${GCC} -c object.c -o object.o

main.o: main.c
	${GCC} -c main.c -o main.o

jq: bst.o main.o
	${GCC} main.o bst.o ${FLAGS} -o jq

test_bst.o: test_bst.c
	${GCC} -c test_bst.c -o test_bst.o

test_object.o: test_object.c
	${GCC} -c test_object.c ${FLAGS} -o test_object.o

test_bst: bst.o test_bst.o 
	${GCC} test_bst.o bst.o ${FLAGS} -o test_bst
	@./test_bst

test_object: bst.o object.o test_object.o
	${GCC} test_object.o object.o bst.o ${FLAGS} -o test_object
	@./test_object

clean:
	@rm *.o
