CC = gcc
CFLAGS = -g -Wall -Wextra -std=gnu11

compile: clean
	gcc tests.c stringoperations.c -o ferdig_program
run: compile
	./ferdig_program
clean:
	-rm ferdig_program
