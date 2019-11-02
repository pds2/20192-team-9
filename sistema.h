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

class Sistema {  
public:
    Sistema();
    ~Sistema();
    static void limparTela();
    static void mostrarOpcoes(std::vector<std::string> opcoes);		// Funcao para facilitar a exbicao de mensagens
    int paginaInicial();
    std::vector<std::string> preencher(std::vector<std::string> campos);
    void salvar(std::vector<std::string> dados, std::string arquivo);
    void marcarConsulta();
};