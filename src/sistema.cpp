#include "sistema.h"


Sistema::Sistema() 
{
	std::vector<std::vector<std::string>> pacientesData = lerArquivo("paciente.txt");
	std::vector<std::vector<std::string>> secretariasData = lerArquivo("secretaria.txt");
	std::vector<std::vector<std::string>> psicologosData = lerArquivo("psicologo.txt");
	std::vector<std::vector<std::string>>::iterator itr;
	for(itr = pacientesData.begin(); itr != pacientesData.end(); itr++) {
		pacientes.push_back(new Paciente(*itr));
	}
	for(itr = secretariasData.begin(); itr != secretariasData.end(); itr++) {
		secretarias.push_back(new Pessoa(*itr));
	}
	for(itr = psicologosData.begin(); itr != psicologosData.end(); itr++) {
		psicologos.push_back(new Psicologo(*itr));
	}
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

int Sistema::mostrarOpcoes(std::vector<std::string> opcoes)
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
			flag = false;
		} catch(std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cin.ignore(10000, '\n');
	return e;
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
		if(*itr== "CPF"){
			bool flag =validar_CPF(entrada);
			while(!flag){
				limparTela();
				std::cout<<"CPF invalido, por favor digite novamente: ";
				getline(std::cin, entrada);
				flag =validar_CPF(entrada);
			}
		}
		dados.push_back(entrada);
	}
	return dados;
}

void Sistema::sair() 
{
	limparTela();
	std::cout << "Obrigado por usar nosso programa!" << std::endl;
}
bool Sistema::validar_CPF(std::string cpf){
	int cpfFinal[11];
	if(cpf.length()!=11){
		return false;
	}else{
		for(unsigned int i=0; i<cpf.length();i++){
			int number=(int)cpf[i]-'0';
			
			if(number<0||number>9){
				return false;
			}else{
				cpfFinal[i]=number;
			}
		}
		int dezena, unidade;
		int soma1 = (cpfFinal[0]*2+cpfFinal[1]*3+cpfFinal[2]*4+cpfFinal[3]*5+cpfFinal[4]*6+cpfFinal[5]*7+cpfFinal[6]*8+cpfFinal[7]*9+cpfFinal[8]*10);
    	int resto1 = soma1%11;
    	if (resto1==0 || resto1==1){
       		unidade=0;
    	}else {
            unidade = 11-resto1;
        }
        int soma2 = (unidade*2+cpfFinal[0]*3+cpfFinal[1]*4+cpfFinal[2]*5+cpfFinal[3]*6+cpfFinal[4]*7+cpfFinal[5]*8+cpfFinal[6]*9+cpfFinal[7]*10+cpfFinal[8]*11);
    	int resto2 = soma2%11;
     	if (resto2==0 || resto2==1){
       		dezena=0;
    	}else {
        	dezena = 11-resto2;
        }
        if(cpfFinal[9]!=dezena||cpfFinal[10]!=unidade){
        	return false;
        }else{
        	return true;
        }
	}
}
void Sistema::paginaInicial() 
{
	while (true) {
		limparTela();
		int e = mostrarOpcoes({"Fazer Login","Cadastrar Secretaria","Cadastrar Psicologo","Visualizar Secretarias", "Visualizar Psicologos","Sair Do Programa"});
		if (e == 1) {
			logar();
		} else if (e == 2) {
			cadastrarSecretaria();
		} else if (e == 3) {
			cadastrarPsicologo();
		} else if (e == 4) {
			imprimirSecretaria("secretaria.txt");
		} else if (e == 5) {
			imprimirPsicologo("psicologo.txt");
		} else if (e == 6) {
			sair();
			break;
		}
	}
}

