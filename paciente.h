#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "paciente.h"

using namespace std;

class Paciente : public Pessoa{
private:
	string psicologoResponsavel;
	string queixa; 
	float mensalidade;
	string prontuario;

public:
	// CONSTRUTORES E DESTRUTORES
	Paciente():Pessoa();
	Paciente(string, string, string, string, string, 
			string, string, float, string): 
			Pessoa(string, string, string, string, string);
	~Paciente();

	// SETTERS (Setar informação dos atributos da classe)
	void setPsicologoResponsavel(string);
	void setQueixa(string);
	void setMensalidade(float);
	void setProntuario(string);

	// GETTERS (Retornar informação dos atributos da classe)
	string getPsicologoResponsavel();
	string getQueixa();
	float getMensalidade();
	string getProntuario();
};

#endif