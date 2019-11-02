#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "pessoa.h"
#include <vector>
#include <fstream>

class Paciente : public Pessoa{
private:
	std::string psicologoResponsavel;
	std::string queixa; 
	float mensalidade;
	std::vector<std::string> prontuario;
public:
	static int quantidade;
	static std::string nomeClasse;
	// CONSTRUTORES E DESTRUTORES
	Paciente(std::vector<std::string> dados);
	Paciente(std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
	~Paciente();

	// SETTERS (Setar informação dos atributos da classe)
	void setPsicologoResponsavel(std::string pr);
	void setQueixa(std::string queixa);
	
	// GETTERS (Retornar informação dos atributos da classe)
	void getInformacoes();
	std::string getPsicologoResponsavel();
	std::string getQueixa();

	void imprimirDados();
	static std::vector<std::string> cadastro;
	static std::string arquivo;
	
	//Para adicionar informações no prontuário"
	void addEntrada(std::string CRP, std::string entrada);

};

#endif