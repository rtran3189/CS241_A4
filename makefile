all: lltest main

clean:
	rm lltest main

lltest: ll.h ll.c lltest.c help.c
	gcc -Wall -ansi -pedantic -g -o lltest lltest.c ll.c help.c

main: ll.h ll.c help.c main.c parse.c
	gcc -Wall -ansi -pedantic -g -o main ll.c main.c help.c parse.c

