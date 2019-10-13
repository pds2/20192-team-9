#ifndef PROJETO_H
#define PROJETO_H

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