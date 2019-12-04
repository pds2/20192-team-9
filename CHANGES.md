# Alterações
Corrigimos uma exceção que não era tratada quando tentávamos marcar uma consulta fora do horário do expediente do psicologo porém
enquanto a clinica ainda estava aberta.
O erro era simplesmente trocar "throw std::out_of_range" para "throw std::invalid_argument" haja vista estarmos tratando de um invalid_argument no catch.s