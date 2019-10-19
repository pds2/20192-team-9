#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

class Pessoa{
protected:
	std::string nome;
	std::string endereco;
	std::string telefone;
	std::string dataInicio;
	std::string dataFim;

public:

	//CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
	Pessoa();
	Pessoa(std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
	~Pessoa();

	// SETTERS (Setar informação dos atributos da classe)
	void setEndereco(std::string endereco);
	void setNome(std::string nome);
	void setTelefone(std::string telefone);
	void setDataInicio(std::string dataInicio);
	void setDataFim(std::string dataFim);
	void imprimirDados();
	// GETTERS (Retornar informação dos atributos da classe)
	std::string getEndereco();
	std::string getNome();
	std::string getTelefone();
	std::string getDataInicio();
	std::string getDataFim();
};

#endif