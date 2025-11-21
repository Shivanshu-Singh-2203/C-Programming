all : build

matrix.o : matrix.c 
	gcc -g -c matrix.c -o matrix.o

main.o : main.c matrix.o 
	gcc -g -c main.c -o main.o

build : 
	gcc main.o matrix.o -o main
	./main	

test : test-matrix.c matrix.o
	gcc -g -c test-matrix.c -o testmatrix.o
	gcc  testmatrix.o matrix.o -o test
	./test
	valgrind --leak-check=full ./test

.PHONY : clean
clean : 
	rm -rf *.o test main
