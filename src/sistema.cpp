#include "sistema.h"

Sistema::Sistema() {

	std::ifstream infile("paciente.txt");
	if(!infile.is_open()) {
		std::cout << "Não foi possível abrir o arquivo" << std::endl;
		infile.clear();
	} else {
		while(infile) {
			std::string s;
			if (!getline(infile, s)) break;

			std::istringstream ss( s );
			std::vector<std::string> pessoa;
			while(ss) {
				std::string s;
				if(!getline(ss, s, ',')) break;
				pessoa.push_back(s);
			}
			pacientes.push_back(Paciente(pessoa[0], pessoa[1], pessoa[2], pessoa[3]));
		}
	}
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

void Sistema::cadastrar(std::string tipo) {
	std::ofstream pessoa;
	pessoa.open(tipo, std::ios::app);

	std::vector<std::string> informacoes = {"Nome: ", "Endereco: ", "Telefone: ", "Data de Inicio: "};
	if(tipo == "psicologo.txt") {
		informacoes.push_back("Numero: CRP: ");
	}
	std::cout << "Preencha os dados abaixo" << std::endl;

	std::vector<std::string> dados;
	for(std::vector<int>::size_type i = 0; i != informacoes.size(); i++) {
		std::string entrada;
		std::cout << informacoes[i];
		std::cin >> entrada;
		dados.push_back(entrada);
		pessoa << dados[i] << ",";
	}
	pessoa << std::endl;
	pessoa.close();

	if(tipo == "paciente.txt") {
		pacientes.push_back(Paciente(dados[0], dados[1], dados[2], dados[3]));
	}
	std::cout << "Pessoa cadastrada!" << std::endl;
	std::cin.ignore();
	std::cin.get();
}

void Sistema::ambienteSecretaria()
{
	std::string opcoes[] = {"Visualizar Pacientes","Marcar Consulta","Cadastrar Pacientes", "Voltar para Pagina Inicial", "end"};
	int entrada;

	while (true) {
		limparTela();
		mostrarOpcoes(opcoes);
		std::cin >> entrada;
		limparTela();
		if (entrada == 1) {
			imprimirPacientes();
		} else if (entrada == 2) {
			marcarConsulta();
		} else if (entrada == 3) {
			cadastrar("paciente.txt");
		} else if (entrada == 4) {
			break;
		}
	}
}

void Sistema::marcarConsulta() {
	std::cout << "Digite o nome do Paciente" << std::endl;
}

void Sistema::imprimirPacientes() {
	while(true) {
		std::cout << "Nome|" << "Endereco|" << "Telefone|" << "Data de Entrada|" << "Data de Saida|" << "Psicologo Responsavel|" << "Queixa|" << "Mensalidade" << std::endl;
		std::cout << "=============================================================================================" << std::endl;
		
		if(pacientes.size() == 0) {
			std::cout << "Nenhum Paciente Cadastrado" << std::endl;
		} else  {
			for(std::vector<int>::size_type i = 0; i != pacientes.size(); i++) {
				pacientes[i].imprimirDados();
			}
		}
		std::cout << "=============================================================================================" << std::endl;
		std::cout << "Total de Pacientes: " << Paciente::quantidadePacientes << std::endl;

		std::cout << "1. Limpar Pacientes" << std::endl;
		std::cout << "2. Voltar" << std::endl;
		
		int entrada;
		std::cin.ignore();
		std::cin >> entrada;
		if(entrada == 1) {
			limparTela();
			remove("paciente.txt");
			pacientes.clear();
		} else if(entrada == 2) {
			break;
		}
	}
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