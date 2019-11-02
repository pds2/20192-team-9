#ifndef SECRETARIA_H
#define SECRETARIA_H

#include <string>
#include "pessoa.h"
#include "funcionario.h"
#include "agenda.h"
#include "paciente.h"


class Secretaria : Pessoa, Funcionario {
	public:
		Secretaria(std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
		~Secretaria();

		//Consultar os pacientes do dia do psicologo selecionado
		std::string consultarAgendaDia() override;
		std::string proximaConsulta() override;
		std::string adicionarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

		void desmarcarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

};

#endif