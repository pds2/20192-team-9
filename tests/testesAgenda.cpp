#include "doctest.h"
#include "agenda.h"

TEST_CASE("01 - Testando construtor Agenda") {
    CHECK_NOTHROW(Agenda(8, 13));
    CHECK_NOTHROW(Agenda(12, 17));
    CHECK_THROWS(Agenda(5,10));     // Expediente com clinica fechada
    CHECK_THROWS(Agenda(13,18));    // Expediente com clinica fechada
}

TEST_CASE("02 - Marcando e Desmarcando Consultas") {
    Agenda agenda(8, 13);
    agenda.adicionarConsulta("Carlos", 20, 11, 2019, 9);
    CHECK(agenda.getConsulta(20,11,2019,9) == "Carlos");
    CHECK(agenda.getConsulta(22,11,2019,12) == "disponivel");

    agenda.desmarcarConsulta(20, 11, 2019, 9);
    CHECK(agenda.getConsulta(20, 11, 2019, 9) == "disponivel");
}

TEST_CASE("02 - Marcando e Desmarcando Consultas - Excecoes") {
    Agenda agenda(7, 15);
    CHECK_NOTHROW(agenda.adicionarConsulta("Carlos", 20, 11, 2019, 7));
    CHECK_THROWS(agenda.adicionarConsulta("Pedro", 20, 11, 2019, 7));   // Marcando consulta em horario já marcado
    CHECK_THROWS(agenda.adicionarConsulta("Joao", 18, 11, 2019, 5));    // Marcando consulta com clinica fechada
    CHECK_THROWS(agenda.adicionarConsulta("Ana", 19, 11, 2019, 16));   // Marcando consulta fora do expediente
    CHECK_THROWS(agenda.adicionarConsulta("Carol", 23, 11, 2019, 12));   // Marcando consulta no fim de semana

    CHECK_NOTHROW(agenda.desmarcarConsulta(20, 11, 2019, 7));
    CHECK_THROWS(agenda.desmarcarConsulta(20, 11, 2019, 7)); // Desmarcando consulta já disponivel
    CHECK_THROWS(agenda.desmarcarConsulta(24, 11, 2019, 8));   // Desmarcando consulta de dia não criado
}
