#include "usuarioSecretaria.h"



usuarioSecretaria::usuarioSecretaria(Sistema &in_sys) 
	:
	sys ( in_sys )
{
	std::ifstream infile("paciente.txt");
	while(infile) {
		std::string s;
		if (!getline(infile, s)) break;
		std::istringstream ss( s );
		std::vector<std::string> pessoa;
		while(ss) {
			std::string s;
			if(!getline(ss, s, ',')) break;
			pessoa.push_back(s);
		}
		registro["paciente"].push_back(new Paciente(pessoa[0], pessoa[1], pessoa[2], pessoa[3]));
	}
}

void usuarioSecretaria::paginaInicial() {
    int entrada;
    while (true) {
		Sistema::limparTela();
		Sistema::mostrarOpcoes({"Visualizar Pacientes","Marcar Consulta","Cadastrar Pacientes", "Voltar para Pagina Inicial"});
		std::cin >> entrada;
		Sistema::limparTela();
		if (entrada == 1) {
			imprimir<Paciente>();
		} else if (entrada == 2) {
			//marcarConsulta();
		} else if (entrada == 3) {
			cadastrar<Paciente>();
		} else if (entrada == 4) {
			break;
		}
	}
}

template <typename T>
void usuarioSecretaria::imprimir() {
    while(true) {
		std::vector<Pessoa*> pessoas =  registro[T::nomeClasse];
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

		Sistema::mostrarOpcoes({"Limpar Pacientes", "Voltar"});
		
		int entrada;
		std::cin.ignore();
		std::cin >> entrada;
		if(entrada == 1) {
			Sistema::limparTela();
			excluir<T>();
		} else if(entrada == 2) {
			break;
		}
	}
}

template<typename T>
void usuarioSecretaria::excluir() {
	const char* arquivo = T::arquivo.c_str();
	remove(arquivo);
	T::quantidade = 0;
	registro[T::nomeClasse].clear();
}

template<typename T>
void usuarioSecretaria::cadastrar() {
	std::vector<std::string> dados = sys.preencher(T::cadastro);
	sys.salvar(dados, T::arquivo);
	registro[T::nomeClasse].push_back(new T(dados));
	std::cout << "Cadastro Realizado!" << std::endl;
	std::cin.get();
}