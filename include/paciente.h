#ifndef PACIENTE_H
#define PACIENTE_H

#include "pessoa.h"
#include <fstream>

class Paciente : public Pessoa{
private:
	std::string _psicologoResponsavel;
	std::string _queixa; 
	std::vector<std::string> prontuario;
public:
	
	// CONSTRUTORES
	Paciente(std::string cpf, std::string nome, std::string rua, std::string telefone, std::string dataInicio);
	Paciente(std::vector<std::string> dados);

	// SETTERS (Setar informação dos atributos da classe)
	void setPsicologoResponsavel(std::string pr);
	void setQueixa(std::string queixa);	
	void addQueixa(std::string queixa);
	// GETTERS (Retornar informação dos atributos da classe)
	std::string getPsicologoResponsavel();
	std::string getQueixa();

	void imprimirDados() override;
};

#endif