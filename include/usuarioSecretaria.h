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

    virtual std::string consultarAgendaDia(Psicologo *p) = 0;
	virtual std::string proximaConsulta(Psicologo *p) = 0;
	virtual std::string adicionarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) = 0;
	virtual std::string desmarcarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) = 0;
};