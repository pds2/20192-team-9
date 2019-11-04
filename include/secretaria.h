#ifndef SECRETARIA_H
#define SECRETARIA_H

#include <string>
#include "pessoa.h"
#include "funcionario.h"
#include "agenda.h"
#include "paciente.h"


class Secretaria : public Pessoa, public Funcionario {
	public:
		Secretaria(std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
		Secretaria(std::vector<std::string> secretariaDados);
		~Secretaria();
		std::string getCPF();
		void imprimirDados();
		//Consultar os pacientes do dia do psicologo selecionado
		/*
		std::string consultarAgendaDia() override;
		std::string proximaConsulta() override;
		std::string adicionarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

		void desmarcarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;
		*/

		static std::vector<std::string> cadastro;
		static std::string nomeClasse;
		static std::string arquivo;
};

#endif