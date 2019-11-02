#include "sistema.h"


Sistema::Sistema() 
{
	std::vector<std::vector<std::string>> pacientesData = lerArquivo("paciente.txt");
	std::vector<std::vector<std::string>>::iterator itr;
	for(itr = pacientesData.begin(); itr != pacientesData.end(); itr++) {
		std::vector<std::string> pacienteData = *itr;
		registro[Paciente::nomeClasse].push_back(new Paciente(pacienteData));
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
	int entrada;
	Sistema::limparTela();
	logar();
	while (true) {
		Sistema::limparTela();
		Sistema::mostrarOpcoes({"Entrar como Secretaria","Entrar como Psicologo","Cadastrar Secretaria","Cadastrar Psicologo","Sair Do Programa"});

		std::cin >> entrada;
		Sistema::limparTela();
		if (entrada == 1) {
			ambienteSecretaria();
		} else if (entrada == 2) {
			ambientePsicologo();
		} else if (entrada == 3) {
			cadastrar<Secretaria>();
		} else if (entrada == 4) {
			cadastrar<Psicologo>();
		} else if (entrada == 5) {
			sair();
			break;
		}
	}
}

void Sistema::sair() 
{
	std::cout << "Obrigado por usar nosso programa!" << std::endl;
	std::cin.get();
}

void Sistema::ambienteSecretaria() {
	int entrada;
	while(true) {
		limparTela();
		mostrarOpcoes({"Visualizar Pacientes","Marcar Consulta","Cadastrar Pacientes", "Voltar para Pagina Inicial"});
		std::cin >> entrada;
		limparTela();
		if (entrada == 1) {
			imprimir<Paciente>();
		} else if (entrada == 2) {
			//marcarConsulta();
		} else if (entrada == 3) {
			cadastrar<Paciente>();
		} else if (entrada == 4) 
			break;
	}
}


void Sistema::ambientePsicologo() {

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
	std::vector<std::string> dados = preencher(T::cadastro);
	salvar(dados, T::arquivo);
	registro[T::nomeClasse].push_back(new T(dados));
	std::cout << "Cadastro Realizado!" << std::endl;
	std::cin.get();
}

void Sistema::logar() 
{
	bool flag = false;
	while(!flag){
		std::cout << "Bem vindo ao sistema da Clinica Social \n";
		std::cout << "Para fazer login, favor digitar o CPF: \n";
		std::string cpf;
		std::getline (std::cin, cpf);

		/*for(int i=0; i<this->pessoas["secretaria"]->size();i++){
			if(cpf==this->pessoas[i]->getCPF()){
				this->indice=i;
				flag=true;
				break;
			}
		}
		if(!flag){
			std::cout << "CPF nao encontrado \n";
			this->logar();
		}*/
		flag = true;
	}
}


template <typename T>
void Sistema::imprimir() 
{
    while(true) {
		std::vector<Pessoa*> pessoas = registro[T::nomeClasse];
		std::cout << "Nome|" << "Endereco|" << "Telefone|" << "Data de Entrada|" << "Data de Saida|" << "Psicologo Responsavel|" << "Queixa|" << "Mensalidade" << std::endl;
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

		mostrarOpcoes({"Limpar Pacientes", "Voltar"});
		
		int entrada;
		std::cin.ignore();
		std::cin >> entrada;
		if(entrada == 1) {
			limparTela();
			excluir<T>();
		} else if(entrada == 2) {
			break;
		}
	}
}

void Sistema::mostrarOpcoes(std::vector<std::string> opcoes)
{
	int i = 1;
	for(std::vector<std::string>::iterator it = opcoes.begin() ; it != opcoes.end(); it++) {
		std::cout << i << ". " << *it << std::endl;
		i++;
	}
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
	std::cin.ignore();
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