#include "doctest.h"
#include "pessoa.h"

TEST_CASE("01 - Testando Construtor e getters") {
    CHECK_THROWS(new Pessoa("12AaBb", "Vitor Damasceno Santos", "Manoel Gomes", "31985468745", "15102010")); // Digitando letra no CPF
    CHECK_THROWS(new Pessoa("45243830003", "12AaBb", "Manoel Gomes", "31985468745", "15102010")); // Digitando numero no Nome
    CHECK_THROWS(new Pessoa("45243830003", "Vitor Damasceno Santos", "12AaBb", "31985468745", "15102010")); // Digitando numero na rua
    CHECK_THROWS(new Pessoa("45243830003", "Vitor Damasceno Santos", "Manoel Gomes", "12AaBb", "15102010")); // Digitando letra no telefone
    CHECK_THROWS(new Pessoa("45243830003", "Vitor Damasceno Santos", "Manoel Gomes", "31985468745", "12AaBb")); // Digitando letra na data
    CHECK_NOTHROW(new Pessoa("45243830003", "Vitor Damasceno Santos", "Manoel Gomes", "31985468745", "15102010"));

    std::vector<std::string> dados = {"45243830003", "Vitor Damasceno Santos", "Antonio Carlos", "31985468745", "15102010"};
    CHECK_NOTHROW(new Pessoa(dados));   // Passando vetor para construtor 

    Pessoa p("45243830003", "Vitor Damasceno Santos", "Manoel Gomes", "31985468745", "15102010");
    CHECK(p.getCPF() == "45243830003");
    CHECK(p.getNome() == "Vitor Damasceno Santos");
    CHECK(p.getRua() == "Manoel Gomes");
    CHECK(p.getTelefone() == "31985468745");
    CHECK(p.getDataInicio() == "15102010");
}