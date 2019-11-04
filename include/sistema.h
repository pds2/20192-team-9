#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "secretaria.h"
#include "paciente.h"
#include "pessoa.h"
#include "psicologo.h"
#include "funcionario.h"

class Sistema { 
    std::map<std::string ,std::vector<Pessoa*>> registro;
    std::vector<std::string> arquivos = {Paciente::arquivo, Secretaria::arquivo, Psicologo::arquivo};
public:
    Sistema();
    ~Sistema();
    // Facilitadores
    static void limparTela();
    static void mostrarOpcoes(std::vector<std::string> opcoes);
    static std::vector<std::vector<std::string>> lerArquivo(std::string arquivo);
    static std::vector<std::string> preencher(std::vector<std::string> campos);
    // Operacoes no sistema
    void paginaInicial();
    bool isCadastrado(std::string cpf, std::string funcionario);
    void salvar(std::vector<std::string> dados, std::string arquivo);
    void logar();
    void sair();
    void ambienteSecretaria();
    void ambientePsicologo();
    template<typename T> void cadastrar();
    template<typename T> void excluir();
    template<typename T> void imprimir();
};