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
    //std::vector<Paciente*> getPacientes();
    std::vector<Psicologo*> getPsicologos();
    //std::vector<Pessoa*> getSecretarias();
    std::vector<Psicologo*>::iterator encontrar(std::vector<Psicologo*>& psicologos, std::string cpf);
    std::vector<Paciente*>::iterator encontrar(std::vector<Paciente*>& pacientes, std::string cpf);
    std::vector<Pessoa*>::iterator encontrar(std::vector<Pessoa*>& secretarias, std::string cpf);

    // FACILITADORES
    std::string mostrarOpcoes(std::vector<std::string> opcoes);
    std::vector<std::vector<std::string>> lerArquivo(std::string arquivo);
    std::vector<std::string> preencher(std::vector<std::string> campos);
    std::string preencher(std::string campo);
    void limparTela();
    bool validar_CPF(std::string cpf);

    //Pessoa encontrarPessoa(Pessoa* p);
    //Paciente encontrarPessoa(Paciente *p);

    // OUTRAS OPERACOES
    void salvar(std::vector<std::string> dados, std::string arquivo);
    void sair();

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
    void adicionar(Pessoa* secretaria);
    void adicionar(Psicologo* psicologo);
    void adicionar(Paciente* paciente);

    void cadastrar(Paciente *paciente, std::vector<std::string>& dados);
    void cadastrar(Pessoa *secretaria, std::vector<std::string>& dados);
    void cadastrar(Psicologo *psicologo, std::vector<std::string>& dados);

    void marcarConsulta(std::vector<std::string>& dados);
    void imprimirAgenda();
};
