# Compiler to use
CC = gcc

# Compiler flags:
# -Wall = enable all warnings
# -g    = include debugging info
CFLAGS = -Wall -g

# Source file(s) and output executable name
SRC = portscanner.c
OUT = run

# Mark these targets as phony (not actual files)
.PHONY: all build run clean

# Default target: build and run the program
all: build run

# Build target: compile the source file into an executable
build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Run target: execute the program after building
run:
	./$(OUT) 

# Clean target: remove the


