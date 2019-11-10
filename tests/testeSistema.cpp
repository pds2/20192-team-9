#include "doctest.h"
#include "sistema.h"
#include "secretaria.h"

TEST_CASE("01 - Testando") {
    Sistema sys;
    CHECK_NOTHROW(sys.cadastrar<Secretaria>());
}