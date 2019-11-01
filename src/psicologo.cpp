#include "psicologo.h"

Psicologo::Psicologo(
			std::string numeroCRP,
			std::string id,
			std::string nome,
			std::string endereco,
			std::string telefone,
			std::string dataInicio) : Pessoa(id, nome, endereco, telefone, dataInicio), numeroCRP(numeroCRP) { }

Psicologo::~Psicologo(){}

void Psicologo::imprimirDados(){

}

void Psicologo::setProntuarioPaciente(){

}

void Psicologo::setNumeroCRP(std::string numeroCRP){
	this->numeroCRP=numeroCRP;
}

std::string Psicologo::getNumeroCRP(){
	return this->numeroCRP;
}
