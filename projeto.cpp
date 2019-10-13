#include "projeto.h"

// (PESSOA) CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
Pessoa::Pessoa(){
	this->ID = "";
	this->nome = "";
	this->endereco = "";
	this->telefone = "";
	this->dataInicio = "";
	this->dataFim = "";
}

Pessoa::Pessoa(string id, string nome, string endereco, string telefone, string dataInicio){
	this->ID = id;
	this->nome = nome;
	this->endereco = endereco;
	this->telefone = telefone;
	this->dataInicio = dataInicio;
	this->dataFim = "";
}

Pessoa::~Pessoa(){
	cout << "Destrutor" << endl;
}

// (PESSOA) SETTERS (Setar informação dos atributos da classe)
void Pessoa::setID(string ID){
	this->ID = ID;
}

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

// (PESSOA) GETTERS (Retornar informação dos atributos da classe)
string Pessoa::getID(){
	return this->ID;
}

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


// (PACIENTE) CONSTRUTORES E DESTRUTORES
Paciente::Paciente():Pessoa(){
	this->psicologoResponsavel = "";
	this->queixa = ""; 
	this->mensalidade = 0;
	this->prontuario = "";
}

Paciente::Paciente(string id, string nome, string endereco, string telefone, string dataInicio, 
		string pr, string queixa, float mensalidade, string prontuario): 
		Pessoa(id, nome, endereco, telefone, dataInicio)
{
	this->psicologoResponsavel = pr;
	this->queixa = queixa;
	this->mensalidade = mensalidade;
	this->prontuario = prontuario;
}

Paciente::~Paciente(){
	cout << "Destrutor Paciente";
}

// (PACIENTE) SETTERS (Setar informação dos atributos da classe)
void Paciente::setPsicologoResponsavel(string pr){
	this->psicologoResponsavel = pr;
}

void Paciente::setQueixa(string queixa){
	this->queixa = queixa;
}

void Paciente::setMensalidade(float mensalidade){
	this->mensalidade = mensalidade;
}

void Paciente::setProntuario(string prontuario){
	this->prontuario = prontuario;
}

// GETTERS (Retornar informação dos atributos da classe)
string Paciente::getPsicologoResponsavel(){
	return this->psicologoResponsavel;
}

string Paciente::getQueixa(){
	return this->queixa;
}

float Paciente::getMensalidade(){
	return this->mensalidade;
}

string Paciente::getProntuario(){
	return this->prontuario;
}	