CC=g++


CFLAGS=-c -Wall

all: run

run: main.o
	$(CC) main.o -o sistemaClinica

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean: 
	rm *.o sistemaClinica.exe