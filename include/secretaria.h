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
		std::string consultarAgendaDia(Psicologo * p) override;
		std::string proximaConsulta(Psicologo * p) override;
		std::string adicionarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

		void desmarcarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

};