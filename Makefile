CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -lm

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = bin/reverse_logistics_cli

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
