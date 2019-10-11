#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mostrarOpcoes(string frases[])
{
	int i = 0;
	while (frases[i] != "end")
	{
		cout << i+1 << "." << frases[i] << endl;
		i++;
	}
}

void paginaInicial() {
	system("CLS");
	string frases[] = { "Entrar como Secretaria", "Entrar como Psicologo", "Cadastrar Psicologo","Cadastrar Scretaria","Sair Do Programa", "end" };
	mostrarOpcoes(frases);
	int entrada;
	cin >> entrada;
	switch (entrada) {
		case 1:
			system("CLS");
			cout << "Entrou como secretaria!" << endl;
			break;
	}
	system("pause");
}

int main() {
	paginaInicial();
}