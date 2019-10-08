# UserStories

## Administrador

#### *“Como administrador do sistema eu gostaria de visualizar todos usuários cadastrados para poder adicionar, editar ou remover funcionários.”*
- Critérios de aceitação.
	- Exibir uma página que possibilita a visualização dos usuários por nome, tipo e ID
	-   Adicionar secretárias com preenchimento de dados pessoais e criação de login    
	- Adicionar psicólogos preenchendo informações pessoais, definindo carga horária de trabalho, agenda e criação de login
	- Remover login de Psicólogos/Secretárias do sistema

## Secretária

#### *“Como secretária da clínica gostaria de cadastrar, editar e visualizar dados dos clientes para contatá-lo e atualizar suas informações sempre que necessário“*
-   Critérios de aceitação
	-   Exibir tela com dados pessoais a serem cadastrados
    -   Exibir opção de editar cadastros dos clientes.
    -   Buscar paciente por Nome ou ID (sem acesso ao prontuário)
    -   Visualizar todos os pacientes
    - 
#### *"Como secretária da clínica eu gostaria de visualizar a agenda dos psicólogos para poder marcar uma consulta ou verificar uma marcação"*

   - Critérios de aceitação
	    -   Visualização de um período de 7 dias a partir do dia atual
	    -   Visualizar dia específico
	    -   Visualizar mês atual ou posterior;
	    -   Mostrar o nome de todos os psicólogos
	    -   Mostrar horários vagos dos psicólogos
	    -   Mostrar horário das consultas dos psicólogos com nome do paciente
#### *"Como secretária da clínica eu gostaria de visualizar e dar baixa em pagamentos realizados para poder verificar o fluxo de caixa da organização."*

-   Critérios de aceitação
    -   Visualização do pagamento mensal de cada cliente da clínica.
    -   Dar baixa no pagamento efetuado exigindo ID, mês e quantia
    -   Visualização do fechamento mensal e anual do caixa..
## Psicólogo
#### *“Como psicólogo da clínica eu gostaria de visualizar minha agenda para saber quais pacientes atenderei e em quais dias.”*
-   Critérios de aceitação
	 -   Permitir a visualização da agenda dos próximos 7 dias
    -   Permitir a visualização da agenda do mês atual ou posterior

#### *“Como psicólogo da clínica eu gostaria de buscar no sistema o ID do paciente e registrar um prontuário.”*
-   Critérios de aceitação
	-  Buscar paciente por nome ou matrícula
    - Permitir campo de texto para relatar informações do cliente
# CRC
### Classe Administrador
| Responsabilidades | Colaborações  |
|--|--|
|login| Secretaria |
|senha|Psicologo|

### Classe Pessoa
|Responsabilidades| Colaborações |
|--|--|
|ID  | Paciente |
|nome|Psicologo|
|endereco|Secretaria|
|telefone|
|dataInicio|
|dataFim|
|alta|
|Pessoa( )|
|~Pessoa( )|
|setEndereco( )|
|setTelefone( )|
|darAlta( )|
|retirarAlta( )|

### Classe Paciente : Pessoa
|Responsabilidades  | Colaborações |
|--|--|
|psicologoResponsavel  | Psicologo |
|queixa|Financeiro|
|pagamentos|
|prontuario|
|Paciente( )|
|~Paciente( )|
|setQueixa( )|
|setProntuario( )|
|imprimirQueixa( )|
|imprimirProntuário( )|
|imprimirPacientes( )|

### Classe Psicologo : Pessoa
|Responsabilidades| Colaborações |
|--|--|
|numeroCRP  | Paciente |
|Psicologo( )| Agenda|
|~Psicologo( )|
|imprimirPacientes( )|

### Classe Agenda
|Responsabilidades| Colaborações |
|--|--|
|dia|Psicologo|
|seteDias|Paciente|
|mesAtual|
|mesPosterior|
|marcarConsulta( )|
|imprimirAgenda( )|

### Classe Financeiro
|Responsabilidades| Colaborações |
|--|--|
|arrecadacaoMensal  | Agenda |
|arrecadacaoAnual|Paciente|
|pagar( )|Secretaria|
|imprimirArrecadacao( )|







