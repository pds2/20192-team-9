#ifndef AGENDA_H_
#define AGENDA_H_

#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include <map>
#include <list>
#include <algorithm>

class Agenda
{
public:
	struct Dia {
		Dia(int dia, int mes, int ano, std::vector<int> horarios);
		std::string id;
		int dia;
		int mes;
		int ano;
		std::map<int, std::string> consultas;
		bool operator== (const Dia &d2) {
        	return (id == d2.id);
		}
	};
private:
	int aberturaClinica;
	int fechamentoClinica;
	std::list<Dia> dias;
	std::vector<int> horarios;
	void adicionarDia(int dia, int mes, int ano, std::vector<int> horarios);
    bool isDiaSemana(int dia, int mes, int ano);
public:
	Agenda(int inicio, int fim);
	void desmarcarConsulta(int dia, int mes, int ano, int hora);
	std::string getConsulta(int dia, int mes, int ano, int hora);
	void adicionarConsulta(std::string paciente, int dia, int mes, int ano, int hora);
	void imprimirConsultas();
};


#endif
