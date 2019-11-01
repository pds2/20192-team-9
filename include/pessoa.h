#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
protected:
	int ID;
	string cpf;
	string nome;
	string endereco;
	string telefone;
	string dataInicio;
	string dataFim;

public:

	//CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
	Pessoa();
	Pessoa(string id, string nome, string endereco, string telefone, string dataInicio);
	~Pessoa();

	// SETTERS (Setar informação dos atributos da classe)
	void setID(string ID);
	void setEndereco(string endereco);
	void setNome(string nome);
	void setTelefone(string telefone);
	void setDataInicio(string dataInicio);
	void setDataFim(string dataFim);

	// GETTERS (Retornar informação dos atributos da classe)
	string getID();
	string getEndereco();
	string getNome();
	string getTelefone();
	string getDataInicio();
	string getDataFim();
};

#endif