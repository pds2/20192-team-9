#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "pessoa.h"
#include <vector>

class Paciente : public Pessoa{
private:
	std::string psicologoResponsavel;
	std::string queixa; 
	std::vector<std::string> prontuario;

public:
	static int quantidadePacientes;
	// CONSTRUTORES E DESTRUTORES
	Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
	Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio, 
		std::string pr, std::string queixa);
	~Paciente();

	// SETTERS (Setar informação dos atributos da classe)
	void setPsicologoResponsavel(std::string pr);
	void setQueixa(std::string queixa);
	
	// GETTERS (Retornar informação dos atributos da classe)
	std::string getPsicologoResponsavel();
	std::string getQueixa();

	//Para adicionar informações no prontuário"
	void addEntrada(std::string CRP, std::string entrada);

};

#endif