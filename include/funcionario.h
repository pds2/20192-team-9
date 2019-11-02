
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario{
protected:
	virtual std::string consultarAgendaDia() = 0;
	virtual std::string proximaConsulta() = 0;
	virtual std::string adicionarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) = 0;
	virtual void desmarcarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) = 0;
};

#endif