#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "secretaria.h"
#include "paciente.h"
#include "pessoa.h"


class Sistema {
public:
    void mostrarOpcoes(string frases[]);		// Funcao para facilitar a exbicao de mensagens
    void paginaInicial();
    void cadastrar(string tipo);
    void ambienteSecretaria();
};