void Sistema::cadastrarSecretaria() {
	std::vector<std::string> cadastro = {"CPF", "Nome", "Rua", "Telefone", "Data de Inicio"};
	bool flag = true;
	limparTela();
	while(flag) {
		
		try {
			std::vector<std::string> dados = preencher(cadastro);
			secretarias.push_back(new Pessoa(dados));
			salvar(dados, "secretaria.txt");
			flag = false;
		} catch(std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void Sistema::cadastrarPsicologo() {
	std::vector<std::string> cadastro = {"CPF", "Nome", "Rua", "Telefone", "Data de Inicio", "CRP" , "Inicio Expediente", "Fim Expediente"};
	bool flag = true;
	limparTela();
	while(flag) {
		try {
			std::vector<std::string> dados = preencher(cadastro);
			psicologos.push_back(new Psicologo(dados));
			salvar(dados, "psicologo.txt");
			flag = false;
		} catch(std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void Sistema::cadastrarPaciente() {
	std::vector<std::string> cadastro = {"CPF", "Nome", "Rua", "Telefone", "Data de Inicio"};
	bool flag = true;
	limparTela();
	while(flag) {
		try {
			std::vector<std::string> dados = preencher(cadastro);
			pacientes.push_back(new Paciente(dados));
			salvar(dados, "paciente.txt");
			flag = false;
		} catch(std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void Sistema::logar() 
{
	bool flag = true;
	while(flag){
		limparTela();
		std::cout << "Bem vindo ao sistema da Clinica Social \n";
		std::cout << "Para fazer login, favor digitar o CPF: \n";
		std::string cpf;
		std::getline(std::cin, cpf);

		std::string logado;
		for(std::vector<Pessoa*>::iterator itr = secretarias.begin(); itr != secretarias.end(); itr++) {
			if((*itr)->getCPF() == cpf) {
				secretariaUsuario = *itr;
				logado = "secretaria";
				break;
			}
		}
		for(std::vector<Psicologo*>::iterator itr = psicologos.begin(); itr != psicologos.end(); itr++) {
			if((*itr)->getCPF() == cpf) {
				psicologoUsuario = *itr;
				logado = "psicologo";
				break;
			}
		}

		if (logado == "secretaria") {
			ambienteSecretaria();
			flag = false;
		}
		else if (logado == "psicologo") {
			ambientePsicologo();
			flag = false;
		}
		else {
			limparTela();
			std::cout << "CPF nao encontrado! \n";
			int e = mostrarOpcoes({"Tentar novamente", "Voltar"});
			if (e == 2) {
				flag = false;
			}
		}
	}
}

void Sistema::ambienteSecretaria() 
{
	while(true) {
		limparTela();
		std::cout << "Logado:\t" << secretariaUsuario->getNome() << "\t" << "Secretaria" << std::endl;
		int e = mostrarOpcoes({"Visualizar Pacientes","Marcar Consulta","Cadastrar Pacientes", "Voltar para Pagina Inicial"});
		if (e == 1) {
			imprimirPaciente("paciente.txt");
		} else if (e == 2) {
			//marcarConsulta();
		} else if (e == 3) {
			cadastrarPaciente();
		} else if (e == 4) 
			break;
	}
}

void Sistema::ambientePsicologo() 
{
	while(true) {
		limparTela();
		std::cout << "Logado:\t" << psicologoUsuario->getNome() << "\t" << "Psicologo" << std::endl;
		int e = mostrarOpcoes({"Consultar Agenda","Escrever Prontuario", "Consultar Prontuario","Voltar para Pagina Inicial"});
		if (e == 1) {
			consultarAgenda();
		} else if (e == 2) {
			escreverProntuario();
		} else if (e == 3) {
			//consultar_prontuario();
		}else if (e == 4) 
			break;
	}
}

void Sistema::consultarAgenda() 
{
	bool flag = true;
	limparTela();
	while(flag) {
		psicologoUsuario->imprimirConsultas();
		std::cout << "Imprimindo Consultas" << std::endl;
		int e = mostrarOpcoes({"Voltar"});
		if(e == 1)
			flag = false;
	}
}

void Sistema::escreverProntuario() 
{
	std::cout << "Informe CPF:" << std::endl;
	std::string cpf;
	std::cin >> cpf;
	for(std::vector<Paciente*>::iterator itr = pacientes.begin(); itr != pacientes.end(); itr++) {
		if( (*itr)->getCPF() == cpf ) {
			limparTela();
			std::cout << "Digite o prontuario" << std::endl;
			std::string queixa;
			std::cin >> queixa;
			(*itr)->setQueixa(queixa);
		}
	}
}

void Sistema::imprimirPaciente(const char* arquivo) 
{
    while(true) {
		limparTela();
		std::cout << std::endl;
		std::cout << "=============================================================================================" << std::endl;
		if(pacientes.size() == 0)
			std::cout << "Nenhum paciente cadastrado" << std::endl;
		else  {
			for(std::vector<Paciente*>::iterator itr = pacientes.begin(); itr != pacientes.end(); itr++) {
				(*itr)->imprimirDados();
			}
		}
		std::cout << "=============================================================================================" << std::endl;
	
		int e = mostrarOpcoes({"Limpar Tudo", "Voltar"});
		if(e == 1) {
			remove(arquivo);
			pacientes.clear();
		} else if(e == 2)
			break;
	}
}

void Sistema::imprimirSecretaria(const char* arquivo) 
{
    while(true) {
		limparTela();
		std::cout << std::endl;
		std::cout << "=============================================================================================" << std::endl;
		if(secretarias.size() == 0)
			std::cout << "Nenhuma secretaria cadastrado" << std::endl;
		else  {
			for(std::vector<Pessoa*>::iterator itr = secretarias.begin(); itr != secretarias.end(); itr++) {
				(*itr)->imprimirDados();
			}
		}
		std::cout << "=============================================================================================" << std::endl;
	
		int e = mostrarOpcoes({"Limpar Tudo", "Voltar"});
		if(e == 1) {
			remove(arquivo);
			secretarias.clear();
		} else if(e == 2)
			break;
	}
}

void Sistema::imprimirPsicologo(const char* arquivo) 
{
    while(true) {
		limparTela();
		std::cout << std::endl;
		std::cout << "=============================================================================================" << std::endl;
		if(psicologos.size() == 0)
			std::cout << "Nenhum psicologo cadastrado" << std::endl;
		else  {
			for(std::vector<Psicologo*>::iterator itr = psicologos.begin(); itr != psicologos.end(); itr++) {
				(*itr)->imprimirDados();
			}
		}
		std::cout << "=============================================================================================" << std::endl;
	
		int e = mostrarOpcoes({"Limpar Tudo", "Voltar"});
		if(e == 1) {
			remove(arquivo);
			psicologos.clear();
		} else if(e == 2)
			break;
	}
}

