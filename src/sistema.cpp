#include "sistema.h"


Sistema::Sistema() 
{
	std::vector<std::vector<std::string>> pacientesData = lerArquivo("paciente.txt");
	std::vector<std::vector<std::string>> secretariasData = lerArquivo("secretaria.txt");
	std::vector<std::vector<std::string>> psicologosData = lerArquivo("psicologo.txt");
	std::vector<std::vector<std::string>>::iterator itr;
	try {
		for(itr = pacientesData.begin(); itr != pacientesData.end(); itr++) {
			adicionar(new Paciente(*itr));
		}
		for(itr = secretariasData.begin(); itr != secretariasData.end(); itr++) {
			adicionar(new Pessoa(*itr));
		}
		for(itr = psicologosData.begin(); itr != psicologosData.end(); itr++) {
			adicionar(new Psicologo(*itr));
		}
	}catch(std::invalid_argument &e) {
		throw std::invalid_argument("Arquivos txt defeituosos, por favor delete-os");
	}

}

std::vector<Psicologo*> Sistema::getPsicologos() {
	return this->psicologos;
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
				throw std::invalid_argument("Entrada maior que o permitido");
			}
			if(e <= 0)
				throw std::invalid_argument("Entrada menor ou igual a zero");
			flag = false;
		} catch(std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cin.ignore(10000, '\n');
	return opcoes[e-1];
}

void Sistema::salvar(std::vector<std::string> dados, std::string arquivo) 
{
	std::ofstream pessoa;
	pessoa.open(arquivo, std::ios::app);
	for(std::vector<int>::size_type i = 0; i != dados.size(); i++) {
		pessoa << dados[i] << ",";
	}
	pessoa << std::endl;
	pessoa.close();
}

void Sistema::limparTela() 
{
	#ifdef WINDOWS
		std::system("cls");
	#else
		std::system("clear");
	#endif
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

void Sistema::sair() 
{
	
}

bool Sistema::validar_CPF(std::string cpf){
	int cpfFinal[11];
	if(cpf.size() != 11)
		return false;
	else {
		for(unsigned int i=0; i<cpf.length();i++) {
			int number = (int)cpf[i]-'0';
			if(number < 0 || number>9)
				return false;
			else
				cpfFinal[i]=number;
		}


		do
		{
			getline(std::cin, cpf);
			if(cpf.size() != 11)
				return false;
		} while (cpf.size() != 11);
		

		int dezena, unidade;
		int soma1 = (cpfFinal[0]*10+cpfFinal[1]*9+cpfFinal[2]*8+cpfFinal[3]*7+cpfFinal[4]*6+cpfFinal[5]*5+cpfFinal[6]*4+cpfFinal[7]*3+cpfFinal[8]*2);
		int resto1 = soma1%11;
		if (resto1==0 || resto1==1)
			dezena = 0;
		else
			dezena = 11-resto1;
		int soma2 = (dezena*2+cpfFinal[0]*11+cpfFinal[1]*10+cpfFinal[2]*9+cpfFinal[3]*8+cpfFinal[4]*7+cpfFinal[5]*6+cpfFinal[6]*5+cpfFinal[7]*4+cpfFinal[8]*3);
		int resto2 = soma2%11;
		if (resto2 == 0 || resto2 == 1)
			unidade = 0;
		else 
			unidade = 11-resto2;

		if(cpfFinal[9]!=dezena||cpfFinal[10]!=unidade)
			return false;
		else
			return true;
	}
}

void Sistema::logar(std::string cpf)  
{
	std::vector<Psicologo*>::const_iterator psicologo = encontrar(psicologos,cpf);
	std::vector<Pessoa*>::const_iterator secretaria = encontrar(secretarias,cpf);
	if(psicologo != psicologos.end()) {
		usuarioPsicologo = *psicologo;
		ambientePsicologo();
	} else if(secretaria != secretarias.end()) {
		usuarioSecretaria = *secretaria;
		ambienteSecretaria();
	} else
		throw std::invalid_argument("CPF nao cadastrado!");
}

void Sistema::adicionar(Pessoa* secretaria) {
	secretarias.push_back(secretaria);

}

void Sistema::adicionar(Psicologo* psicologo) {
	psicologos.push_back(psicologo);
}

void Sistema::adicionar(Paciente* paciente) {
	pacientes.push_back(paciente);
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
					cadastrar(new Pessoa(dados), dados);
					std::cout << "Secretaria Cadastrada!" << std::endl;
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
				std::cin.get();
			} while(opcao != "Voltar");
		}
		if (opcao == "Cadastrar Psicologo") {
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF (somente numeros)", "Nome", "Rua", "Telefone", "Data de Inicio (ddmmaa)", "CRP" , "\n============================\nHorario de funcionamento de 7 as 16.\nInicio Expediente (hh)", "Fim Expediente (hh)"});
				try {
					cadastrar(new Psicologo(dados), dados);
					std::cout << "Psicologo Cadastrado!" << std::endl;
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
					std::cin.get();
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
		std::string opcao = mostrarOpcoes({"Visualizar Pacientes", "Visualizar Agenda", "Marcar Consulta", "Cadastrar Paciente", "Voltar para Pagina Inicial"});
		if(opcao == "Visualizar Pacientes") {
			do {
				limparTela();
				imprimir(pacientes);
				opcao = mostrarOpcoes({"Limpar Tudo", "Voltar"});
				if(opcao == "Limpar Tudo")
					deletar(pacientes);
			} while(opcao != "Voltar");
<<<<<<< HEAD
		} if(opcao == "Visualizar Agenda") {
			try{
				imprimirAgenda();
			} catch(std::invalid_argument &e) {
				std::cout << e.what() << std::endl;
			}
			std::cin.get();
		} if(opcao == "Marcar Consulta") {
=======
		} 
		
		
	
		if (opcao == "Visualizar Agenda") {
			do {
				limparTela();
				usuarioPsicologo->imprimirConsultas();
				opcao = mostrarOpcoes({"Voltar"});
			} while (opcao != "Voltar");


		} 
		
		
		
		
		if(opcao == "Marcar Consulta") {
>>>>>>> 267f5d04b51b536c9ae7c0de737820b42fe52ad7
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF do psicologo","CPF do Paciente","Dia", "Mes", "Ano", "Hora"});
				try {
					marcarConsulta(dados);
					std::cout << "Consulta Marcada!" << std::endl;
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
				std::cin.get();
			} while(opcao == "Tentar Novamente");
		} if(opcao == "Cadastrar Paciente") {
			do {
				limparTela();
				std::cout << opcao << std::endl;
				std::vector<std::string> dados = preencher({"CPF (somente números)", "Nome", "Rua", "Telefone", "Data de Inicio (ddmmaa)"});
				try {
					cadastrar(new Paciente(dados), dados);
					std::cout << "Paciente Cadastrado!" << std::endl;
					opcao = "Voltar";
				} catch(std::invalid_argument &e) {
					std::cout << e.what() << std::endl;
					opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
				}
				std::cin.get();
			} while(opcao != "Voltar");
		} if (opcao == "Voltar para Pagina Inicial")
			break;
	}
}
void Sistema::marcarConsulta(std::vector<std::string>& dados) {
	std::vector<Psicologo*>::iterator psicologo = encontrar(psicologos, dados[0]); // Temp
	if(psicologo == psicologos.end())
		throw std::invalid_argument("Psicologo nao existe!");
	std::vector<Paciente*>::iterator paciente = encontrar(pacientes, dados[1]);
	if(paciente == pacientes.end())
		throw std::invalid_argument("Paciente nao existe!");
	(*paciente)->setPsicologoResponsavel((*psicologo)->getNome());
	(*psicologo)->adicionarConsulta((*paciente)->getNome(), dados[2], dados[3], dados[4], dados[5]);
}

