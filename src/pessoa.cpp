#include "pessoa.h"

// (PESSOA) CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
Pessoa::Pessoa(std::string cpf, std::string nome, std::string rua, std::string telefone, std::string dataInicio)
{
	// Tratamento e armazenamento
	if(!isNumero(cpf))
		throw std::invalid_argument("CPF Invalido! Digite apenas numeros");
	this->_cpf = cpf;

	if(!isLetra(nome))
		throw std::invalid_argument("Nome Invalido! Digite apenas letras e espacos");
	this->_nome = nome;

	if(!isLetra(rua))
		throw std::invalid_argument("Rua Invalida! Digite apenas letras e espacos");
	this->_rua = rua;

	if(!isNumero(telefone))
		throw std::invalid_argument("Telefone Invalido! Digite apenas numeros");
	this->_telefone = telefone;

	if(!isNumero(dataInicio))
		throw std::invalid_argument("Data Invalida! Digite apenas numeros");
	this->_dataInicio = dataInicio;
}

Pessoa::Pessoa(std::vector<std::string> dados)
	:
	Pessoa(dados[0], dados[1], dados[2], dados[3], dados[4])
{
}

bool Pessoa::isNumero(std::string s) {
	bool isDigit = true;
	for(std::string::iterator it = s.begin(); it != s.end(); it++) 
		isDigit = isDigit && std::isdigit(*it);
	return !s.empty() && isDigit;
}

bool Pessoa::isLetra(std::string s) {
	bool isLetter = true;
	for(std::string::iterator it = s.begin(); it != s.end(); it++) 
		isLetter = isLetter && (isalpha(*it) || std::isspace(*it));
	return !s.empty() && isLetter;
}


// (PESSOA) GETTERS (Retornar informação dos atributos da classe)
std::string Pessoa::getCPF(){
	return this->_cpf;
}

std::string Pessoa::getRua(){
	return this->_rua;
}

std::string Pessoa::getNome(){
	return this->_nome;
}

std::string Pessoa::getTelefone(){
	return this->_telefone;
}

std::string Pessoa::getDataInicio(){
	return this->_dataInicio;
}

void Pessoa::imprimirDados() {
    std::cout << _nome << " |\t" << _rua << " |\t" << _telefone << " |\t" << _dataInicio << " |\t" << std::endl;
}

int Pessoa::converterParaInteiro(std::string &s) {
	int inteiro = 0;
	bool isDigit = true;

	for(std::string::iterator it = s.begin(); it != s.end(); it++) 
		isDigit = isDigit && std::isdigit(*it);
	isDigit  = !s.empty() && isDigit;
	if(!isDigit)
		throw std::invalid_argument("Entrada Invalida! Digite um numero");
	std::istringstream stream(s);
	stream >> inteiro;

	return inteiro;
}