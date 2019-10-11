#include <iostream>
#include <string>
#include <fstream>
#include "secretaria.h"

using namespace std;

void mostrarOpcoes(string frases[]);		// Funcao para facilitar a exbicao de mensagens
void cadastrar(string tipo);
void paginaInicial();

void mostrarOpcoes(string opcoes[])
{
	int i = 0;
	while (opcoes[i] != "end")
	{
		cout << i + 1 << "." << opcoes[i] << endl;
		i++;
	}
}

void cadastrar(string tipo)
{
	ofstream funcionario;
	funcionario.open(tipo, ios::app);
	string nome, endereco, telefone;
	cout << "Preencha os dados abaixo" << endl;
	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome);
	cout << "Endereco: ";
	getline(cin, endereco);
	cout << "Telefone: ";
	getline(cin, telefone);
	if(tipo == "psicologo.txt")
	{
		string crp;
		cout << "Numero CRP:";
		getline(cin, crp);
		funcionario << nome << ", " << endereco << ", " << telefone << ", " << crp <<  endl;
	} else
	{
		funcionario << nome << ", " << endereco << ", " << telefone << endl;
	}
	funcionario.close();
	cout << "Funcionario cadastrado!" << endl;
	system("pause");
	paginaInicial();
}

void ambienteSecretaria()
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

void paginaInicial() {
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

int main() {
	system("title SistemaClinica");
	paginaInicial();
}