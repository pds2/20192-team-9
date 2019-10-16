#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "secretaria.h"
#include "paciente.h"
#include "pessoa.h"


class Sistema {
    
public:
    vector<Paciente> pacientes;
    Sistema();
    void mostrarOpcoes(string frases[]);		// Funcao para facilitar a exbicao de mensagens
    void paginaInicial();
    void cadastrar(string tipo);
    void ambienteSecretaria();
};