#ifndef AGENDA_H_
#define AGENDA_H_

#include <iostream>
#include <string> 
#include "horario.h"

struct Consulta
{
	Horario horario[5];
	Data data;
	std::string id="";
	Consulta *proximo = nullptr;
	Consulta *anterior = nullptr;
};

class Agenda
{
	public:
		Agenda();
		~Agenda();
		void adicionarConsulta(std::string paciente, int dia, int mes, int ano, int hora);
		void desmarcarConsulta(std::string paciente, int dia, int mes, int ano);
		std::string consultarAgendaDia(int dia, int mes, int ano);
		std::string horarioDisponivel(int dia, int mes, int ano);
		void fimConsulta();

	protected:
		Consulta *inicio = nullptr;
		Consulta *proxConsulta = nullptr;
		Consulta *fim = nullptr;
		int hora[5];
};

#endif
