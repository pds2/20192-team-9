#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string.h>
#include "psicologo.h"

class Funcionario{

	virtual std::string consultarAgendaDia(Psicologo *p) = 0;
	virtual std::string proximaConsulta(Psicologo *p) = 0;
	virtual std::string adicionarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) = 0;
	virtual std::string desmarcarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) = 0;
};

#endif