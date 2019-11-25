#include "doctest.h"
#include "sistema.h"

TEST_CASE("01 - Testando Construtor") {
    CHECK_NOTHROW(new Sistema());
}

TEST_CASE("02 - Testando Cadastro") {
    Sistema sys;
    CHECK_NOTHROW(sys.cadastrar(new Paciente("45243830003", "Joao Pedro", "Antonio Carlos", "34258765", "18052019")));
    CHECK_NOTHROW(sys.cadastrar(new Pessoa("97279382053", "Angelica Antunes", "Joao Pinheiro", "34268715", "19062019")));
    CHECK_NOTHROW(sys.cadastrar(new Psicologo("03977335006", "Joao Pedro", "Antonio Carlos", "32659874", "22082018", "25749865", "8", "13")));
    
    Paciente* paciente = sys.encontrar(sys.getPacientes(), "45243830003");
    Pessoa* secretaria = sys.encontrar(sys.getSecretarias(), "97279382053");
    Psicologo* psicologo = sys.encontrar(sys.getPsicologos(), "03977335006");

    CHECK(paciente->getNome() == "Joao Pedro");
    CHECK(secretaria->getNome() == "Angelica Antunes");
    CHECK(psicologo->getNome() == "Joao Pedro");

    sys.deletar(sys.getPacientes());
    sys.deletar(sys.getSecretarias());
    sys.deletar(sys.getPsicologos());
}