#ifndef PSICOLOGO_H
#define PSICOLOGO_h

#include "pessoa.h"
#include "agenda.h"


class Psicologo : public Pessoa {
	private:
		std::string _crp;
		Agenda *agenda;
	public:
		// CONSTRUTORES
		Psicologo(std::vector<std::string> dados); 
		Psicologo(std::string cpf, std::string nome, std::string endereco, std::string telefone, std::string dataInicio,
		std::string crp, std::string inicioExpediente, std::string fimExpediente);

		// GETTERS
		std::string getCRP();

		// OPERACOES AGENDA
		void desmarcarConsulta(std::string in_dia, std::string in_mes, std::string in_ano, std::string in_hora);
		std::string getConsulta(std::string in_dia, std::string in_mes, std::string in_ano, std::string in_hora);
		void adicionarConsulta(std::string in_paciente, std::string in_dia, std::string in_mes, std::string in_ano, std::string in_hora);
		void imprimirConsultas();
};

#endif