CC = gcc
CFLAGS = -Wall -O2 -Werror

# Default rule: when you run `make "file name"`
# It compiles "file name.c", then runs it, then valgrinds it.
%: %.c
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) "$<" -o "$@"

	@echo ""
	@echo "Running $@ ..."
	@"./$@"

	@echo ""
	@echo "Running valgrind on $@ ..."
	@valgrind "./$@"

clean:
	@echo "Cleaning..."
	find . -maxdepth 1 -type f -executable \
		! -name "*.c" \
		! -name "makefile" \
		-delete
	rm -f *.o *~ *.out *.tmp

