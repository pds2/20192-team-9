#include "sistema.h"
#include "usuarioSecretaria.h"
//#include "usuarioPsicologo.h"

int main() {
	Sistema sys;
	while(1) {
	int login = sys.paginaInicial();
		if(login == 1) {
			usuarioSecretaria usuario(sys);
			usuario.paginaInicial();
		} else if(login == 2) {
			//usuarioPsicologo usuario;
			//usuario.paginaInicial();
		} else if (login == 5) {
			std::cout << "Obrigado por usar nosso programa!" << std::endl;
			std::cin.get();
			break;
		}
	}
}