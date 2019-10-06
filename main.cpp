#include <iostream>
#include <string>

using namespace std;

void login()
{
    system("CLS");
    string user, password;
    cout << "Informe seu ID" << endl;
    cin >> user;
    system("CLS");
    cout << "Informe sua senha" << endl;
    cin >> password;
    system("CLS");
    cout << "O login foi feito!" << endl;
    system("pause");
}

void quit()
{
    system("CLS");
    cout << "Obrigado por usar nosso programa" << endl;
    system("pause");
    cin.get();
}

int main() {
    int input;
    cout << "-----------------------------------------"<< endl;
    cout << "1. Fazer login" << endl;
    cout << "2. Sair do Programa" << endl;
    cout << "-----------------------------------------"<< endl;
    cin >> input;
    switch ( input )
    {
        case 1:
            login();
            break;
        case 2:
            quit();
            break;
    }
}
