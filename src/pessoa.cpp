#include "pessoa.h"

// (PESSOA) CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
Pessoa::Pessoa()
	:
	CPF(" - "),
	nome(" - "),
	endereco(" - "),
	telefone(" - "),
	dataInicio(" - "),
	dataFim(" - ")
{
}

Pessoa::Pessoa(std::string nome, std::string endereco, std::string telefone, std::string dataInicio)
:
	CPF(CPF),
	nome(nome),
	endereco(endereco),
	telefone(telefone),
	dataInicio(dataInicio),
	dataFim(" - ")
{
}

Pessoa::~Pessoa(){
}

// (PESSOA) SETTERS (Setar informação dos atributos da classe)
void Pessoa::setCPF(std::string CPF){
	this->CPF = CPF;
}
void Pessoa::setEndereco(std::string endereco){
	this->endereco = endereco;
}

void Pessoa::setNome(std::string nome){
	this->nome = nome;
}

void Pessoa::setTelefone(std::string telefone){
	this->telefone = telefone;
}

void Pessoa::setDataInicio(std::string dataInicio){
	this->dataInicio = dataInicio;
}

void Pessoa::setDataFim(std::string dataFim){
	this->dataFim = dataFim;
}

void Pessoa::imprimirDados() {
	
}

// (PESSOA) GETTERS (Retornar informação dos atributos da classe)
std::string Pessoa::getCPF(){
	return this->CPF;
}

std::string Pessoa::getEndereco(){
	return this->endereco;
}

std::string Pessoa::getNome(){
	return this->nome;
}

std::string Pessoa::getTelefone(){
	return this->telefone;
}

std::string Pessoa::getDataInicio(){
	return this->dataInicio;
}

std::string Pessoa::getDataFim(){
	return this->dataFim;
}


