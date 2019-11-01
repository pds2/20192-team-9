#include "psicologo.h"

Psicologo::Psicologo(
			std::string CRP,
			std::string nome,
			std::string endereco,
			std::string telefone,
			std::string dataInicio) : Pessoa(CPF, nome, endereco, telefone, dataInicio), CRP(CRP) { 
				this->agenda = new Agenda();
}

Psicologo::~Psicologo(){
	delete this->agenda;
}

std::string Psicologo::consultarAgendaDia(Psicologo * p){
	return p->agenda->consultarAgendaDia();
}

std::string Psicologo::proximaConsulta(Psicologo * p){
	return p->agenda->proximaConsulta();
}

std::string Psicologo::adicionarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora){
	return p->agenda->adicionarConsulta(dia, mes, ano, paciente, hora);
}

std::string Psicologo::desmarcarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora){
	return p->agenda->desmarcarConsulta(dia, mes, ano, paciente, hora);
}

void Psicologo::editarProntuario(Paciente * p, std::string entrada){
	p->addEntrada(this->CRP, entrada);
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

Agenda Psicologo::getAgenda(){
	return this->agenda;
}