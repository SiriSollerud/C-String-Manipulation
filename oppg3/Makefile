CC = gcc
CFLAGS = -g -Wall -Wextra -std=gnu11

compile: clean
	gcc the_apple.c apple.c -o apple
run: compile
	./apple
clean:
	-rm apple
