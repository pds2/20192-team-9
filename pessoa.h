#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
private:
	string ID;
	string nome;
	string endereco;
	string telefone;
	string dataInicio;
	string dataFim;

public:

	//CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
	Pessoa();
	Pessoa(string, string, string, string, string);
	~Pessoa();

	// SETTERS (Setar informação dos atributos da classe)
	void setID(string);
	void setEndereco(string);
	void setNome(string);
	void setTelefone(string);
	void setDataInicio(string);
	void setDataFim(string);

	// GETTERS (Retornar informação dos atributos da classe)
	string getID();
	string getEndereco();
	string getNome();
	string getTelefone();
	string getDataInicio();
	string getDataFim();
};

#endif