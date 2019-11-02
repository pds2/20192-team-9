CC=g++


CFLAGS=-c -Wall -std=c++11

all: run

run: main.o usuarioSecretaria.o sistema.o pessoa.o paciente.o agenda.o 
	$(CC) main.o pessoa.o paciente.o agenda.o usuarioSecretaria.o  sistema.o -o sistemaClinica

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

sistema.o: sistema.cpp
	$(CC) $(CFLAGS) sistema.cpp

pessoa.o: pessoa.cpp
	$(CC) $(CFLAGS) pessoa.cpp

paciente.o: paciente.cpp
	$(CC) $(CFLAGS) paciente.cpp

agenda.o: agenda.cpp
	$(CC) $(CFLAGS) agenda.cpp

usuarioSecretaria.o: usuarioSecretaria.cpp
	$(CC) $(CFLAGS) usuarioSecretaria.cpp

usuarioPsicologo.o: usuarioPsicologo.cpp
	$(CC) $(CFLAGS) usuarioPsicologo.cpp

clean: 
	rm *.o *.txt sistemaClinica