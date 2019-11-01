#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "secretaria.h"
#include "paciente.h"
#include "pessoa.h"


class Sistema {
private:
    std::vector<Paciente> pacientes;
public:
    Sistema();
    void limparTela();
    void imprimirPacientes();
    void mostrarOpcoes(std::string frases[]);		// Funcao para facilitar a exbicao de mensagens
    void paginaInicial();
    void cadastrar(std::string tipo);               //Instancia objetos e salva em arquivo txt
    void ambienteSecretaria();
    void marcarConsulta();
};