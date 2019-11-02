#include "sistema.h"


Sistema::Sistema() {}

Sistema::~Sistema() {}

int Sistema::paginaInicial() {
	int entrada;
	while (true) {
		Sistema::limparTela();
		Sistema::mostrarOpcoes({"Entrar como Secretaria","Entrar como Psicologo","Cadastrar Secretaria","Cadastrar Psicologo","Sair Do Programa"});

		std::cin >> entrada;
		Sistema::limparTela();
		if (entrada == 1) {
			return 1;
		} else if (entrada == 2) {
			return 2;
		} else if (entrada == 3) {
			salvar(preencher({"Nome: ", "Endereco: ", "Telefone: ", "Data de Inicio:: "}), "secretaria.txt");
			std::cout << "Cadastro Realizado!";
			std::cin.get();
		} else if (entrada == 4) {
			salvar(preencher({"Nome: ", "Endereco: ", "Telefone: ", "Data de Inicio: ", "Numero CRP: "}), "psicologo.txt");
			std::cout << "Cadastro Realizado!";
			std::cin.get();
		} else if (entrada == 5) {
			return 5;
		}
	}
	
}

void Sistema::mostrarOpcoes(std::vector<std::string> opcoes)
{
	int i = 1;
	for(std::vector<std::string>::iterator it = opcoes.begin() ; it != opcoes.end(); it++) {
		std::cout << i << ". " << *it << std::endl;
		i++;
	}
}

void Sistema::limparTela() {
	#ifdef WINDOWS
		std::system("cls");
	#else
		std::system("clear");
	#endif
}

std::vector<std::string> Sistema::preencher(std::vector<std::string> campos) {
	std::cout << "Preencha os campos abaixo" << std::endl;
	std::cin.ignore();
	std::vector<std::string> dados;

	for(std::vector<int>::size_type i = 0; i != campos.size(); i++) {
		std::string entrada;
		std::cout << campos[i];
		getline(std::cin, entrada);
		dados.push_back(entrada);
	}
	return dados;
}

void Sistema::salvar(std::vector<std::string> dados, std::string arquivo) {
	std::ofstream pessoa;
	pessoa.open(arquivo, std::ios::app);
	for(std::vector<int>::size_type i = 0; i != dados.size(); i++) {
		pessoa << dados[i] << ",";
	}
	pessoa << std::endl;
	pessoa.close();
}