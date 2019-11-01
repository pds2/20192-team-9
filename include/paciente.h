#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "pessoa.h"

using namespace std;

class Paciente : public Pessoa{
private:
	string psicologoResponsavel;
	string queixa; 
	float mensalidade;
	string prontuario;

public:
	// CONSTRUTORES E DESTRUTORES
	Paciente();
	Paciente(string id, string nome, string endereco, string telefone, string dataInicio, 
		string pr, string queixa, float mensalidade, string prontuario);
	~Paciente();

	// SETTERS (Setar informação dos atributos da classe)
	void setPsicologoResponsavel(string pr);
	void setQueixa(string queixa);
	void setMensalidade(float mensalidade);
	void setProntuario(string prontuario);

	// GETTERS (Retornar informação dos atributos da classe)
	string getPsicologoResponsavel();
	string getQueixa();
	float getMensalidade();
	string getProntuario();
};

#endif