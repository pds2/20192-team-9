#include "paciente.h"

// (PACIENTE) CONSTRUTORES E DESTRUTORES
Paciente::Paciente(std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio)
	:
	Pessoa(CPF, nome, endereco, telefone, dataInicio),
	psicologoResponsavel(" - "),
	queixa(" - ")
{
	quantidade++;
}

Paciente::Paciente(std::vector<std::string> dados) 
	:
	Paciente(dados[0], dados[1], dados[2], dados[3], dados[4])
{
}

int Paciente::quantidade = 0;

std::string Paciente::nomeClasse = "paciente";

std::vector<std::string> Paciente::dados = {"Nome", "Endereco", "Telefone", "Data Inicio", "Data Fim", "Psicologo Responsavel", "Queixa", "Mensalidade"};

Paciente::~Paciente(){
} 

// (PACIENTE) SETTERS (Setar informação dos atributos da classe)
void Paciente::setPsicologoResponsavel(std::string pr){
	this->psicologoResponsavel = pr;
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

void Paciente::imprimirDados() {
	std::cout << nome << " | " << endereco << " | " << telefone << " | " << dataInicio << " | " << dataFim << " | " <<
	psicologoResponsavel << " | " << queixa << " | " << mensalidade << std::endl;
}

void Paciente::setInformacao(std::string inf) {
	this->queixa = inf;
}

std::string Paciente::arquivo = "paciente.txt";

std::vector<std::string> Paciente::cadastro = {"CPF: ", "Nome: ", "Endereco: ", "Telefone: ", "Data de Inicio: "};
