#include "secretaria.h"

Secretaria::Secretaria(std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio) 
    :
    Pessoa(CPF, nome, endereco, telefone, dataInicio)
{
}

Secretaria::Secretaria(std::vector<std::string> secretariaDados) 
    :
    Secretaria(secretariaDados[0], secretariaDados[1], secretariaDados[2], secretariaDados[3], secretariaDados[4])
{
}

void Secretaria::imprimirDados() {

}

std::vector<std::string> Secretaria::cadastro = {"CPF: ","Nome: ", "Endereco: ", "Telefone: ", "Data de Inicio: "};

std::string Secretaria::nomeClasse = "secretaria";

std::string Secretaria::arquivo = "secretaria.txt";