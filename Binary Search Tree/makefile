CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pg

TARGET = test-binary-search-tree
SRC = binary-search-tree.c test-binary-search-tree.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c binary-search-tree.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) *.out
