#include "agenda.h"

Agenda::Agenda() 
{
   this-> inicio = nullptr;
   this-> fim = nullptr;
   this-> proxConsulta = nullptr;
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

void Agenda::adicionarConsulta(std::string paciente, int dia, int mes, int ano, int hora, int min)
{
	//cria uma nova consulta
	Consulta *novo = new Consulta;
	
	//preenche as variaveis de consulta com os parametros passados
	novo-> paciente = paciente;
	novo-> data.dia = dia;
	novo-> data.mes = mes;
	novo-> data.ano = ano;
	novo-> hora.hora = hora;
	novo-> hora.min = min;
	//cria o id da consulta
	novo -> id += std::to_string(ano);
	if(mes < 10)
		novo -> id += "0";
	novo -> id += std::to_string(mes);
	if(dia < 10)
		novo -> id += "0";
	novo -> id += std::to_string(dia);
	if(hora < 10)
		novo -> id += "0";
	novo -> id += std::to_string(hora);
	if(min < 10)
		novo -> id += "0";
	novo -> id += std::to_string(min);

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
		//cria um ponteiro que aponta para consulta mais recente e que percorre a agenda
		Consulta *percorrer = this -> proxConsulta;
		//cria um ponteiro auxiliar 
		Consulta *aux = nullptr;
		//percorre a lista ate encontrar a posicao da consulta em ordem cronologica
		while(percorrer -> id < novo -> id)
			percorrer = percorrer -> proximo;

		aux = percorrer -> anterior;

		aux -> proximo = novo;
		novo -> anterior = aux;
		novo -> proximo = percorrer;
		percorrer -> anterior = novo;
	}
}

void Agenda::desmarcarConsulta(int dia, int mes, int ano, int hora, int min)
{
	//cria uma string para receber o id da consulta a ser desmarcada
	std::string id = "";
	//cria ponteiro para percorrer a Agenda e ponteiros auxiliares necessarios para deletar a consulta
	Consulta *percorrer = this -> proxConsulta;
	Consulta *anterior = nullptr , *proximo = nullptr;
	
	//preenche a string com a id da consulta a ser desmarcada
	id += std::to_string(ano);
	if(mes < 10)
		id += "0";
	id += std::to_string(mes);
	if(dia < 10)
		id += "0";
	id += std::to_string(dia);
	if(hora < 10)
		id += "0";
	id += std::to_string(hora);
	if(min < 10)
		id += "0";
	id += std::to_string(min);

	//percorre a Agenda ate encontrar a consulta a ser removida
	while(id != percorrer -> id)
		percorrer = percorrer -> proximo;

	//remove a consulta
	anterior = percorrer -> anterior;
	proximo = percorrer -> proximo;

	anterior -> proximo = proximo;
	proximo -> anterior = anterior;

	delete percorrer;
}

void Agenda::desmarcarConsulta(std::string id)
{
	//cria ponteiro para percorrer a Agenda e ponteiros auxiliares necessarios para deletar a consulta
	Consulta *percorrer = this -> proxConsulta;
	Consulta *anterior = nullptr , *proximo = nullptr;

	//percorre a Agenda ate encontrar a consulta a ser removida
	while(id != percorrer -> id)
		percorrer = percorrer -> proximo;

	//remove a consulta
	anterior = percorrer -> anterior;
	proximo = percorrer -> proximo;

	anterior -> proximo = proximo;
	proximo -> anterior = anterior;

	delete percorrer;
}
	

std::string Agenda::proximaConsulta()
{
	//cria uma string que sera o retorno do metodo
	std::string retorna = "";
	//preenche a string com as informacoes da proxima consulta
	retorna += this -> proxConsulta -> paciente;
	retorna += "	no dia ";
	retorna += std::to_string(this -> proxConsulta ->data.dia);
	retorna += "/";
	retorna += std::to_string(this -> proxConsulta ->data.mes);
	retorna += "/";
	retorna += std::to_string(this -> proxConsulta ->data.ano);
	retorna += "	as ";
	retorna += std::to_string(this -> proxConsulta -> hora.hora);
	retorna += "h";
	retorna += std::to_string(this -> proxConsulta -> hora.min);
	retorna += "min.";

	return retorna;
}

std::string Agenda::consultarAgendaDia(int dia, int mes, int ano)
{
	//cria duas strings auxiliares que contem o menor id possivel do dia passado e o maior id possivel do dia passado. 
	std::string menorDia = "";
	std::string maiorDia = "";
	//cria a string que sera retornada.
	std::string retorna = "";
	//cria ponteiro auxiliar para percorrer a Agenda
	Consulta *percorrer = this -> proxConsulta;

	//preenche as strings menorDia e maiorDia
	menorDia += std::to_string(ano);
	maiorDia += std::to_string(ano);
	if(mes < 10)
	{
		menorDia += "0";
		maiorDia += "0";
	}
	menorDia += std::to_string(mes);
	maiorDia += std::to_string(mes);
	if(dia < 10)
	{
		menorDia += "0";
		maiorDia += "0";
	}
	menorDia += std::to_string(dia);
	maiorDia += std::to_string(dia);
	maiorDia += "24";
	for(int i = 0; i <2; i++)
		maiorDia += "0";
	for(int i = 0; i < 4; i++)
		menorDia += "0";


	//percorre a agenda ate chegar no dia desejado
	while(percorrer -> id < menorDia)
		percorrer = percorrer -> proximo;


	//adiciona as informaçoes necessarias a string que sera retornada
	while(percorrer -> id <= maiorDia)
	{
		retorna += percorrer -> paciente;
		retorna += "	as ";
		retorna += std::to_string(percorrer -> hora.hora);
		retorna += "h";
		retorna += std::to_string(percorrer -> hora.min);
		retorna += "min.		";
	}

	return retorna;
}

void Agenda::fimConsulta()
{
	this -> proxConsulta = this -> proxConsulta -> proximo;	
}


