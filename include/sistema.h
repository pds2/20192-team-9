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
    Sistema();
    // Facilitadores
    void limparTela();
    int mostrarOpcoes(std::vector<std::string> opcoes);
    std::vector<std::vector<std::string>> lerArquivo(std::string arquivo);
    std::vector<std::string> preencher(std::vector<std::string> campos);
    void salvar(std::vector<std::string> dados, std::string arquivo);
    void sair();
    bool isCadastrado(std::string cpf, std::string funcionario);
    int converterParaInteiro(std::string &s);
    // Operacoes no sistema
    void paginaInicial();
    void logar();
    void ambienteSecretaria();
    void ambientePsicologo();
    void escreverProntuario();
    void consultarAgenda();

    void imprimirPaciente(const char* arquivo);
    void imprimirPsicologo(const char* arquivo);
    void imprimirSecretaria(const char* arquivo);

    void cadastrarPaciente();
    void cadastrarPsicologo();
    void cadastrarSecretaria();
};