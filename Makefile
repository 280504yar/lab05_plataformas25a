CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o arraydinamico.o
	$(CC) $(CFLAGS) -o main main.o arraydinamico.o
main.o: main.c arraydinamico.h
	$(CC) $(CFLAGS) -c main.c
arraydinamico.o: arraydinamico.c arraydinamico.h
	$(CC) $(CFLAGS) -c arraydinamico.c
clean:
	rm -f *.o main

