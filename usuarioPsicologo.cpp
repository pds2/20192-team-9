#include "usuarioPsicologo.h"

void usuarioPsicologo::paginaInicial() {
    int entrada;
	while(true) {
		limparTela();
		mostrarOpcoes({"Visualizar Pacientes", "Visualizar Agenda", "Voltar para Pagina Inicial"});
		std::cin >> entrada;
		limparTela();
		if(entrada == 1) {
			imprimirPacientes();
		} else if(entrada == 2) {
			//imprimirAgenda();
		} else if(entrada == 3) {
			break;
		}
	}
}

void usuarioPsicologo::imprimirPacientes() {
	
    while(true) {
        limparTela();
		std::cout << "Nome|" << "Endereco|" << "Telefone|" << "Data de Entrada|" << "Data de Saida|" << "Psicologo Responsavel|" << "Queixa|" << "Mensalidade" << std::endl;
		std::cout << "=============================================================================================" << std::endl;
		
		if(pacientes.size() == 0) {
			std::cout << "Nenhum Paciente Cadastrado" << std::endl;
		} else  {
			for(std::vector<int>::size_type i = 0; i != pacientes.size(); i++) {
				pacientes[i]->imprimirDados();
			}
		}
		std::cout << "=============================================================================================" << std::endl;
		std::cout << "Total de Pacientes: " << Paciente::quantidadePacientes << std::endl;


		mostrarOpcoes({"Lancar Prontuario", "Voltar"});
		
		int entrada;
		std::cin.ignore();
		std::cin >> entrada;
		if(entrada == 1) {
			//lancarProntuario();
		} else if(entrada == 2) {
			break;
		}
	}
}