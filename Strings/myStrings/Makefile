CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11

# Files
SRC     := mystring.c test-mystring.c
OBJ     := $(SRC:.c=.o)
TARGET  := test

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c mystring.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

