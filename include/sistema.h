#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "secretaria.h"
#include "paciente.h"
#include "pessoa.h"
#include "psicologo.h"
#include "funcionario.h"


class Sistema {
private:
    int indice;
    std::vector<Paciente> pacientes;
    std::vector<Funcionario> funcionario;
public:
    Sistema();
    void iniciar();
    void logar();
    void editarProntuario();
    void limparTela();
    void imprimirPacientes();
    void mostrarOpcoes(std::string frases[]);		// Funcao para facilitar a exbicao de mensagens
    void paginaInicial();
    void cadastrar(std::string tipo);               //Instancia objetos e salva em arquivo txt
    void ambienteSecretaria();
    void marcarConsulta();
};