#include "paciente.h"

// (PACIENTE) CONSTRUTORES E DESTRUTORES
Paciente::Paciente()
	:
	psicologoResponsavel(""),
	queixa(""),
	mensalidade(0),
	prontuario("")
{
}

Paciente::Paciente(string id, string nome, string endereco, string telefone, string dataInicio, 
		string pr, string queixa, float mensalidade, string prontuario)
		: 
		Pessoa(id, nome, endereco, telefone, dataInicio),
		psicologoResponsavel(pr),
		queixa(queixa),
		mensalidade(mensalidade),
		prontuario(prontuario)
{
}

Paciente::~Paciente(){
	cout << "Destrutor Paciente" << endl;
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