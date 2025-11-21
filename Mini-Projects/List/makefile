all:build

list.o : list.c
	gcc -Wall -Werror -c -g list.c -o list.o

test.o : test-list.c
	gcc -Wall -Werror -c -g test-list.c -o test.o

build: test.o list.o
	gcc test.o list.o -o test
	valgrind -s ./test
.PHONY : clean
clean: 
	rm -rf test
	rm -rf *.o 
