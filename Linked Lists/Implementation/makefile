# Compiler
CC = gcc
CFLAGS = -g -Werror

# Target executable
TARGET = test

# Source files
SRCS = linkedlist.c test-linkedlist.c

# Object files
OBJS = linkedlist.o test-linkedlist.o

# Default target
all: $(TARGET)

# Compile linkedlist.c to object file
linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c -o linkedlist.o

# Compile test-linkedlist.c to object file
test-linkedlist.o: test-linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c test-linkedlist.c -o test-linkedlist.o

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	./$(TARGET)
# Clean generated files
clean:
	rm -f $(OBJS) $(TARGET)

