#include "paciente.h"

// CONSTRUTORES
Paciente::Paciente(std::string cpf, std::string nome, std::string rua, std::string telefone, std::string dataInicio)
	:
	Pessoa(cpf, nome, rua, telefone, dataInicio),
	_psicologoResponsavel("-"),
	_queixa("-")
{
}

Paciente::Paciente(std::vector<std::string> dados) 
	:
	Paciente(dados[0], dados[1], dados[2], dados[3], dados[4])
{
}

// SETTERS
void Paciente::setQueixa(std::string queixa){
	this->_queixa = queixa;
}

void Paciente::addQueixa(std::string queixa) {
	this->_queixa += queixa;
}

void Paciente::setPsicologoResponsavel(std::string pr){
	this->_psicologoResponsavel = pr;
}

// GETTERS
std::string Paciente::getPsicologoResponsavel(){
	return this->_psicologoResponsavel;
}

std::string Paciente::getQueixa(){
	return this->_queixa;
}

void Paciente::imprimirDados() {
	std::cout << "Nome:" <<_nome << "\tEndereco:"  << _rua << " \tTelefone:"  << _telefone << "\tData de Inicio:"  
	<< _dataInicio << "\tPsicologo Responsavel:" << _psicologoResponsavel << std::endl << "Queixa:" << _queixa << std::endl;
}