#include "agenda.h"

bool Agenda::isDiaSemana(int dia, int mes, int ano)
{
	int k;
	if(mes == 1) 
    {
		mes = 13;
		ano -= -1;
	} else if(mes == 2)	
    {
		mes=14;
		ano=ano-1;
	}

    //Formula para obter dia da semana k = 0 -> sabado, k = 1 -> domingo
	k = (dia + (2 * mes) + (3 * (mes + 1) / 5) + ano + (ano / 4) - (ano / 100) + (ano / 400) + 2);
	k %= 7;

    return !(k == 0 || k == 1);
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


Agenda::Agenda(int inicio, int fim)
	:
	aberturaClinica(7),
	fechamentoClinica(17)
{		
	if(inicio < aberturaClinica || inicio > fechamentoClinica || fim < aberturaClinica || fim > fechamentoClinica)
		throw std::invalid_argument("O horario de funcionamento da clinica e de 7h as 17h");

	for(int i = inicio; i <= fim; i++) {
		horarios.push_back(i);
	}
}

Agenda::Dia::Dia(int dia, int mes, int ano, std::vector<int> horarios) 
	:
	dia ( dia ),
	mes ( mes ),
	ano ( ano )
{
	id = gerarId(dia,mes,ano);
	for(unsigned int i = 0; i < horarios.size(); i++) {
		consultas[horarios[i]] = ("disponivel");
	}
}

void Agenda::adicionarDia(int dia, int mes, int ano, std::vector<int> horarios) {
	Dia novoDia = Dia(dia, mes, ano, horarios);

	if(dias.size() == 0)
		dias.push_front(Dia(dia, mes, ano, horarios));
	else if ( dias.front().id > novoDia.id)
			dias.push_front(Dia(dia, mes, ano, horarios));
	else if	( dias.back().id < novoDia.id)
			dias.push_back(Dia(dia, mes, ano, horarios));
	else {
		std::list<Dia>::iterator it;
		for(std::list<Dia>::iterator itr = dias.begin(); (*itr).id < novoDia.id; itr++) {
			it = itr;
		}
		dias.insert(it, novoDia);
	}
}

void Agenda::adicionarConsulta(std::string paciente, int dia, int mes, int ano, int hora) {
	if (!isDiaSemana(dia, mes, ano))
	{
		throw std::invalid_argument("A clinica so funciona de segunda a sexta");
	}
	else if(hora < aberturaClinica || hora > fechamentoClinica)
	{
		throw std::invalid_argument("O horario de funcionamento da clinica e de 7h as 17h");
	}
	// Instancia ou certifica de que o dia existe
	if(dias.size() == 0) {
		dias.push_front(Dia(dia, mes, ano, horarios));
	}
	
	std::list<Dia>::iterator itr = std::find(dias.begin(), dias.end(), Dia(dia, mes, ano, horarios));
	if(itr == dias.end()) {
		adicionarDia(dia, mes, ano, horarios);
		itr = std::find(dias.begin(), dias.end(), Dia(dia, mes, ano, horarios));
	}

	//Marca a consulta
	if( (*itr).consultas.count(hora) == 0 )
		throw std::invalid_argument("Horario fora do expediente do psicologo");
	if((*itr).consultas[hora] != "disponivel")
		throw std::invalid_argument("Horario ocupado");
	(*itr).consultas[hora] = paciente;
}

void Agenda::imprimirConsultas() {
	std::cout << "\t" << "Consultas" << std::endl;
	if(dias.size() == 0)
		throw std::invalid_argument("Nenhum Consulta Cadastrada!");
	else {
		for(std::list<Dia>::iterator itr = dias.begin(); itr != dias.end(); itr++) {
			std::cout << "Dia: "<< (*itr).dia << " Mes: "<< (*itr).mes << " Ano: "<< (*itr).ano << std::endl;
			for(std::map<int, std::string>::iterator it = (*itr).consultas.begin(); it != (*itr).consultas.end(); it++) {
				std::cout << it->first << ":00\t" << it->second << std::endl;
			}
		std::cout << std::endl;
		}
	}
}

void Agenda::desmarcarConsulta(int dia, int mes, int ano, int hora)
{
	// Encontrar consulta desejada
	std::list<Dia>::iterator itr = std::find(dias.begin(), dias.end(), Dia(dia, mes, ano, horarios));
	if(itr == dias.end()) {
		throw std::invalid_argument("Nao ha nenhuma consulta nesse dia");
	}
	if((*itr).consultas[hora] == "disponivel") {
		throw std::invalid_argument("Horario ja esta disponivel");
	}
	// Desmarca consulta
	(*itr).consultas[hora] = "disponivel";

	// Retira o dia caso ele esteja vazio
	bool diaLivre = true;
	for(std::map<int, std::string>::iterator it = (*itr).consultas.begin(); it != (*itr).consultas.end() ; it++) {
		diaLivre = diaLivre && (it->second == "disponivel");
	}
	if(diaLivre)
		dias.erase(itr);
}

std::string Agenda::getConsulta(int dia, int mes, int ano, int hora)
{
	std::list<Dia>::iterator itr = std::find(dias.begin(), dias.end(), Dia(dia, mes, ano, horarios));
	if(itr == dias.end())
		return "disponivel";
	else
		return (*itr).consultas[hora];
}
