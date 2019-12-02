#include "sistema.h"


Sistema::Sistema() 
{
	std::vector<std::vector<std::string>> pacientesData = lerArquivo("paciente.txt");
	std::vector<std::vector<std::string>> secretariasData = lerArquivo("secretaria.txt");
	std::vector<std::vector<std::string>> psicologosData = lerArquivo("psicologo.txt");
	std::vector<std::vector<std::string>>::iterator itr;
	try {
		for(itr = pacientesData.begin(); itr != pacientesData.end(); itr++) {
			pacientes.push_back(new Paciente(*itr));
		}
		for(itr = secretariasData.begin(); itr != secretariasData.end(); itr++) {
			secretarias.push_back(new Pessoa(*itr));
		}
		for(itr = psicologosData.begin(); itr != psicologosData.end(); itr++) {
			psicologos.push_back(new Psicologo(*itr));
		}
	}catch(std::invalid_argument &e) {
		throw std::invalid_argument("Arquivos txt defeituosos, por favor delete-os");
	}

}

std::vector<Psicologo*>& Sistema::getPsicologos() {
	return this->psicologos;
}
std::vector<Pessoa*>& Sistema::getSecretarias() {
	return this->secretarias;
}
std::vector<Paciente*>& Sistema::getPacientes() {
	return this->pacientes;
}

std::vector<std::vector<std::string>> Sistema::lerArquivo(std::string arquivo) 
{
	std::ifstream infile(arquivo);

	std::vector<std::vector<std::string>> linhas;
	while(infile) {
		std::string s;
		if (!getline(infile, s)) break;
		std::istringstream ss( s );
		std::vector<std::string> linha;
		while(ss) {
			std::string s;
			if(!getline(ss, s, ',')) break;
			linha.push_back(s);
		}
		linhas.push_back(linha);
	}
	infile.close();
	return linhas;
}

std::string Sistema::preencher(std::string campo) {
	std::cout << campo << ":\t";
	std::string entrada;
	std::getline(std::cin, entrada);
	return entrada;
 }

