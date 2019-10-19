CC=g++


CFLAGS=-c -Wall -std=c++11

all: run

run: main.o sistema.o pessoa.o paciente.o 
	$(CC) main.o pessoa.o paciente.o sistema.o -o sistemaClinica

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

sistema.o: sistema.cpp
	$(CC) $(CFLAGS) sistema.cpp

pessoa.o: pessoa.cpp
	$(CC) $(CFLAGS) pessoa.cpp

paciente.o: paciente.cpp
	$(CC) $(CFLAGS) paciente.cpp


clean: 
	rm *.o sistemaClinica