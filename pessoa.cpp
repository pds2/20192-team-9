#include "pessoa.h"

// (PESSOA) CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
Pessoa::Pessoa()
	:
	nome(""),
	endereco(""),
	telefone(""),
	dataInicio(""),
	dataFim("")
{
}

Pessoa::Pessoa(string nome, string endereco, string telefone, string dataInicio)
:
	nome(nome),
	endereco(endereco),
	telefone(telefone),
	dataInicio(dataInicio),
	dataFim("")
{
}

Pessoa::~Pessoa(){
}

// (PESSOA) SETTERS (Setar informação dos atributos da classe)
void Pessoa::setEndereco(string endereco){
	this->endereco = endereco;
}

void Pessoa::setNome(string nome){
	this->nome = nome;
}

void Pessoa::setTelefone(string telefone){
	this->telefone = telefone;
}

void Pessoa::setDataInicio(string dataInicio){
	this->dataInicio = dataInicio;
}

void Pessoa::setDataFim(string dataFim){
	this->dataFim = dataFim;
}

void Pessoa::imprimirDados() {
	
}

// (PESSOA) GETTERS (Retornar informação dos atributos da classe)
string Pessoa::getEndereco(){
	return this->endereco;
}

string Pessoa::getNome(){
	return this->nome;
}

string Pessoa::getTelefone(){
	return this->telefone;
}

string Pessoa::getDataInicio(){
	return this->dataInicio;
}

string Pessoa::getDataFim(){
	return this->dataFim;
}


