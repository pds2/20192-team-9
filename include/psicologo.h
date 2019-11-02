#include <string>
#include "pessoa.h"
#include "funcionario.h"
#include "agenda.h"


class Psicologo : public Pessoa, public Funcionario {
	private:
		std::string CRP;
		Agenda * agenda;
	public:
		Psicologo(std::string CRP, std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
		~Psicologo();

		//Consultar os pacientes do dia do psicologo selecionado
		std::string consultarAgendaDia() override;
		std::string proximaConsulta() override;
		std::string adicionarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

		void desmarcarConsulta(std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;


		// SETTERS
		void setCRP(std::string CRP);
		void setAgenda(Agenda *agenda);

		// GETTERS
		std::string getCRP();
		Agenda* getAgenda();
};