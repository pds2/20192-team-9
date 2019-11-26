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
    Pessoa* usuarioSecretaria;
    Psicologo* usuarioPsicologo;
    std::vector<Paciente*> pacientes;
    std::vector<Pessoa*> secretarias;
    std::vector<Psicologo*> psicologos;
public:
    // CONSTRUTORES
    Sistema();

    // GETTERS
    std::vector<Paciente*>& getPacientes();
    std::vector<Psicologo*>& getPsicologos();
    std::vector<Pessoa*>& getSecretarias();
    
    Psicologo* encontrar(std::vector<Psicologo*>& psicologos, std::string cpf);
    Paciente* encontrar(std::vector<Paciente*>& pacientes, std::string cpf);
    Pessoa* encontrar(std::vector<Pessoa*>& secretarias, std::string cpf);

    // FACILITADORES
    std::string mostrarOpcoes(std::vector<std::string> opcoes);
    std::vector<std::vector<std::string>> lerArquivo(std::string arquivo);
    std::vector<std::string> preencher(std::vector<std::string> campos);
    std::string preencher(std::string campo);
    void limparTela();

    // OUTRAS PAGINAS
    void paginaInicial();
    void logar(std::string cpf);

    // AMBIENTES
    void ambienteSecretaria();
    void ambientePsicologo();

    // IMPRIMIR
    void imprimir(const std::vector<Pessoa*>& secretarias);
    void imprimir(const std::vector<Psicologo*>& psicologos);
    void imprimir(const std::vector<Paciente*>& pacientes);

    void deletar(std::vector<Pessoa*>& secretarias);
    void deletar(std::vector<Psicologo*>& psicologos);
    void deletar(std::vector<Paciente*>& pacientes);

    // CADASTRAR
    void cadastrar(Paciente *paciente);
    void cadastrar(Pessoa *secretaria);
    void cadastrar(Psicologo *psicologo);

    void marcarConsulta(std::vector<std::string>& dados);
    void desmarcarConsulta(std::vector<std::string> dados);
    void imprimirAgenda();
    void addQueixa(Paciente* paciente, std::string queixa);
    std::string getQueixa(Paciente* paciente);
};
