#include "agenda.h"
#include <iostream>
#include <stdbool.h>

Agenda::Agenda() 
{
   inicio = nullptr;
   fim = nullptr;
}

Agenda::~Agenda() 
{
   node *anterior = nullptr;
   node *proximo = inicio;
   while (proximo != nullptr) {
     anterior = proximo;
     proximo = proximo->proximo;
     delete anterior;
   }
}

void Agenda::Marcar_consulta()
{
   Node *novo = new Node;
   novo->proximo=nullptr;
   novo->anterior=nullptr;
   int min, hora, dia, mes, ano;
   std::cout<<"Digite o horario da consulta(hora cheia em seguida os minutos):"<<endl;
   std::cin>>hora>>min;
   std::cout<<"Digite a data da consulta( DD/MM/AAAA ):"<<endl;
   std::cin>>dia>>mes>>ano;
   novo->Data_consulta->min=min;
   novo->Data_consulta->hora=hora;
   novo->Data_consulta->mes=mes;
   novo->Data_consulta->dia=dia;
   novo->Data_consulta->ano=ano;
   if(this->inicio==nullptr)
   {
   		this->inicio=novo;
   		this->fim=novo;
   }
   else
   {
   		this->fim->proximo=novo;
   		novo->anterior=this->fim;
   		this->fim=novo;
   }
}

void Agenda::Desmarcar_consulta(std::string paciente)
{
	Node *aux=nullptr;
	Node *aux2=nullptr;
	Node *remover= this->inicio;
	while(remover->nome !=paciente)
		remover=remover->proximo;
	aux=remover->anterior;
	aux2=remover->proximo;
	aux->proximo=aux2;
	aux2->anterior=aux;
	delete remover;
	
}

void Agenda::get_consulta (std::string paciente)
{
	Node *aux=inicio;
	while(aux->nome != paciente)
		aux=aux->proximo;
	std::cout<<"o paciente "<< aux->nome << " tem uma consulta marcada para o dia "<< aux->Data_consulta->dia <<"/"<<aux->Data_consulta->mes<<"/"<<aux->Data_consulta->ano;
	std::cout<<endl<< "às "<<aux->Data_consulta->hora<<":"<<aux->Data_consulta->min;
}