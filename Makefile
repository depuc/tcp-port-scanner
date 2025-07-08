CC = gcc
CFLAGS = -Wall -g

SRC = portscanner.c
OUT = run

.PHONY: all build run clean

all: build run

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT) 

clean:
	rm -f $(OUT)

