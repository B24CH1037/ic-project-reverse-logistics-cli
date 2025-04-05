# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -lm

# Source files: This wildcard picks up all .c files in the src directory,
# including modules like return_classification.c and resale_prediction.c.
SRC = $(wildcard src/*.c)
# Object files: Convert each source file (.c) path to its corresponding object file (.o)
OBJ = $(SRC:.c=.o)

# Target executable location
TARGET = bin/reverse_logistics_cli

# Default target: Build the executable
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Pattern rule: compile each .c file in the src folder into a corresponding .o file
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