std::string Sistema::mostrarOpcoes(std::vector<std::string> opcoes)
{
	unsigned int e;
	bool flag = true;

	for(unsigned int i = 0; i < opcoes.size(); i++) {
		std::cout << i+1 << ". " << opcoes[i] << std::endl;
	}

	while(flag){
		try{
			if(!(std::cin >> e)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::invalid_argument("Entrada nao e um numero");
			}
			if(e > opcoes.size()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::invalid_argument("Entrada fora do permitido");
			}
			if(e == 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::invalid_argument("Entrada igual a zero");
			}
			flag = false;
		} catch(std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cin.ignore(10000, '\n');
	return opcoes[e-1];
}

void Sistema::limparTela() 
{
	std::cout << "\x1B[2J\x1B[H";
}

std::vector<std::string> Sistema::preencher(std::vector<std::string> campos) 
{
	std::cout << "Preencha os campos abaixo" << std::endl;
	std::vector<std::string> dados;
	for(std::vector<std::string>::iterator itr = campos.begin(); itr != campos.end(); itr++) {
		std::string entrada;
		std::cout << (*itr) << ":\t";
		getline(std::cin, entrada);
		dados.push_back(entrada);
	}
	return dados;
}

void Sistema::logar(std::string cpf)  
{
	try{
		Psicologo* psicologo = encontrar(psicologos,cpf);
		usuarioPsicologo = psicologo;
		ambientePsicologo();
	} catch (std::invalid_argument &e){
		try{
			Pessoa* secretaria = encontrar(secretarias,cpf);
			usuarioSecretaria = secretaria;
			ambienteSecretaria();
		} catch (std::invalid_argument &e){
			throw std::invalid_argument("CPF nao cadastrado!");
		}
	}
}

void Sistema::paginaInicial() 
{
	while (true) {
		limparTela();
		std::string opcao = mostrarOpcoes({"Fazer Login","Cadastrar Secretaria","Cadastrar Psicologo","Visualizar Secretarias", "Visualizar Psicologos","Sair Do Programa"});
		if (opcao == "Fazer Login")
			do {
				limparTela();
				std::cout << "Bem vindo ao sistema da Clinica Social" << std::endl;
				std::string cpf = preencher("CPF");
				try {
					logar(cpf);
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
			} while(opcao != "Voltar");
		if (opcao == "Cadastrar Secretaria"){
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF (somente numeros)", "Nome", "Rua", "Telefone", "Data de Inicio (ddmmaa)"});
				try {
					cadastrar(new Pessoa(dados));
					std::cout << "Secretaria Cadastrada!" << std::endl;
					std::cin.get();
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
			} while(opcao != "Voltar");
		}
		if (opcao == "Cadastrar Psicologo") {
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF (somente numeros)", "Nome", "Rua", "Telefone", "Data de Inicio (ddmmaa)", "CRP" , "\n============================\nHorario de funcionamento de 7 as 16.\nInicio Expediente (hh)", "Fim Expediente (hh)"});
				try {
					cadastrar(new Psicologo(dados));
					std::cout << "Psicologo Cadastrado!" << std::endl;
					std::cin.get();
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
			} while(opcao != "Voltar");
		} if (opcao == "Visualizar Secretarias") {
			do {
				limparTela();
				imprimir(secretarias);
				opcao = mostrarOpcoes({"Limpar Tudo", "Voltar"});
				if(opcao == "Limpar Tudo")
					deletar(secretarias);
			} while(opcao != "Voltar");
		} if (opcao == "Visualizar Psicologos") {
			do {
				limparTela();
				imprimir(psicologos);
				opcao = mostrarOpcoes({"Limpar Tudo", "Voltar"});
				if(opcao == "Limpar Tudo")
					deletar(psicologos);
			} while(opcao != "Voltar");
		} if (opcao == "Sair Do Programa") {
			//limparTela();
			std::cout << "Obrigado por usar nosso programa!" << std::endl;
			break;
		}
	}
}

void Sistema::ambienteSecretaria() 
{
	while(true) {
		limparTela();
		std::cout << "Logado:\t" << usuarioSecretaria->getNome() << "\t" << "Secretaria" << std::endl;
		std::string opcao = mostrarOpcoes({"Visualizar Pacientes", "Visualizar Agenda", "Marcar Consulta", "Desmarcar Consulta", "Cadastrar Paciente", "Voltar para Pagina Inicial"});
		if(opcao == "Visualizar Pacientes") {
			do {
				limparTela();
				imprimir(pacientes);
				opcao = mostrarOpcoes({"Limpar Tudo", "Voltar"});
				if(opcao == "Limpar Tudo")
					deletar(pacientes);
			} while(opcao != "Voltar");
		} if(opcao == "Visualizar Agenda") {
			try{
				imprimirAgenda();
			} catch(std::invalid_argument &e) {
				std::cout << e.what() << std::endl;
			}
			std::cin.get();
		} if(opcao == "Marcar Consulta") {
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF do psicologo","CPF do Paciente","Dia", "Mes", "Ano", "Hora"});
				try {
					marcarConsulta(dados);
					std::cout << "Consulta Marcada!" << std::endl;
					std::cin.get();
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
			} while(opcao == "Tentar Novamente");
		} if(opcao == "Desmarcar Consulta") {
			limparTela();
			std::vector<std::string> dados = preencher({"CPF do psicologo", "Dia", "Mes", "Ano", "Hora"});
			try {
				desmarcarConsulta(dados);
				std::cout << "Consulta Desmarcada!" << std::endl;
				std::cin.get();
				opcao = "Voltar";
			} catch (std::invalid_argument &e) {
				std::cout << e.what() << std::endl;
				opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
			}
		} if(opcao == "Cadastrar Paciente") {
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF (somente números)", "Nome", "Rua", "Telefone", "Data de Inicio (ddmmaa)"});
				try {
					cadastrar(new Paciente(dados));
					std::cout << "Paciente Cadastrado!" << std::endl;
					opcao = "Voltar";
					std::cin.get();
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
			} while(opcao != "Voltar");
		} if (opcao == "Voltar para Pagina Inicial")
			break;
	}
}
void Sistema::marcarConsulta(std::vector<std::string>& dados) {
	Psicologo* psicologo = encontrar(psicologos, dados[0]); // Temp
	Paciente* paciente = encontrar(pacientes, dados[1]);
	paciente->setPsicologoResponsavel(psicologo->getNome());
	psicologo->adicionarConsulta(paciente->getNome(), dados[2], dados[3], dados[4], dados[5]);
}

void Sistema::imprimirAgenda(){
	if(psicologos.size() == 0)
		throw std::invalid_argument("Nenhum psicologo Cadastrado!");
	for(std::vector<Psicologo*>::iterator itr = psicologos.begin(); itr != psicologos.end(); itr++) {
		std::cout <<"Agenda de "<< (*itr)->getNome() << std::endl;
		(*itr)->imprimirConsultas();
	}
	std::cin.get();
}

void Sistema::cadastrar(Paciente *paciente) {
	pacientes.push_back(paciente);

	std::ofstream pessoa;
	pessoa.open("paciente.txt", std::ios::app);
	pessoa << paciente->getCPF() << "," << paciente->getNome() << "," << paciente->getRua() << "," << paciente->getTelefone() << "," 
	<< paciente->getDataInicio() << "," << std::endl;
	pessoa.close();
}

void Sistema::cadastrar(Psicologo *psicologo) {
	psicologos.push_back(psicologo);

	std::ofstream pessoa;
	pessoa.open("psicologo.txt", std::ios::app);
	pessoa << psicologo->getCPF() << "," << psicologo->getNome() << "," << psicologo->getRua() << "," << psicologo->getTelefone() << "," 
	<< psicologo->getDataInicio() << ","  << psicologo->getCRP() << "," << psicologo->getInicioExpediente() << "," 
	<< psicologo->getFimExpediente() << "," << std::endl;
	pessoa.close();
}

void Sistema::cadastrar(Pessoa *secretaria) {
	secretarias.push_back(secretaria);

	std::ofstream pessoa;
	pessoa.open("secretaria.txt", std::ios::app);
	pessoa << secretaria->getCPF() << "," << secretaria->getNome() << "," << secretaria->getRua() << "," << secretaria->getTelefone() << "," 
	<< secretaria->getDataInicio() << "," << std::endl;
	pessoa.close();
}

void Sistema::deletar(std::vector<Pessoa*>& secretarias) {
	secretarias.clear();
	remove("secretaria.txt");
}

void Sistema::deletar(std::vector<Psicologo*>& psicologos) {
	psicologos.clear();
	remove("psicologo.txt");
}

void Sistema::deletar(std::vector<Paciente*>& pacientes) {
	pacientes.clear();
	remove("paciente.txt");
}
void Sistema::imprimir(const std::vector<Pessoa*>& secretarias) 
{
	std::cout << "=============================================================================================" << std::endl;
	if(secretarias.size() == 0)
		std::cout << "Nenhuma secretaria esta cadastrada!" << std::endl;
	else  {
		for(std::vector<Pessoa*>::const_iterator itr = secretarias.begin(); itr != secretarias.end(); itr++) {
			(*itr)->imprimirDados();
		}
	}
	std::cout << "=============================================================================================" << std::endl;
}

void Sistema::imprimir(const std::vector<Psicologo*>& psicologos) 
{
	std::cout << "=============================================================================================" << std::endl;
	if(psicologos.size() == 0)
		std::cout << "Nenhum psicologo esta cadastrado!" << std::endl;
	else  {
		for(std::vector<Psicologo*>::const_iterator itr = psicologos.begin(); itr != psicologos.end(); itr++) {
			(*itr)->imprimirDados();
		}
	}
	std::cout << "=============================================================================================" << std::endl;
}

Psicologo* Sistema::encontrar(std::vector<Psicologo*>& psicologos, std::string cpf) {
	std::vector<Psicologo*>::iterator itr;
	for(itr = psicologos.begin(); itr != psicologos.end(); itr++) {
		if( (*itr)->getCPF() == cpf )
			return *itr;
	}
	throw std::invalid_argument("Nao ha nenhum psicologo com esse CPF");
}

Pessoa* Sistema::encontrar(std::vector<Pessoa*>& secretarias, std::string cpf) {
	std::vector<Pessoa*>::iterator itr;
	for(itr = secretarias.begin(); itr != secretarias.end(); itr++) {
		if( (*itr)->getCPF() == cpf )
			return *itr;
	}
	throw std::invalid_argument("Nao ha nenhuma secretaria com esse CPF");
}

Paciente* Sistema::encontrar(std::vector<Paciente*>& pacientes, std::string cpf) {
	std::vector<Paciente*>::iterator itr;
	for(itr = pacientes.begin(); itr != pacientes.end(); itr++) {
		if( (*itr)->getCPF() == cpf )
			return *itr;
	}
	throw std::invalid_argument("Nao ha nenhum paciente com esse CPF");
}


void Sistema::imprimir(const std::vector<Paciente*>& pacientes) 
{
	std::cout << "=============================================================================================" << std::endl;
	if(pacientes.size() == 0)
		std::cout << "Nenhum paciente esta cadastrado!" << std::endl;
	else  {
		for(std::vector<Paciente*>::const_iterator itr = pacientes.begin(); itr != pacientes.end(); itr++) {
			(*itr)->imprimirDados();
		}
	}
	std::cout << "=============================================================================================" << std::endl;
}

void Sistema::ambientePsicologo() 
{
	while(true) {
		limparTela();
		std::cout << "Logado:\t" << usuarioPsicologo->getNome() << "\t" << "Psicologo" << std::endl;
		std::string opcao = mostrarOpcoes({"Consultar Agenda","Escrever Prontuario", "Visualizar Pacientes","Voltar para Pagina Inicial"});
		if (opcao == "Consultar Agenda") {
			do {
				limparTela();
				usuarioPsicologo->imprimirConsultas();
				opcao = mostrarOpcoes({"Voltar"});
			} while (opcao != "Voltar");
		} if (opcao == "Escrever Prontuario") {
			do {
				limparTela();
				std::string cpf = preencher("CPF");
				std::cout << "Digite o prontuario abaixo" << std::endl;
				try{
					Paciente* paciente = encontrar(pacientes, cpf);
					std::cout << getQueixa(paciente);
					std::string queixa;
					getline(std::cin, queixa);
					addQueixa(paciente, queixa);
					std::cout << "Queixa cadastrada!" << std::endl;
					std::cin.get();
					opcao = "Voltar";
				}catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
			} while(opcao != "Voltar");
		} if (opcao == "Visualizar Pacientes") {
			do {
				limparTela();
				imprimir(pacientes);
				opcao = mostrarOpcoes({"Limpar Tudo", "Voltar"});
				if(opcao == "Limpar Tudo")
					deletar(pacientes);
			} while(opcao != "Voltar");
		} if (opcao == "Voltar para Pagina Inicial") 
			break;
	}
}

std::string Sistema::getQueixa(Paciente* paciente) {
	return paciente->getQueixa();
}

void Sistema::addQueixa(Paciente* paciente, std::string queixa) {
	paciente->addQueixa(queixa);
}

void Sistema::desmarcarConsulta(std::vector<std::string> dados) {
	Psicologo *psicologo = encontrar(psicologos, dados[0]);
	psicologo->desmarcarConsulta(dados[1], dados[2], dados[3], dados[4]);

}//84213703088, 15746533009