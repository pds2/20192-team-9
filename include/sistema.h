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
    int indice;
public:
    Sistema();
    ~Sistema();
    static void limparTela();
    static void mostrarOpcoes(std::vector<std::string> opcoes);
    int paginaInicial();
    std::vector<std::string> preencher(std::vector<std::string> campos);
    void salvar(std::vector<std::string> dados, std::string arquivo);
    void iniciar();
    void logar();
};