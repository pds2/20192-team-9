#include "sistema.h"


Sistema::Sistema() 
{
	std::vector<std::vector<std::string>> pacientesData = lerArquivo("paciente.txt");
	carregar<Paciente>(pacientesData);
	std::vector<std::vector<std::string>> secretariaData = lerArquivo("secretaria.txt");
	carregar<Secretaria>(secretariaData);
	std::vector<std::vector<std::string>> psicologoData = lerArquivo("psicologo.txt");
	carregar<Psicologo>(psicologoData);
	
}

template <typename T>
void Sistema::carregar(std::vector<std::vector<std::string>> data) {
	std::vector<std::vector<std::string>>::iterator itr;
	for(itr = data.begin(); itr != data.end(); itr++) {
		std::vector<std::string> data = *itr;
		registro[T::nomeClasse].push_back(new T(data));
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


Sistema::~Sistema() {}

void Sistema::paginaInicial() 
{
	while (true) {
		limparTela();
		int e = mostrarOpcoes({"Fazer Login","Cadastrar Secretaria","Cadastrar Psicologo","Visualizar Secretarias", "Visualizar Psicologos","Sair Do Programa"});
		if (e == 1) {
			logar();
		} else if (e == 2) {
			cadastrar<Secretaria>();
		} else if (e == 3) {
			cadastrar<Psicologo>();
		} else if (e == 4) {
			imprimir<Secretaria>();
		} else if (e == 5) {
			imprimir<Psicologo>();
		} else if (e == 6) {
			sair();
			break;
		}
	}
}

void Sistema::sair() 
{
	limparTela();
	std::cout << "Obrigado por usar nosso programa!";
	std::cin.get();
}

void Sistema::ambienteSecretaria() {
	while(true) {
		limparTela();
		int e = mostrarOpcoes({"Visualizar Pacientes","Marcar Consulta","Cadastrar Pacientes", "Voltar para Pagina Inicial"});
		if (e == 1) {
			imprimir<Paciente>();
		} else if (e == 2) {
			//marcarConsulta();
		} else if (e == 3) {
			cadastrar<Paciente>();
		} else if (e == 4) 
			break;
	}
}


void Sistema::ambientePsicologo() {
while(true) {
		limparTela();
		int e = mostrarOpcoes({"Consultar Agenda","Escrever Prontuario", "Consultar Prontuario","Voltar para Pagina Inicial"});
		if (e == 1) {
			//consultarAgenda();
		} else if (e == 2) {
			escreverProntuario();
		} else if (e == 3) {
			//consultar_prontuario();
		}else if (e == 4) 
			break;
	}
}

void Sistema::escreverProntuario() {
	std::cout << "Informe CPF:" << std::endl;
	std::string cpf;
	std::cin >> cpf;
	std::vector<Pessoa*> pacientes = registro["paciente"];
	for(std::vector<Pessoa*>::iterator itr = pacientes.begin(); itr != pacientes.end(); itr++) {
		Pessoa *p = (*itr);
		if( p->getCPF() == cpf ) {
			limparTela();
			std::cout << "Digite o prontuario" << std::endl;
			std::string queixa;
			std::cin >> queixa;
			p->setInformacao(queixa);
		}
	}
}

template<typename T>
void Sistema::excluir() 
{
	const char* arquivo = T::arquivo.c_str();
	remove(arquivo);
	T::quantidade = 0;
	registro[T::nomeClasse].clear();
}

template <typename T>
void Sistema::cadastrar() {
	limparTela();
	std::vector<std::string> dados = preencher(T::cadastro);
	salvar(dados, T::arquivo);
	registro[T::nomeClasse].push_back(new T(dados));
	std::cout << "Cadastro Realizado!" << std::endl;
	std::cin.get();
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

		if (isCadastrado(cpf, "secretaria")) {
			ambienteSecretaria();
			break;
		}
		else if (isCadastrado(cpf, "psicologo")) {
			ambientePsicologo();
			break;
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

bool Sistema::isCadastrado(std::string cpf, std::string funcionario) {
	std::vector<Pessoa*>::iterator itr;
	std::vector<Pessoa*> pessoas = registro[funcionario];
	for(itr = pessoas.begin(); itr != pessoas.end(); itr++) {
		Pessoa* pessoa = *itr;
		if(cpf == pessoa->getCPF()) {
			return true;
		}
	}
	return false;
}


template <typename T>
void Sistema::imprimir() 
{
    while(true) {
		limparTela();
		std::vector<Pessoa*> pessoas = registro[T::nomeClasse];
		std::vector<std::string>::iterator itr;
		for(itr = T::dados.begin(); itr != T::dados.end(); itr++) {
			std::cout << *itr << "|";
		} 
		std::cout << std::endl;
		std::cout << "=============================================================================================" << std::endl;
		if(pessoas.size() == 0) {
			std::cout << "Nenhum " << T::nomeClasse << " Cadastrado" << std::endl;
		} else  {
			for(std::vector<int>::size_type i = 0; i != pessoas.size(); i++) {
				Pessoa* pessoa = pessoas[i];
				pessoa->imprimirDados();
			}
		}
		std::cout << "=============================================================================================" << std::endl;
		std::cout << "Total de " << T::nomeClasse << "s : " << T::quantidade << std::endl;

		
		int e = mostrarOpcoes({"Limpar " + T::nomeClasse + "s", "Voltar"});
		if(e == 1) {
			excluir<T>();
		} else if(e == 2) {
			break;
		}
	}
}

int Sistema::mostrarOpcoes(std::vector<std::string> opcoes)
{
	int i = 1;
	int e;
	std::string entrada;
	for(std::vector<std::string>::iterator it = opcoes.begin() ; it != opcoes.end(); it++) {
		std::cout << i << ". " << *it << std::endl;
		i++;
	}
	getline(std::cin,entrada);
	try {
		e = std::stoi(entrada);
	} catch (std::invalid_argument) {
		std::cout << "Entrada invalida! Digite um numero" << std::endl;
		std::cin.get();
		return 0;
	}
	return e;
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

	for(std::vector<int>::size_type i = 0; i != campos.size(); i++) {
		std::string entrada;
		std::cout << campos[i];
		getline(std::cin, entrada);
		dados.push_back(entrada);
	}
	return dados;
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
