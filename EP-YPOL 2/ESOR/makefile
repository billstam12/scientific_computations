CC=gcc

CFLAGS= -c -I.

all: esor

esor: main.o functions.o readmatrix.o esor.o
	$(CC) -o esor main.o functions.o readmatrix.o esor.o -lm -lrt

main.o: main.c
	$(CC) $(CFLAGS) main.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

readmatrix.o: readmatrix.c
	$(CC) $(CFLAGS) readmatrix.c

esor.o: esor.c
	$(CC) $(CFLAGS) esor.c -lm

clean:
	rm -f *.o esor
