GCC = gcc

FLAGS = -lm

.PHONY: all

all: jq

bst.o: bst.c bst.h
	${GCC} -c bst.c -o bst.o

main.o: main.c
	${GCC} -c main.c -o main.o

jq: bst.o main.o
	${GCC} main.o bst.o ${FLAGS} -o jq

test_bst.o: test_bst.c
	${GCC} -c test_bst.c -o test_bst.o

test_bst: bst.o test_bst.o 
	${GCC} test_bst.o bst.o ${FLAGS} -o test_bst
	@./test_bst

clean:
	@rm *.o
