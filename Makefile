GCC = gcc

FLAGS = -lm

.PHONY: all

all: jq

heap.o: heap.c heap.h
	${GCC} -c heap.c -o heap.o

main.o: main.c
	${GCC} -c main.c -o main.o

jq: heap.o main.o
	${GCC} main.o heap.o ${FLAGS} -o jq

clean:
	@rm *.o
