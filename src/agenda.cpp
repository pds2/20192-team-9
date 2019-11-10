#include "agenda.h"

int CalcularDiaDaSemana(int d, int m, int a)
{
	int k;
	if(m==1)
	{
		m=13;
		a=a-1;
	}
	else if(m==2)
	{
		m=14;
		a=a-1;
	}

	k=(d+(2*m)+(3*(m+1)/5)+a+(a/4)-(a/100)+(a/400)+2);

	k=(k/7);

	if (k==0 || k==1)
		return 0;
	else
		return 1;
}

int VerificarHoraConsulta(int h)
{
	if (h<7 || h>17)
	{
		return 0;
	}
	else
		return 1;
}

std::string gerarId(int dia, int mes, int ano)
{
	std::string id="";
	id += std::to_string(ano);
	if (mes<10)
		id += "0";
	id += std::to_string(mes);
	if(dia<10)
		id += "0";
	id += std::to_string(dia);

	return id;

}


Agenda::Agenda()
{
	std::cout<<"Quais sao os horarios deste psicologo? (ex.: 17h = 17 , 09h = 9)";
	for (int i = 0; i < 5; i++)
	{
		std::cin>>this -> hora[i];
		std::cout<<std::endl;
	}
}

Agenda::~Agenda() 
{
   Consulta *anterior = nullptr;
   Consulta *proximo = this-> inicio;
   while (proximo != nullptr) 
   {
     anterior = proximo;
     proximo = proximo-> proximo;
     delete anterior;
   }
}

void Agenda::adicionarConsulta(std::string paciente, int dia, int mes, int ano, int hora)
{
	if (CalcularDiaDaSemana(dia, mes, ano)==0)
	{
		std::cout<<"A clinica so funciona de segunda a sexta";
	}
	else if(VerificarHoraConsulta(hora)==0)
	{
		std::cout<<"O horario de funcionamento da clinica e de 7h as 17h";
	}


	else
	{
		//cria um ponteiro do tipo consulta para percorrer a agenda e verificar se ja existe umca consulta com esta data 
		Consulta *percorre = this -> proxConsulta;

		bool existeConsulta = false;
		//variavel com o id da consulta
		std::string id = gerarId(dia, mes, ano);

		//percorre a agenda da proxima consulta ate o fim
		while(percorre -> proximo != nullptr)
		{
			//verifica se ja existe uma consulta com o mesmo id
			if(percorre -> id == id)
			{
				//se existir, variavel do tipo bool recebe true e sai do escopo da funcao while
				existeConsulta = true;
				break;
			}
			percorre = percorre -> proximo;
		}

		//caso nao exista consulta com o mesmo id
		if (existeConsulta == false)
		{
			//cria uma nova consulta
			Consulta *novo = new Consulta;
		
			//preenche as variaveis de consulta com os parametros passados
			//novo-> paciente = paciente;
			novo-> data.dia = dia;
			novo-> data.mes = mes;
			novo-> data.ano = ano;
			novo-> id = id;
			for (int i = 0; i < 5; i++)
			{
				novo ->  horario[i].hora = this -> hora[i];
				if(novo->horario[i].hora==hora)
					novo->horario[i].paciente = paciente;

			}
			//caso nao exista nenhuma consulta na Agenda
			if(this->inicio==nullptr)
			{
				this-> inicio = novo;
				this-> proxConsulta = novo;
				this-> fim = novo;
			}
			//caso seja a consulta com a data mais distante
			else if(this -> fim -> id < novo -> id)
			{
				this -> fim -> proximo = novo;
				novo -> anterior = this -> fim;
				this -> fim = novo;
			}

			else
			{
				//cria um ponteiro que aponta para consulta mais recente
				Consulta *percorrer = this -> proxConsulta;
				//cria um ponteiro auxiliar 
				Consulta *aux = nullptr;
				//percorre a lista ate encontrar a posicao da lista em ordem cronologica
				while(percorrer -> id < novo -> id)
					percorrer = percorrer -> proximo;

				aux = percorrer -> anterior;

				aux -> proximo = novo;
				novo -> anterior = aux;
				novo -> proximo = percorrer;
				percorrer -> anterior = novo;
			}
		}

		//caso ja exista consulta com mesmo id
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if(percorre->horario[i].hora==hora)
					percorre->horario[i].paciente = paciente;
			}
		}
	}

}

