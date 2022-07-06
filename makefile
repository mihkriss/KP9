CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g
SRC = vector.c kp9.c
PROG = kp9

build:
	$(CC) $(CFLAGS) $(SRC) -o $(PROG)

clean:
	rm $(PROG)

