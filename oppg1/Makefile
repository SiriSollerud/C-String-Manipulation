CC = gcc
CFLAGS = -g -Wall -Wextra -std=gnu11

compile: clean
	gcc vowelshift.c -o vowelshift
run: compile
	./vowelshift 'LET us take out ALL the vowels' s
clean:
	-rm vowelshift
