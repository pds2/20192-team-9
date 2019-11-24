#include "psicologo.h"

Psicologo::Psicologo(std::string cpf, std::string nome, std::string endereco, std::string telefone, std::string dataInicio, std::string crp, std::string inicioExpediente, std::string fimExpediente) 
	:
	Pessoa(cpf, nome, endereco, telefone, dataInicio)
{
	if(!isNumero(crp))
		throw std::invalid_argument("CRP Invalido! Digite apenas numeros");
	this->_crp = crp;

	int inicio, fim;
	if(!isNumero(inicioExpediente) || !isNumero(fimExpediente))
		throw std::invalid_argument("Hora Invalida! Digite apenas numeros");
	std::istringstream iniciostream(inicioExpediente);
	std::istringstream fimstream(fimExpediente);
	iniciostream >> inicio;
	fimstream >> fim;
	if(inicio > fim)
		throw std::invalid_argument("Hora Invalida! Inicio maior que o fim");

	agenda = new Agenda(inicio, fim);
}

Psicologo::Psicologo(std::vector<std::string> dados) 
	:
	Psicologo(dados[0], dados[1], dados[2], dados[3], dados[4], dados[5], dados[6], dados[7])
{
}

std::string Psicologo::getCRP(){
	return this->_crp;
}

// OPERACOES AGENDA
void Psicologo::adicionarConsulta(std::string in_paciente, std::string in_dia, std::string in_mes, std::string in_ano, std::string in_hora) {
	int dia = converterParaInteiro(in_dia);
	int mes = converterParaInteiro(in_mes);
	int ano = converterParaInteiro(in_ano);
	int hora = converterParaInteiro(in_hora);
	agenda->adicionarConsulta(in_paciente, dia, mes, ano, hora);
}

void Psicologo::desmarcarConsulta(std::string in_dia, std::string in_mes, std::string in_ano, std::string in_hora) {
	int dia = converterParaInteiro(in_dia);
	int mes = converterParaInteiro(in_mes);
	int ano = converterParaInteiro(in_ano);
	int hora = converterParaInteiro(in_hora);
	agenda->desmarcarConsulta(dia, mes, ano, hora);
}

std::string Psicologo::getConsulta(std::string in_dia, std::string in_mes, std::string in_ano, std::string in_hora) {
	int dia = converterParaInteiro(in_dia);
	int mes = converterParaInteiro(in_mes);
	int ano = converterParaInteiro(in_ano);
	int hora = converterParaInteiro(in_hora);
	return agenda->getConsulta(dia, mes, ano, hora);
}

void Psicologo::imprimirConsultas() {
	agenda->imprimirConsultas();
}
