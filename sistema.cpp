#include "sistema.h"

Sistema::Sistema()
{
}

void Sistema::mostrarOpcoes(string opcoes[])
{
	int i = 0;
	while (opcoes[i] != "end")
	{
		std::cout << i + 1 << "." << opcoes[i] << endl;
		i++;
	}
}

void Sistema::cadastrar(string tipo)
{
	ofstream pessoa;
	pessoa.open(tipo, ios::app);

	string dados[5];
	std::cout << "Preencha os dados abaixo" << endl;
	std::cout << "Nome: ";
	cin.ignore();
	getline(cin, dados[0]);
	std::cout << "Endereco: ";
	getline(cin, dados[1]);
	std::cout << "Telefone: ";
	getline(cin, dados[2]);
	std::cout << "Data de Inicio: ";
	getline(cin, dados[3]);

	pessoa << dados[0] << ", " << dados[1] << ", " << dados[2] << ", " << dados[3] << ", ";

	if(tipo == "psicologo.txt")
	{
		std::cout << "Numero CRP:";
		getline(cin, dados[4]);
		pessoa << dados[4] <<  endl;
	} else {
		pessoa << endl;
		if(tipo == "paciente.txt") {
			pacientes.push_back(Paciente(dados[0], dados[1], dados[2], dados[3]));
		}

	}
	pessoa.close();

	std::cout << "Pessoa cadastrada!" << endl;
	std::system("pause");
}

void Sistema::ambienteSecretaria()
{
	system("CLS");
	string opcoes[] = {"Visualizar Secretarias","Visualizar Quantidade de Pacientes Cadastrados","Cadastrar Pacientes", "end"};
	mostrarOpcoes(opcoes);
	int entrada;
	cin >> entrada;
	std::system("CLS");
	switch (entrada) {
	case 1:
		break;
	case 2:
		system("cls");
		cout << "Quantidade de Pacientes cadastrados ate agora: "<< Paciente::quantidadePacientes << endl;
		system("pause");
		break;
	case 3:
		cadastrar("paciente.txt");
		break;
	}
	ambienteSecretaria();
}

void Sistema::paginaInicial() {
	std::system("CLS");
	string opcoes[] = { "Entrar como Secretaria", "Entrar como Psicologo", "Cadastrar Secretaria","Cadastrar Psicologo","Sair Do Programa", "end" };
	mostrarOpcoes(opcoes);
	int entrada;
	cin >> entrada;
	std::system("CLS");
	switch (entrada) {
	case 1:
		ambienteSecretaria();
		paginaInicial();
		break;
	case 2:
		//ambientePsicologo();
		break;
	case 3:
		cadastrar("secretaria.txt");
		paginaInicial();
		break;
	case 4:
		cadastrar("psicologo.txt");
		paginaInicial();
		break;
	case 5:
		std::cout << "Obrigador por usar nosso programa!" << endl;
		break;
	}
}