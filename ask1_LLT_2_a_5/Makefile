CC=gcc

CFLAGS= -c -I.

all: ergasia1

ergasia1: main.o functions.o readmatrix.o cholesky_decomposition.o
	$(CC) -o ergasia1 main.o functions.o readmatrix.o cholesky_decomposition.o -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

readmatrix.o: readmatrix.c
	$(CC) $(CFLAGS) readmatrix.c

cholesky_decomposition.o: cholesky_decomposition.c
	$(CC) $(CFLAGS) cholesky_decomposition.c -lm

clean:
	rm -f *.o ergasia1
