#include "doctest.h"
#include "paciente.h"

TEST_CASE("01 - Testando Construtor, setters e getters") {
    CHECK_NOTHROW(new Paciente("10486571670", "Vitor Damasceno Santos", "Manoel Gomes", "31985468745", "15102010"));

    std::vector<std::string> dados = {"10486571670", "Vitor Damasceno Santos", "Antonio Carlos", "31985468745", "15102010"};
    CHECK_NOTHROW(new Paciente(dados)); // Passando vetor para construtor

    Paciente p("10486571670", "Vitor Damasceno Santos", "Manoel Gomes", "31985468745", "15102010");
    p.setPsicologoResponsavel("Pedro");
    p.setQueixa("Sentindo muita ansiedade");
    CHECK(p.getPsicologoResponsavel() == "Pedro");
    CHECK(p.getQueixa() == "Sentindo muita ansiedade");

}