void Sistema::imprimirAgenda(){
	if(psicologos.size() == 0)
		throw std::invalid_argument("Nenhum psicologo Cadastrado!");
	for(std::vector<Psicologo*>::iterator itr = psicologos.begin(); itr != psicologos.end(); itr++) {
		std::cout <<"Agenda de"<< (*itr)->getNome() << std::endl;
		(*itr)->imprimirConsultas();
	}
		std::cout << "Foi";
	std::cin.get();
}

void Sistema::cadastrar(Paciente *paciente, std::vector<std::string>& dados) {
	adicionar(paciente);
	salvar(dados, "paciente.txt");
}

void Sistema::cadastrar(Psicologo *psicologo, std::vector<std::string>& dados) {
	adicionar(psicologo);
	salvar(dados, "psicologo.txt");
}

void Sistema::cadastrar(Pessoa *secretaria, std::vector<std::string>& dados) {
	adicionar(secretaria);
	salvar(dados, "secretaria.txt");
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

std::vector<Psicologo*>::iterator Sistema::encontrar(std::vector<Psicologo*>& psicologos, std::string cpf) {
	std::vector<Psicologo*>::iterator itr;
	for(itr = psicologos.begin(); itr != psicologos.end(); itr++) {
		if( (*itr)->getCPF() == cpf )
			return itr;
	}
	return itr;
}

std::vector<Pessoa*>::iterator Sistema::encontrar(std::vector<Pessoa*>& secretarias, std::string cpf) {
	std::vector<Pessoa*>::iterator itr;
	for(itr = secretarias.begin(); itr != secretarias.end(); itr++) {
		if( (*itr)->getCPF() == cpf )
			return itr;
	}
	return itr;
}

std::vector<Paciente*>::iterator Sistema::encontrar(std::vector<Paciente*>& pacientes, std::string cpf) {
	std::vector<Paciente*>::iterator itr;
	for(itr = pacientes.begin(); itr != pacientes.end(); itr++) {
		if( (*itr)->getCPF() == cpf )
			return itr;
	}
	return itr;
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
				std::vector<Paciente*>::iterator paciente = encontrar(pacientes, cpf);
				if(paciente != pacientes.end()) {
					std::cout << "Digite o prontuario abaixo" << std::endl;
					std::cout << (*paciente)->getQueixa();
					std::string queixa;
					getline(std::cin, queixa);
					(*paciente)->addQueixa(queixa);
					std::cout << "Queixa cadastrada!" << std::endl;
					std::cin.get();
					opcao = "Voltar";
				} else {
					std::cout << "Nenhum paciente encontrado!" << std::endl;
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
