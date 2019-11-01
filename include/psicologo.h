#include <string>
#include "pessoa.h"
#include "funcionario.h"
#include "agenda.h"
#include "paciente.h"


class Psicologo : Pessoa, Funcionario {
	private:
		std::string CRP;
		Agenda * agenda;
	public:
		Psicologo(std::string CRP, std::string CPF, std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
		~Psicologo();

		std::string consultarAgendaDia(Psicologo * p) override;
		std::string proximaConsulta(Psicologo * p) override;
		std::string adicionarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;

		void desmarcarConsulta(Psicologo * p, std::string dia, std::string mes, std::string ano, std::string paciente, std::string hora) override;
		void editarProntuario(Paciente * p, std::string entrada);


		// SETTERS
		void setCRP(std::string CRP);
		void setAgenda(Agenda agenda);

		// GETTERS
		std::string getCRP();
		Agenda getAgenda();
};