#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
private:
	string nome;
	string endereco;
	string telefone;
	string dataInicio;
	string dataFim;

public:

	//CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
	Pessoa();
	Pessoa(string nome, string endereco, string telefone, string dataInicio);
	~Pessoa();

	// SETTERS (Setar informação dos atributos da classe)
	void setEndereco(string endereco);
	void setNome(string nome);
	void setTelefone(string telefone);
	void setDataInicio(string dataInicio);
	void setDataFim(string dataFim);
	void imprimirDados();
	// GETTERS (Retornar informação dos atributos da classe)
	string getEndereco();
	string getNome();
	string getTelefone();
	string getDataInicio();
	string getDataFim();
};

#endif