#ifndef AGENDA_H_
#define AGENDA_H_

#include <string>
#include <iostream>
#include <stdbool.h>

struct Data_consulta
{
	int min, hora, dia, mes, ano;
};

struct Node
{
	std::string nome;
	Data_consulta data;
	Node *proximo;
	Node *anterior;

};

struct Agenda
{
	Node *inicio;
	Node *fim;
	Agenda();
	~Agenda();
	void marcar_consulta();
	void desmarcar_consulta(std::string paciente);
	void get_consulta(std::string paciente);
};


#endif
