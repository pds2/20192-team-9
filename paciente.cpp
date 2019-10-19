#include "paciente.h"

// (PACIENTE) CONSTRUTORES E DESTRUTORES
Paciente::Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio)
	:
	Pessoa(nome, endereco, telefone, dataInicio),
	psicologoResponsavel(""),
	queixa(""),
	mensalidade(0),
	prontuario("")
{
	quantidadePacientes++;
}

int Paciente::quantidadePacientes = 0;

Paciente::Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio, 
		std::string pr, std::string queixa, float mensalidade, std::string prontuario)
		: 
		Pessoa(nome, endereco, telefone, dataInicio),
		psicologoResponsavel(pr),
		queixa(queixa),
		mensalidade(mensalidade),
		prontuario(prontuario)
{
}

Paciente::~Paciente(){
} 

// (PACIENTE) SETTERS (Setar informação dos atributos da classe)
void Paciente::setPsicologoResponsavel(std::string pr){
	this->psicologoResponsavel = pr;
}

void Paciente::setQueixa(std::string queixa){
	this->queixa = queixa;
}

void Paciente::setMensalidade(float mensalidade){
	this->mensalidade = mensalidade;
}

void Paciente::setProntuario(std::string prontuario){
	this->prontuario = prontuario;
}

// GETTERS (Retornar informação dos atributos da classe)
std::string Paciente::getPsicologoResponsavel(){
	return this->psicologoResponsavel;
}

std::string Paciente::getQueixa(){
	return this->queixa;
}

float Paciente::getMensalidade(){
	return this->mensalidade;
}

std::string Paciente::getProntuario(){
	return this->prontuario;
}

void Paciente::imprimirDados() {
}