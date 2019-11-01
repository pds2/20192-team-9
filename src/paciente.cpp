#include "paciente.h"

// (PACIENTE) CONSTRUTORES E DESTRUTORES
Paciente::Paciente(std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio, std::string dataFim)
	:
	Pessoa(CPF, nome, endereco, telefone, dataInicio, dataFim),
	psicologoResponsavel(" - "),
	queixa(" - ")
{
	quantidadePacientes++;
}

int Paciente::quantidadePacientes = 0;

Paciente::Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio, 
		std::string pr, std::string queixa, float mensalidade, std::string prontuario)
		: 
		Pessoa(nome, endereco, telefone, dataInicio),
		psicologoResponsavel(pr),
		queixa(queixa);
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


// GETTERS (Retornar informação dos atributos da classe)
std::string Paciente::getPsicologoResponsavel(){
	return this->psicologoResponsavel;
}

std::string Paciente::getQueixa(){
	return this->queixa;
}

void Paciente::addEntrada(std::string CRP, std::string entrada){
	if (CRP==this->psicologoResponsavel){
		this->prontuario.push_back(entrada);
	}

}
