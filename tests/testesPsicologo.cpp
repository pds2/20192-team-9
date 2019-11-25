#include "doctest.h"
#include "psicologo.h"

TEST_CASE("01 - Testando construtor e getters") {
    CHECK_THROWS(new Psicologo("45243830003", "Vitor Damasceno Santos", "Rua Manoel Gomes", "31985467895", "15102010", "12AaBb", "8", "13"));
    CHECK_NOTHROW(new Psicologo("45243830003", "Vitor Damasceno Santos", "Rua Manoel Gomes", "31985467895", "15102010", "145987563", "8", "13"));

    std::vector<std::string> dados = {"45243830003", "Vitor Damasceno Santos", "Antonio Carlos", "31985468745", "15102010","145987563", "8", "13"};
    CHECK_NOTHROW(new Psicologo(dados)); // Passando vetor para construtor

    Psicologo p("45243830003", "Vitor Damasceno Santos", "Rua Manoel Gomes", "31985467895", "15102010", "145987563", "8", "13");
    CHECK(p.getCRP() == "145987563");
}

TEST_CASE("02 - Testando operacoes da agenda") {
    Psicologo p("45243830003", "Vitor Damasceno Santos", "Rua Manoel Gomes", "31985467895", "15102010", "145987563", "8", "13");
    CHECK_NOTHROW(p.adicionarConsulta("Carlos", "27", "11", "2019", "8"));
    CHECK_NOTHROW(p.getConsulta("27", "11", "2019", "8"));
    CHECK_NOTHROW(p.desmarcarConsulta("27", "11", "2019", "8"));

    CHECK_THROWS(p.adicionarConsulta("Joao", "12AaBb", "12AaBb","12AaBb","12AaBb"));
}