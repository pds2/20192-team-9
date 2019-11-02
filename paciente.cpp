#include "paciente.h"

// (PACIENTE) CONSTRUTORES E DESTRUTORES
Paciente::Paciente(std::string nome, std::string endereco, std::string telefone, std::string dataInicio)
	:
	Pessoa(nome, endereco, telefone, dataInicio),
	psicologoResponsavel(" - "),
	queixa(" - "),
	mensalidade(0),
	prontuario(" - ")
{
	quantidade++;
}

Paciente::Paciente(std::vector<std::string> dados) 
	:
	Paciente(dados[0], dados[1], dados[2], dados[3])
{
}

int Paciente::quantidade = 0;

std::string Paciente::nomeClasse = "paciente";

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
	std::cout << nome << " | " << endereco << " | " << telefone << " | " << dataInicio << " | " << dataFim << " | " <<
	psicologoResponsavel << " | " << queixa << " | " << mensalidade << std::endl;
}

std::string Paciente::arquivo = "paciente.txt";

std::vector<std::string> Paciente::cadastro = {"Nome: ", "Endereco: ", "Telefone: ", "Data de Inicio: "};
