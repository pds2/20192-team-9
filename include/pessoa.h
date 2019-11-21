#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Pessoa{
protected:
	std::string _cpf;
	std::string _nome;
	std::string _rua;
	std::string _telefone;
	std::string _dataInicio;
	bool isNumero(std::string s); 	// Checa se a string e composta completamente por numeros
	bool isLetra(std::string s);	// Checa se a string e composta completamente por letras e espacos
	int converterParaInteiro(std::string &s);
public:
	//CONSTRUTORES
	Pessoa(std::string cpf, std::string nome, std::string rua, std::string telefone, std::string dataInicio);
	Pessoa(std::vector<std::string> dados);
	// GETTERS
	std::string getCPF();
	std::string getRua();
	std::string getNome();
	std::string getTelefone();
	std::string getDataInicio();
	virtual void imprimirDados();

};

#endif