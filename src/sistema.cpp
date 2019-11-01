#include "sistema.h"

void Sistema::mostrarOpcoes(string opcoes[])
{
	int i = 0;
	while (opcoes[i] != "end")
	{
		cout << i + 1 << "." << opcoes[i] << endl;
		i++;
	}
}

void Sistema::cadastrar(string tipo)
{
	ofstream pessoa;
	pessoa.open(tipo, ios::app);

	string dados[5];
	cout << "Preencha os dados abaixo" << endl;
	cout << "Nome: ";
	getline(cin, dados[0]);
	cout << "Endereco: ";
	getline(cin, dados[1]);
	cout << "Telefone: ";
	getline(cin, dados[2]);
	cout << "Data de Inicio: ";
	getline(cin, dados[3]);

	if(tipo == "psicologo.txt")
	{
		cout << "Numero CRP:";
		getline(cin, dados[4]);
		pessoa << dados[0] << ", " << dados[1] << ", " << dados[2] << ", " << dados[3] << ", " << dados[4] <<  endl;
	} else
	{
		pessoa << dados[0] << ", " << dados[1] << ", " << dados[2] << endl;
	}
	pessoa.close();

	cout << "Pessoa cadastrada!" << endl;
	system("pause");
	paginaInicial();
}

void Sistema::ambienteSecretaria()
{
	string opcoes[] = {"Visualizar Secretarias","Visualizar Psicologos"};
	mostrarOpcoes(opcoes);
	int entrada;
	cin >> entrada;
	system("CLS");
	switch (entrada) {
	case 1:
		break;
	case 2:
		break;
	}
}

void Sistema::paginaInicial() {
	system("CLS");
	string opcoes[] = { "Entrar como Secretaria", "Entrar como Psicologo", "Cadastrar Secretaria","Cadastrar Psicologo","Sair Do Programa", "end" };
	mostrarOpcoes(opcoes);
	int entrada;
	cin >> entrada;
	system("CLS");
	switch (entrada) {
	case 1:
		//ambienteSecretaria();
		break;
	case 2:
		//ambientePsicologo();
		break;
	case 3:
		cadastrar("secretaria.txt");
		break;
	case 4:
		cadastrar("psicologo.txt");
		break;
	case 5:
		cout << "Obrigador por usar nosso programa!" << endl;
		system("pause");
	}
}