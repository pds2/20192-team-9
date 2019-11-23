#include "doctest.h"
#include "sistema.h"

TEST_CASE("Testando Construtor") {
    CHECK_NOTHROW(new Sistema());
    Sistema sys;
    CHECK(sys.validar_CPF("10486571670") == true);
    //CHECK_NOTHROW(sys.encontrarPessoa(sys.getPsicologos(), "456"));
}