#include "psicologo.h"

Psicologo::Psicologo(
			std::string CPF,
			std::string nome,
			std::string endereco,
			std::string telefone,
			std::string dataInicio,
			std::string CRP) : Pessoa(CPF, nome, endereco, telefone, dataInicio), CRP(CRP) { 
				this->agenda = new Agenda();
}

Psicologo::~Psicologo(){
	delete this->agenda;
}

std::string Psicologo::consultarAgendaDia(){
	return consultarAgendaDia();
}

std::string Psicologo::proximaConsulta(){
	return proximaConsulta();
}

std::string Psicologo::adicionarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora){
	return adicionarConsulta(dia, mes, ano, paciente, hora);
}

void Psicologo::desmarcarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora){
	desmarcarConsulta(dia, mes, ano, paciente, hora);
}

void Psicologo::setCRP(std::string CRP){
	this->CRP=CRP;
}
void Psicologo::setAgenda(Agenda * agenda){
	this->agenda = agenda;
}

std::string Psicologo::getCRP(){
	return this->CRP;
}

Agenda* Psicologo::getAgenda(){
	return this->agenda;
}