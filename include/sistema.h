#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include "paciente.h"
#include "pessoa.h"
#include "psicologo.h"

class Sistema {
    Psicologo* psicologoUsuario;
    Pessoa* secretariaUsuario;
    std::vector<Paciente*> pacientes;
    std::vector<Pessoa*> secretarias;
    std::vector<Psicologo*> psicologos;
public:
    // CONSTRUTORES
    Sistema();

    // FACILITADORES
    int mostrarOpcoes(std::vector<std::string> opcoes);
    std::vector<std::vector<std::string>> lerArquivo(std::string arquivo);
    std::vector<std::string> preencher(std::vector<std::string> campos);
    void limparTela();
    bool validar_CPF(std::string cpf);

    // OUTRAS OPERACOES
    void salvar(std::vector<std::string> dados, std::string arquivo);
    void sair();

    // OUTRAS PAGINAS
    void paginaInicial();
    void logar();
    void consultarAgenda();
    void escreverProntuario();

    // AMBIENTES
    void ambienteSecretaria();
    void ambientePsicologo();

    // IMPRIMIR
    void imprimirPaciente(const char* arquivo);
    void imprimirPsicologo(const char* arquivo);
    void imprimirSecretaria(const char* arquivo);

    // CADASTRAR
    void cadastrarPaciente();
    void cadastrarPsicologo();
    void cadastrarSecretaria();
};
