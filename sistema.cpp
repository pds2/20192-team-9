#include "sistema.h"

Sistema::Sistema()
{
}

void Sistema::mostrarOpcoes(std::string opcoes[])
{
	int i = 0;
	while (opcoes[i] != "end")
	{
		std::cout << i + 1 << "." << opcoes[i] << std::endl;
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

void Sistema::cadastrar(std::string tipo)
{
	std::ofstream pessoa;
	pessoa.open(tipo, std::ios::app);

	std::string dados[5];
	std::cout << "Preencha os dados abaixo" << std::endl;
	std::cout << "Nome: ";
	std::cin.ignore();
	getline(std::cin, dados[0]);
	std::cout << "Endereco: ";
	getline(std::cin, dados[1]);
	std::cout << "Telefone: ";
	getline(std::cin, dados[2]);
	std::cout << "Data de Inicio: ";
	getline(std::cin, dados[3]);

	pessoa << dados[0] << ", " << dados[1] << ", " << dados[2] << ", " << dados[3] << ", ";

	if(tipo == "psicologo.txt")
	{
		std::cout << "Numero CRP:";
		getline(std::cin, dados[4]);
		pessoa << dados[4] <<  std::endl;
	} else {
		pessoa << std::endl;
		if(tipo == "paciente.txt") {
			pacientes.push_back(Paciente(dados[0], dados[1], dados[2], dados[3]));
		}

	}
	pessoa.close();

	std::cout << "Pessoa cadastrada!" << std::endl;
	std::cin.get();
}

void Sistema::ambienteSecretaria()
{
	std::string opcoes[] = {"Visualizar Pacientes","Visualizar Quantidade de Pacientes Cadastrados","Cadastrar Pacientes", "Voltar para Pagina Inicial", "end"};
	int entrada;

	while (true) {
		limparTela();
		mostrarOpcoes(opcoes);
		std::cin >> entrada;
		limparTela();
		if (entrada == 1) {
			imprimirPacientes();
			
		} else if (entrada == 2) {
			std::cout << "Quantidade de Pacientes cadastrados ate agora: "<< Paciente::quantidadePacientes << std::endl;
			std::cin.ignore();
			std::cin.get();
		} else if (entrada == 3) {
			cadastrar("paciente.txt");
		} else if (entrada == 4) {
			break;
		}
	}
}

void Sistema::imprimirPacientes() {
	std::cout << "Nome|" << "Endereco|" << "Telefone|" << "Data de Entrada|" << "Data de Saida|" << "Psicologo Responsavel|" << "Queixa|" << "Mensalidade" << std::endl;
	pacientes[0].imprimirDados();

	std::cin.ignore();
	std::cin.get();
}

void Sistema::paginaInicial() {
	std::string opcoes[] = { "Entrar como Secretaria", "Entrar como Psicologo", "Cadastrar Secretaria","Cadastrar Psicologo","Sair Do Programa", "end" };
	int entrada;
	while (true) {
		limparTela();
		mostrarOpcoes(opcoes);

		std::cin >> entrada;
		limparTela();

		if (entrada == 1) {
			ambienteSecretaria();
		} else if (entrada == 2) {
			//ambientePsicologo();
		} else if (entrada == 4) {
			cadastrar("psicologo.txt");
		} else if (entrada == 3) {
			cadastrar("secretaria.txt");
		} else if (entrada == 5) {
			std::cout << "Obrigado por usar nosso programa!" << std::endl;
			break;
		}
	}
}