# Compiler settings
CC = gcc
CFLAGS = -g -Wall -Werror

# Default target (shows usage)
all:
	@echo "Usage: make <testname> (e.g., make test-linkedlist)"
	@echo "This will compile and run <testname>.c with linkedlist.c"

# Pattern rule:
# Build any test program when you type: make <name>
# Example: make test-linkedlist  → builds linkedlist.c + test-linkedlist.c
%: %.c linkedlist.c linkedlist.h
	@echo "🔧 Building $@ ..."
	$(CC) $(CFLAGS) linkedlist.c $@.c -o $@
	@echo "✅ Running $@ ..."
	./$@

# Optional fixed target for backwards compatibility
test: linkedlist.c test-linkedlist.c linkedlist.h
	@echo "🔧 Building default target 'test' ..."
	$(CC) $(CFLAGS) linkedlist.c test-linkedlist.c -o test
	@echo "✅ Running ./test ..."
	./test

# Clean rule
clean:
	@echo "🧹 Cleaning up..."
	rm -f *.o test test-linkedlist a.out