void Agenda::desmarcarConsulta(std::string paciente, int dia, int mes, int ano)
{
	//gera o id do dia passado
	std::string id = gerarId(dia, mes, ano);
	//variavel para verificar se existe qualquer consulta marcada no dia
	bool existeConsulta = false;
	//ponteiro para percorrer a agenda
	Consulta *percorrer = proxConsulta;
	//percorre a agenda
	while(percorrer -> proximo != nullptr)
	{
		//caso exista qualquer consulta marcada no dia passado
		if(percorrer -> id == id)
			{
				//se existir, variavel do tipo bool recebe true e sai do escopo da funcao while
				existeConsulta = true;
				break;
			}
			percorrer = percorrer -> proximo;
	}
	//caso nao exista nenhuma consulta marcada no dia passado
	if(existeConsulta==false)
		std::cout<<"Nao ha nenhuma consulta marcada neste dia";
	
	//caso existam consultas marcadas no dia passado
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if(percorrer -> horario[i].paciente == paciente)
			{
				//torna o horario disponivel neste dia
				percorrer ->horario[i].paciente = "disponivel";
				break;
			}
			//caso nao tenha consultas marcadas para o paciente passado
			std::cout<<paciente<<" nao tem consulta marcada neste dia";
		}
	}
}

std::string Agenda::consultarAgendaDia(int dia, int mes, int ano)
{
	//cria a string que sera retornada
	std::string retorna="";
	//gera o id do dia passado
	std::string id = gerarId(dia, mes, ano);
	//variavel para verificar se existe qualquer consulta marcada no dia
	bool existeConsulta = false;
	//ponteiro para percorrer a agenda
	Consulta *percorrer = proxConsulta;
	//percorre a agenda
	while(percorrer -> proximo != nullptr)
	{
		//caso exista qualquer consulta marcada no dia passado
		if(percorrer -> id == id)
			{
				//se existir, variavel do tipo bool recebe true e sai do escopo da funcao while
				existeConsulta = true;
				break;
			}
			percorrer = percorrer -> proximo;
	}
	//caso nao exista nenhuma consulta marcada no dia passado
	if(existeConsulta==false)
		retorna="Nao ha nenhuma consulta marcada neste dia";
	
	//caso existam consultas marcadas no dia passado
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (percorrer->horario[i].paciente=="disponivel")
			{
				retorna +="horario das ";
				retorna += std::to_string(percorrer->horario[i].hora);
				retorna +="h esta disponivel		";
			}
			else
			{
				retorna += percorrer -> horario[i].paciente;
				retorna += "	as ";
				retorna += std::to_string(percorrer -> horario[i].hora);
				retorna += "h 		";
			}
		}
	}
	return retorna;
}

std::string Agenda::horarioDisponivel(int dia, int mes, int ano)
{
	//gera o id do dia passado
	std::string id = gerarId(dia, mes, ano);
	//cria a string que sera retornada
	std::string retorna="";
	//variavel para verificar se existe qualquer consulta marcada no dia
	bool existeConsulta = false;
	//ponteiro para percorrer a agenda
	Consulta *percorrer = proxConsulta;
	//percorre a agenda
	while(percorrer -> proximo != nullptr)
	{
		//caso exista qualquer consulta marcada no dia passado
		if(percorrer -> id == id)
			{
				//se existir, variavel do tipo bool recebe true e sai do escopo da funcao while
				existeConsulta = true;
				break;
			}
			percorrer = percorrer -> proximo;
	}
	//caso nao exista nenhuma consulta marcada com esta data
	if (existeConsulta==false)
	{
		int j = CalcularDiaDaSemana(dia, mes, ano);
		//caso seja um final de semana
		if (j==0)
		{
			retorna = "A data passada e um final de semana. A clinica so funciona de segunda a sexta.";
		}
		//caso seja durante a semana
		else
		{
			retorna="Todos os horarios estao disponiveis nesta data";
		}
	}
	//caso exista consulta marcada com a data passada
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (percorrer->horario[i].paciente=="disponivel")
			{
				retorna += "O horario de ";
				retorna += std::to_string(percorrer->horario[i].hora);
				retorna += "h esta disponivel";
			}
			else
			{
				retorna += "O horario de ";
				retorna += std::to_string(percorrer->horario[i].hora);
				retorna += "h nao esta disponivel";
			}
		}
	}

	return retorna;
}

void Agenda::fimConsulta()
{
	proxConsulta = proxConsulta -> proximo;
}
