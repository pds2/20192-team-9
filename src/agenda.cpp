#include "agenda.h"

Agenda::Agenda() 
{
   this->inicio = nullptr;
   this->fim = nullptr;
}

Agenda::~Agenda() 
{
   Node *anterior = nullptr;
   Node *proximo = this->inicio;
   while (proximo != nullptr) {
     anterior = proximo;
     proximo = proximo->proximo;
     delete anterior;
   }
}

void Agenda::marcar_consulta()
{
   Node *novo = new Node;
   novo->proximo=nullptr;
   novo->anterior=nullptr;
   int min, hora, dia, mes, ano;
   std::cout<<"Digite o horario da consulta(hora cheia em seguida os minutos):"<<"\n";
   std::cin>>hora>>min;
   std::cout<<"Digite a data da consulta( DD/MM/AAAA ):"<<"\n";
   std::cin>>dia>>mes>>ano;
   novo->data.min=min;
   novo->data.hora=hora;
   novo->data.mes=mes;
   novo->data.dia=dia;
   novo->data.ano=ano;
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

void Agenda::desmarcar_consulta(std::string paciente)
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
	Node *aux= this->inicio;
	while(aux->nome != paciente)
		aux=aux->proximo;
	std::cout<<"o paciente "<< aux->nome << " tem uma consulta marcada para o dia "<< aux->data.dia <<"/"<<aux->data.mes<<"/"<<aux->data.ano;
	std::cout<<"\n"<< "às "<<aux->data.hora<<":"<<aux->data.min;
}

