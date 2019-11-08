#ifndef AGENDA_H_
#define AGENDA_H_

#include "data.h"
#include <iostream>
#include "paciente.h"
#include <string> 
#include 

struct Consulta 
{
	Consulta *proximo;
	Consulta *anterior;
	Data data;
	Hora hora;
	std::string paciente;
	std::string id = "";
};

class Agenda
{
	Consulta *inicio;
	Consulta *proxConsulta;
	Consulta *fim;
	Agenda();
	~Agenda();
	std::string consultarAgendaDia(int dia, int mes, int ano);
	std::string proximaConsulta();
	void adicionarConsulta(std::string paciente, int dia, int mes, int ano, int hora, int min);
	void desmarcarConsulta(int dia, int mes, int ano, int hora, int min);
	void desmarcarConsulta(std::string id);
	void fimConsulta();
};

#endif
