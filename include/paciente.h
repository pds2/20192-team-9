#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "pessoa.h"

class Paciente : public Pessoa{
private:
	std::string psicologoResponsavel;
	std::string queixa; 
	float mensalidade;
	std::string prontuario;

public:
	static int quantidadePacientes;
	// CONSTRUTORES E DESTRUTORES
	Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
	Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio, 
		std::string pr, std::string queixa, float mensalidade, std::string prontuario);
	~Paciente();

	// SETTERS (Setar informação dos atributos da classe)
	void setPsicologoResponsavel(std::string pr);
	void setQueixa(std::string queixa);
	void setMensalidade(float mensalidade);
	void setProntuario(std::string prontuario);

	// GETTERS (Retornar informação dos atributos da classe)
	std::string getPsicologoResponsavel();
	std::string getQueixa();
	float getMensalidade();
	std::string getProntuario();

	void imprimirDados();
};

#endif