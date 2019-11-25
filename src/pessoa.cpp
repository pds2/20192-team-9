#include "pessoa.h"

// (PESSOA) CONSTRUTORES E DESTRUTORES (Criando e destruindo o objeto)
Pessoa::Pessoa(std::string cpf, std::string nome, std::string rua, std::string telefone, std::string dataInicio)
{
	// Tratamento e armazenamento
	if(!isNumero(cpf))
		throw std::invalid_argument("CPF Invalido! Digite apenas numeros");
	if(!isCpfValido(cpf))
		throw std::invalid_argument("CPF Invalido!");
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

bool Pessoa::isCpfValido(std::string cpf){
	int cpfFinal[11];
	if(cpf.length() != 11)
		return false;
	else {
		for(unsigned int i=0; i<cpf.length();i++) {
			int number = (int)cpf[i]-'0';
			if(number < 0 || number>9)
				return false;
			else
				cpfFinal[i]=number;
		}
		int dezena, unidade;
		int soma1 = (cpfFinal[0]*10+cpfFinal[1]*9+cpfFinal[2]*8+cpfFinal[3]*7+cpfFinal[4]*6+cpfFinal[5]*5+cpfFinal[6]*4+cpfFinal[7]*3+cpfFinal[8]*2);
		int resto1 = soma1%11;
		if (resto1==0 || resto1==1)
			dezena = 0;
		else
			dezena = 11-resto1;
		int soma2 = (dezena*2+cpfFinal[0]*11+cpfFinal[1]*10+cpfFinal[2]*9+cpfFinal[3]*8+cpfFinal[4]*7+cpfFinal[5]*6+cpfFinal[6]*5+cpfFinal[7]*4+cpfFinal[8]*3);
		int resto2 = soma2%11;
		if (resto2 == 0 || resto2 == 1)
			unidade = 0;
		else 
			unidade = 11-resto2;
		if(cpfFinal[9]!=dezena||cpfFinal[10]!=unidade)
			return false;
		else
			return true;
	}
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
    std::cout << "Nome:" <<_nome << "\t CPF:"<< _cpf <<" \tEndereco:" << _rua << " \tTelefone:" << _telefone << " \tData de Inicio:" << _dataInicio << std::endl;
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
