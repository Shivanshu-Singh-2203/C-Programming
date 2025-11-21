all: build

bigint.o : bigint.c
	gcc -Wall -g -c bigint.c -o bigint.o

list.o : list.c
	gcc -Wall -g -c list.c -o list.o

test-bigint.o : test-bigint.c
	gcc -Wall -g -c test-bigint.c -o test-bigint.o

test-bigint : list.o test-bigint.o bigint.o
	gcc test-bigint.o bigint.o list.o -o test-bigint
4.o : 4.c
	gcc -Werror -g -c 4.c -o 4.o

build : 4.o bigint.o list.o test-bigint.o
	gcc list.o bigint.o 4.o -o 4

mytest:
	gcc list.o bigint.o -o mytest
#####################
# Do not edit below #
#####################

run: build
	@echo "Running the program\n"
	@$(PROJ_HOME)/$(NAME)

clean:
	rm -f $(NAME) run.log leaks.log *.o test-bigint t 

tests: clean build
	@echo 'Running local test-suite'
	@$(TESTS_DIR)/verifier --proj-dir=$(PROJ_HOME) --proj-name=$(NAME) --tests-dir=$(TESTS_DIR)
	@cat run.log
	@echo 'Finished running all test cases'

ltests: clean build
	@echo 'Running valgrind for test-suite'
	@echo 'Hang in tight ... while we test'
	@$(TESTS_DIR)/leakcheck --proj-dir=$(PROJ_HOME) --proj-name=$(NAME) --tests-dir=$(TESTS_DIR)
	@cat leaks.log
	@echo 'Finished running valgrind on test cases'
