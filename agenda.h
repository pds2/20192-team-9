#ifndef AGENDA_H_
#define AGENDA_H_

struct Data_consulta
{
	int min, hora, dia, mes, ano;
};

struct Node
{
	std::string nome;
	Data_consulta data;
	Node *proximo;
	Node *anterior;

};

struct Agenda
{
	Node *proximo;
	Node *anterior;
	Agenda();
	~Agenda();
	void Marcar_consulta();
	void Desmarcar_consulta();
	void get_consulta();
};


#endif