all: 
	gcc stack.o main.o -o main

main.o : main.c 
	gcc -g -Wall -c main.c -o main.o

stack.o : stack.o
	gcc -g -Wall -c stack.c -o stack.o

.PHONY : clean
clean: 
	rm -rf *.o main

