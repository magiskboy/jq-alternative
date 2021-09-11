GCC = gcc

FLAGS = -lm

BUILD = build

.PHONY: all

all: jq

bst.o: bst.c bst.h
	${GCC} -c bst.c -o bst.o

object.o: object.c object.h
	${GCC} -c object.c -o object.o

list.o: list.c list.h
	${GCC} -c list.c -o list.h

main.o: main.c
	${GCC} -c main.c -o main.o

jq: bst.o main.o
	${GCC} main.o bst.o ${FLAGS} -o ${BUILD}/jq

<<<<<<< Updated upstream
test: test.o test_bst.o test_object.o object.o bst.o
	${GCC} test.o test_bst.o test_object.o object.o bst.o ${FLAGS} -o ${BUILD}/test
	./build/test

test.o: ./test/main.c
	${GCC} -c ./test/main.c -o test.o
||||||| constructed merge base
test: test_bst test_object
=======
test: test_bst test_list test_object
>>>>>>> Stashed changes

test_bst.o: ./test/test_bst.c
	${GCC} -c ./test/test_bst.c -o test_bst.o

test_object.o: ./test/test_object.c
	${GCC} -c ./test/test_object.c ${FLAGS} -o test_object.o

<<<<<<< Updated upstream
||||||| constructed merge base
test_bst: bst.o test_bst.o 
	${GCC} test_bst.o bst.o ${FLAGS} -o ${BUILD}/test_bst
	@./${BUILD}/test_bst

test_object: bst.o object.o test_object.o
	${GCC} test_object.o object.o bst.o ${FLAGS} -o ${BUILD}/test_object
	@./${BUILD}/test_object

=======
test_list.o: ./test/test_list.c
	${GCC} -c ./test/test_list.c ${FLAGS} -o test_list.o

test_bst: bst.o test_bst.o 
	${GCC} test_bst.o bst.o ${FLAGS} -o ${BUILD}/test_bst
	@./${BUILD}/test_bst

test_list: list.o test_list.o
	${GCC} test_list.o list.o ${FLAGS} -o ${BUILD}/test_list
	@./${BUILD}/test_list

test_object: bst.o object.o test_object.o
	${GCC} test_object.o object.o bst.o ${FLAGS} -o ${BUILD}/test_object
	@./${BUILD}/test_object

>>>>>>> Stashed changes
clean:
	@rm *.o
	@rm -rf ${BUILD}
