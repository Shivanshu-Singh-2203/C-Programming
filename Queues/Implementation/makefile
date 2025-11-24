all : clean main

queue.o : queue.c 
	gcc -g -Wextra -Werror -c queue.c -o queue.o

test-queue.o : test-queue.c
	gcc -g -Wextra -Werror -c test-queue.c -o test-queue.o

test : test-queue.o queue.o 
	gcc test-queue.o queue.o -o test
	valgrind --leak-check=full ./test

main.o : main.c
	gcc -g -Werror -Wextra -c main.c -o main.o

main : main.o queue.o 
	gcc main.o queue.o -o main

.PHONY  : clean
clean : 
	rm -rf *.o test main

