CC=g++


CFLAGS=-c -Wall -std=c++11

all: run

run: main.o
	$(CC) main.o -o sistemaClinica

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean: 
	rm *.o sistemaClinica.exe