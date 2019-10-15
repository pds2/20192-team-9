#include <string>
#include "pessoa.h"

class Psicologo : Pessoa {
	private:
		std::string numeroCRP;
	public:
		Psicologo(std::string numeroCRP, std::string id, std::string nome, std::string endereco, std::string telefone, std::string dataInicio);
		~Psicologo();
		void imprimirDados();
		void setProntuarioPaciente();

		// SETTERS
		void setNumeroCRP(std::string numeroCRP);

		// GETTERS
		std::string getNumeroCRP();
};