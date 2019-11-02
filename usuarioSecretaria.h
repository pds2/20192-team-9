#pragma once
#include "sistema.h"

class usuarioSecretaria {
private:
    Sistema &sys;
    std::map<std::string ,std::vector<Pessoa*>> registro;
public:
    usuarioSecretaria(Sistema &in_sys);
    void paginaInicial();
    template<typename T> void imprimir();
    template<typename T> void cadastrar();
    template<typename T> void excluir();
};