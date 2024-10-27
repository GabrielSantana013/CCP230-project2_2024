# Projeto 2: Gerenciador de Livraria
Repositório criado para o projeto _(#2)_ "Gerrenciador de Livraria" da disciplina "Desenvolvimento de Algoritmos (CCP230)" - 2° Semestre de 2024


## Objetivo

O objetivo do projeto **Gerenciador de Livraria** é criar um sistema que permita o gerenciamento eficiente de livros, clientes e aluguéis. 
O sistema deve possibilitar o cadastro e armazenamento de informações detalhadas sobre livros e clientes, incluindo a manutenção de históricos de aluguéis. 

Além disso, deve oferecer funcionalidades para alugar livros, gerenciar o carrinho de compras de clientes e gerar relatórios de aluguéis. 
O projeto utiliza arquivos de texto e binários para persistência dos dados, enquanto structs, ponteiros e arrays são usados para manipular dinamicamente as informações.

## Como utilizar o programa

### Entrando como administrador
Para utilizar o programa por completo, é necessário a utilização do **menu de administrador**, para poder cadastrar novos livros e gerenciá-los.  
Para conseguir acessar o menu, é necessário utilizar o login específico de administrador:
   - **CPF**: 12312312312
   - **Senha**: admin

### 1. Cadastro de Livros:
   - Armazenar informações como título, autor, quantidade e status de disponibilidade.
   - Usar um arquivo de texto para guardar os livros.

### 2. Cadastro de Clientes:
   - Armazenar nome, CPF, e senha.
   - Um arquivo binário simples pode ser utilizado para armazenar os dados dos clientes.
   - Armazenar o histórico de aluguéis dos clientes.

### 3. Gerenciamento de Aluguéis:
   - Realizar o aluguel de um livro, atualizando a quantidade disponível e registrando a transação para o cliente.
   - Usar ponteiros para acessar e modificar informações de clientes e livros.
   - Implementar uma função “carrinho”, como nos e-commerces da internet, utilizando vetores dinamicamente alocados (`malloc`) e realocando conforme o cliente adicionar mais itens.
   - Permitir ao cliente adicionar e remover itens do carrinho.

### 4. Consulta de Livros/Clientes:
   - Buscar livros pelo ID, título, autor ou editora.
   - Somente o ADM e o cliente específico podem visualizar o histórico de compras do cliente.

### 5. Relatório de Vendas:
   - Geração de um relatório em formato de texto contendo as transações realizadas.
   - Gerar relatório geral ou por dia, mês ou usuário. 

## Estrutura do Projeto:
   - **Arquivos binários**: Armazenamento dos clientes.
   - **Arquivos de texto**: Armazenamento dos livros e relatórios de vendas.
   - **Structs**: Para definir as entidades do projeto (Livro, Cliente, Histórico e Carrinho).
   - **Ponteiros**: Para manipulação dinâmica dos registros.
   - **Arrays**: Para armazenar listas temporárias de livros e clientes.

### Funções
``` cpp
      int exibirMenuVisitante();
      int exibirMenuCliente();
      int exibirMenuAdm();
      int exibirMenuCliente(Usuario *ptrUsuario);
      void limpaBuffer();
      int verificaDigito(char *entrada);
      int cadastrarUsuario(Usuario *ptrUsuario);
      int cadastrarLivro();
      int catalogarLivros();
      int consultarHistoricoADM();
      int consultarLivro();
      int relatorioAlugueis();
      int logar(Usuario *ptrUsuario);
      int verificarCPF(Usuario *ptrUsuario);
      int verificarCadastro(Usuario *ptrUsuario);
      int verificarSenha(Usuario *ptrUsuario);
      int carrinhoDeCompras(Usuario *ptrUsuario);
      int devolverLivro (Usuario *ptrUsuario);
      int gerarHistorico(Carrinho *carrinho, Usuario *ptrUsuario);
      int consultarHistorico(Usuario *ptrUsuario);
      int exibirLivrosClientes(Usuario *ptrUsuario);
```

#### Funções de sistema
As funções `limpaBuffer(), exibirMenuVisitante(), exibirMenuCliente(), exibirMenuAdm() e verificaDigito()` são autoindicativas: elas, respectivamente, limpam o buffer de entrada do usuário, exibem o menu incial (visitante) na tela, exibem o menu de cliente quando logado, exibem o menu de administrador quando logado e verificam se o dado de entrada é um dígito numérico ou não.

#### Função `verificarSenha()`
A função verificarSenha é responsável por verificar se a senha e o CPF de um usuário correspondem a um registro existente no arquivo binário (clientes.bin).

Parâmetros

      Usuario *ptrUsuario: Ponteiro para uma estrutura do tipo Usuario, contendo os dados do usuário a ser verificado.

Funcionamento

      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo.
      Uma variável usuario do tipo Usuario é criada para armazenar os dados lidos do arquivo.
      
      Abrindo o Arquivo:
      O arquivo clientes.bin é aberto em modo leitura binária (rb).
      Se o arquivo não existir (ptrArquivo é NULL), um erro é reportado e a função retorna 0.
      
      Verificação de Usuário:
      Um loop lê os dados do arquivo até que não haja mais dados (fread retorna 1).
      Se a senha e o CPF do usuário lido corresponderem aos do ptrUsuario, o arquivo é fechado e a função retorna 1, indicando sucesso.
     
      Fechamento do Arquivo:
      O arquivo é fechado após a leitura.
      
      Retorno:
      Se nenhum registro correspondente for encontrado, a função retorna 0.
      
#### Função `verificarCadastro()`
A função verificarCadastro é responsável por verificar se um CPF já está cadastrado no arquivo binário (clientes.bin).

Parâmetros
      
      Usuario *ptrUsuario: Ponteiro para uma estrutura do tipo Usuario, contendo o CPF a ser verificado.
      
Funcionamento

      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo.
      Uma variável usuario do tipo Usuario é criada para armazenar os dados lidos do arquivo.
     
      Abrindo o Arquivo:
      O arquivo clientes.bin é aberto em modo leitura binária (rb).
      Se o arquivo não existir (ptrArquivo é NULL), um erro é reportado e a função retorna 0.
      
      Verificação de Cadastro:
      Um loop lê os dados do arquivo até que não haja mais dados (fread retorna 1).
      Se o CPF do usuário lido corresponder ao CPF do ptrUsuario, o arquivo é fechado e a função retorna 1, indicando que o CPF já está cadastrado.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a leitura.
      
      Retorno:
      Se nenhum registro correspondente for encontrado, a função retorna 0.
      
#### Função `verificarCPF()`
A função verificarCPF é responsável por validar o formato do CPF informado pelo usuário.

Parâmetros
      
      Usuario *ptrUsuario: Ponteiro para uma estrutura do tipo Usuario, onde o CPF validado será armazenado.

Funcionamento
      
      Declaração de Variáveis:
      Um array CPF é declarado para armazenar a entrada do usuário.
      Variáveis tamanhoCPF e numerico são inicializadas para controle do loop.
      
      Entrada do Usuário:
      Um loop solicita ao usuário que digite seu CPF até que um CPF válido seja fornecido.
      O CPF é verificado para garantir que tenha 11 ou 12 dígitos e contenha apenas números.
      
      Cópia do CPF:
      O CPF lido é copiado para ptrUsuario->CPF.
      
      Retorno:
      A função retorna 0, indicando que a verificação foi realizada com sucesso.

#### Função `cadastrarUsuario()`
A função cadastrarUsuario é responsável por cadastrar um novo usuário no arquivo binário (clientes.bin).

Parâmetros
      
      Usuario *ptrUsuario: Ponteiro para uma estrutura do tipo Usuario, que contém os dados do novo usuário a ser cadastrado.
      
Funcionamento
      
      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo.
      A variável retorno é usada para armazenar o resultado das verificações.
      
      Verificação de CPF:
      O CPF do usuário é verificado chamando verificarCPF(ptrUsuario).
      
      Verificação de Cadastro:
      A função verificarCadastro(ptrUsuario) é chamada para checar se o CPF já está cadastrado.
      Se o CPF já estiver cadastrado, uma mensagem de erro é exibida e a função retorna 1.
      
      Entrada de Dados:
      O usuário é solicitado a inserir seu nome e senha, que são armazenados em ptrUsuario.
      
      Gravação no Arquivo:
      O arquivo clientes.bin é aberto em modo append binário (ab+) e os dados do novo usuário são escritos no arquivo.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a gravação.
      
      Retorno:
      A função retorna 0, indicando que o cadastro foi realizado com sucesso.

#### Função `cadastrarLivro()`
A função cadastrarLivro é responsável por cadastrar um novo livro em um arquivo de texto (catalogo.txt).

Funcionamento

      Inicialização:
      Um ponteiro ptrArquivoLivro é declarado para manipular o arquivo.
      Estruturas novo_livro e livro_anterior do tipo Livro são declaradas para armazenar os dados do novo livro e do livro anterior, respectivamente.
     
      Abrindo o Arquivo:
      O arquivo catalogo.txt é aberto em modo append (a+).
      Se o arquivo não puder ser aberto, ele é criado em modo write (w). Se isso falhar, um erro é reportado e o programa é encerrado.
      
      Validação dos Dados do Livro:
      Um loop é utilizado para garantir que o título do livro seja válido. O usuário é solicitado a digitar o título, que não pode ter mais de 50 caracteres. Se o título for muito longo, uma mensagem de erro é exibida, e o usuário é solicitado a tentar novamente.
      Os mesmos passos são repetidos para o autor e a editora do livro, garantindo que cada um tenha no máximo 50 caracteres.
      Para o ano de publicação, o usuário é solicitado a digitar um valor. Se a entrada não for numérica, um erro é exibido e o usuário deve tentar novamente.
      A quantidade em estoque é tratada de maneira semelhante, garantindo que o valor inserido seja numérico.
      
      Determinação do ID do Livro:
      O tamanho do arquivo é obtido usando ftell.
      Se o arquivo estiver vazio, o ID do novo livro (livroId) é definido como 1.
      Se já houver livros cadastrados, o último livro registrado é lido para obter seu ID, que é incrementado para o novo livro.
      
      Gravação no Arquivo:
      Os dados do novo livro são gravados no arquivo usando fwrite.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a gravação.
      
      Retorno:
      A função retorna 0, indicando que o cadastro foi realizado com sucesso.

#### Função `catalogarLivros()`
A função catalogarLivros é responsável por exibir todos os livros cadastrados em um arquivo de texto (catalogo.txt) em um formato tabular.

Funcionamento

      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo.
      Uma variável livro_atual do tipo Livro é criada para armazenar os dados de cada livro lido.
      A variável bytes é inicializada com o tamanho da estrutura Livro.
      
      Abrindo o Arquivo:
      O arquivo catalogo.txt é aberto em modo leitura (r).
      Se o arquivo não existir (ptrArquivo é NULL), uma mensagem é exibida informando que ainda não há catálogo e a função retorna 1.
      
      Imprimindo o Cabeçalho da Tabela:
      Um cabeçalho é impresso na tela, com os títulos das colunas: ID, Título, Autor, Editora, Ano, Quantidade e Status.
      Uma linha de separação é impressa para melhorar a legibilidade.
      
      Leitura e Impressão dos Livros:
      Um loop lê os dados do arquivo, um livro por vez, usando fread.
      Para cada livro lido, os caracteres de nova linha (\n) são removidos das strings titulo, autor e editora utilizando strcspn.
      Dependendo da quantidade em estoque (qttEstoque), o livro é impresso como "Disponível" se a quantidade for maior que 0, ou "Indisponível" se for menor ou igual a 0.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a leitura e impressão dos dados.
      
      Retorno:
      A função retorna 0, indicando que a operação foi concluída com sucesso.

#### Função `consultarHistoricoADM()`
A função consultarHistoricoADM é responsável por consultar e exibir o histórico de transações de um usuário, baseado no CPF fornecido.

Funcionamento

      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo.
      Uma variável historico do tipo Historico é criada para armazenar os dados lidos do arquivo.
      A variável head é inicializada em 0 para controlar a impressão do cabeçalho da tabela.
      Um array cpf é declarado para armazenar o CPF informado pelo usuário.
      
      Entrada do CPF:
      O usuário é solicitado a digitar o CPF. A entrada é lida com um limite de 11 caracteres para evitar overflow.
      A função limpaBuffer() é chamada para limpar o buffer de entrada, e o último caractere do array cpf é definido como \0 para garantir que a string esteja corretamente terminada.
      
      Verificação do Administrador:
      Se o CPF informado for o específico para o administrador ("12312312312"), uma mensagem é exibida informando que o administrador não possui histórico, e a função retorna 1.
     
      Abrindo o Arquivo:
      O arquivo historico.bin é aberto em modo leitura binária (rb+).
      Se o arquivo não puder ser aberto (ptrArquivo é NULL), uma mensagem é exibida informando que não há histórico disponível, e a função retorna 1.
      
      Leitura e Impressão do Histórico:
      Um loop lê os dados do arquivo, um registro de histórico por vez, usando fread.
      Se head for 0, o cabeçalho da tabela é impresso, contendo as colunas: Data, Título, Autor, Editora e Tipo de Transação.
      Para cada registro lido, se o CPF do histórico corresponder ao CPF informado, os detalhes da transação são impressos em formato tabular.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a leitura e impressão dos dados.
      
      Retorno:
      A função retorna 0, indicando que a operação foi concluída com sucesso.

#### Função `consultarLivro()`
A função consultarLivro é responsável por consultar e exibir informações sobre livros cadastrados, com base em diferentes critérios de pesquisa.

Funcionamento

      Inicialização:
      Um ponteiro ptrArquivoLivro é declarado para manipular o arquivo.
      O arquivo catalogo.txt é aberto em modo leitura (r).
      Se o arquivo não existir (ptrArquivoLivro é NULL), uma mensagem é exibida informando que não há livros registrados, e a função retorna 1.
      
      Opções de Consulta:
      O usuário é apresentado com um menu de opções para consultar os livros por ID, nome, autor ou editora.
      A opção escolhida é lida e armazenada na variável opcao.
      Dependendo da opção selecionada, o usuário é solicitado a inserir o critério de busca correspondente (ID, nome, autor ou editora).
      
      Cálculo do Número de Registros:
      O tamanho do arquivo é obtido usando ftell e dividido pelo tamanho da estrutura Livro para determinar o número total de registros (numRegistros).
      
      Leitura e Impressão dos Livros:
      Um loop lê os dados do arquivo, um livro por vez, usando fread.
      Para cada livro lido, a variável match é inicializada como 0. Dependendo da opção selecionada, a correspondência é verificada:
         - Por ID: Verifica se o livroId corresponde ao ID informado e se o ID está dentro dos limites válidos.
         - Por Nome: Compara o título do livro com o nome informado.
         - Por Autor: Compara o autor do livro com o autor informado.
         - Por Editora: Compara a editora do livro com a editora informada.
      Se uma correspondência for encontrada, o cabeçalho da tabela é impresso (apenas na primeira correspondência) e os detalhes do livro são exibidos, incluindo o status do livro (Disponível, Alugado ou Vendido).
      
      Verificação de Livros Encontrados:
      Se nenhuma correspondência for encontrada após a leitura de todos os livros, uma mensagem informando que nenhum livro foi encontrado é exibida.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a conclusão da consulta.
      
      Retorno:
      A função retorna 0, indicando que a operação foi concluída com sucesso.

#### Função `relatorioAlugueis()`
A função relatorioAlugueis é responsável por gerar relatórios de registros de aluguel a partir de um arquivo binário que armazena o histórico de transações.

Funcionamento

      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo.
      O arquivo historico.bin é aberto em modo leitura binária (rb).
      Se o arquivo não existir (ptrArquivo é NULL), uma mensagem é exibida informando que não há registros de aluguel, e a função retorna 1.
      Opções de Relatório:
      
      O usuário é apresentado com um menu de opções para gerar diferentes tipos de relatórios:
         - Relatório geral de aluguéis.
         - Relatório de aluguéis por dia.
         - Relatório de aluguéis por mês.
         - Relatório de aluguéis por usuário.
      A opção escolhida é lida e armazenada na variável opcao.
      
      Verificação da Opção:
      Se a opção for inválida (fora do intervalo de 1 a 4), uma mensagem de erro é exibida, e a função retorna 1.
      Geração do Relatório:
      
      Dependendo da opção escolhida, o relatório é gerado:
      
      Caso 1: Relatório Geral
      Imprime o cabeçalho da tabela e lê cada registro do arquivo.
      Cada registro é exibido com informações sobre CPF, nome, data, título, autor, editora e tipo de transação.
      
      Caso 2: Relatório por Dia
      O usuário é solicitado a inserir uma data no formato "dd/mm/aa".
      O cabeçalho da tabela é impresso e o programa lê cada registro.
      Apenas os registros que correspondem à data inserida são exibidos.
      
      Caso 3: Relatório por Mês
      O usuário é solicitado a inserir um mês no formato "mm/aa".
      O cabeçalho da tabela é impresso e o programa lê cada registro.
      Apenas os registros que correspondem ao mês inserido são exibidos.
      
      Caso 4: Relatório por Usuário
      O usuário é solicitado a inserir o CPF do usuário.
      O cabeçalho da tabela é impresso e o programa lê cada registro.
      Apenas os registros que correspondem ao CPF inserido são exibidos.
      
      Fechamento do Arquivo:
      O arquivo é fechado após a geração do relatório.
      
      Retorno:
      A função retorna 0, indicando que a operação foi concluída com sucesso.

#### Função `logar()`
A função logar é responsável por autenticar um usuário no sistema, verificando suas credenciais (CPF e senha) em um arquivo binário.

Parâmetros
      
      Usuario *ptrUsuario: Um ponteiro para uma estrutura do tipo Usuario, que contém os dados do usuário tentando se autenticar.
      
Funcionamento
      
      Inicialização:
      Um ponteiro ptrArquivo é declarado para manipular o arquivo de usuários.
      Uma variável usuario do tipo Usuario é criada para armazenar os dados lidos do arquivo.
      
      Abertura do Arquivo:
      O arquivo clientes.bin é aberto em modo leitura binária (rb).
      Se o arquivo não existir (ptrArquivo é NULL), uma mensagem é exibida informando que nenhum usuário está cadastrado, e a função retorna 1.
     
      Entrada de Dados:
      O usuário é solicitado a inserir seu CPF através da função verificarCPF, que garante que o CPF seja capturado corretamente.
      Em seguida, o usuário é solicitado a inserir sua senha.
      
      Verificação das Credenciais:
      Um loop lê os dados de cada usuário do arquivo até que não haja mais registros (fread retorna 1).
     
      Para cada registro lido:
      Se o CPF e a senha do usuário correspondem aos dados no arquivo, e se o nome do usuário for "admin", a função imprime uma mensagem de sucesso e retorna 3, indicando que o usuário é um administrador.
      Se o CPF e a senha correspondem a um usuário regular, a função:
         Imprime uma mensagem de sucesso.
      Copia o nome do usuário para o ponteiro ptrUsuario e atribui a quantidade de livros alugados.
      Retorna 2, indicando que um usuário regular fez login com sucesso.
      
      Credenciais Incorretas:
      Se nenhum registro correspondente for encontrado, uma mensagem de erro é exibida, informando que o usuário ou senha estão incorretos.
      
      Fechamento do Arquivo:
      O arquivo é fechado antes de retornar da função, garantindo que todos os recursos sejam liberados.
      
      Retorno:
      A função retorna 0, indicando que a tentativa de login falhou.

#### Função `carrinhoDeCompras()`
1. `inicializarCarrinho()`  
Objetivo: Alocar memória para o carrinho de compras e inicializar suas propriedades.  
Parâmetros: Um ponteiro para um ponteiro de Carrinho.

Funcionamento:  
Aloca memória para um novo Carrinho.
Define a capacidade inicial como 10 e o tamanho como 0.
Aloca memória para um array de Livro com a capacidade definida.
Em caso de falha na alocação, imprime uma mensagem de erro e encerra o programa.

2. `removerLivro()`  
Objetivo: Remover um livro do carrinho com base no seu ID.  
Parâmetros: Um ponteiro para Carrinho e o ID do livro a ser removido.

Funcionamento:  
Percorre os livros no carrinho, procurando pelo ID especificado.
Se encontrado, desloca os livros restantes para a esquerda e decrementa o tamanho do carrinho.
Se não encontrado, imprime uma mensagem de aviso.

3. `exibirCarrinho()`  
Objetivo: Exibir todos os livros atualmente no carrinho.  
Parâmetros: Um ponteiro para Carrinho.

Funcionamento:  
Itera sobre os livros no carrinho e imprime suas informações, incluindo ID, título, autor, editora, ano e status.
Exibe a quantidade total de livros no carrinho.

4. `apagaCarrinho()`  
Objetivo: Liberar a memória alocada para o carrinho.  
Parâmetros: Um ponteiro para Carrinho.

Funcionamento:  
Libera a memória dos livros do carrinho.
Reseta as propriedades do carrinho para evitar acessos indevidos no futuro.

5. `adicionarLivro()`  
Objetivo: Adicionar um livro ao carrinho.  
Parâmetros: Um ponteiro para Carrinho e um objeto Livro.

Funcionamento:  
Verifica se o livro já está no carrinho. Se sim, exibe uma mensagem informando que o livro já foi adicionado.
Se o carrinho estiver cheio, expande a capacidade em 5.
Adiciona o livro ao carrinho e incrementa o tamanho.

6. `buscaLivro()`  
Objetivo: Procurar um livro no arquivo de catálogo pelo seu ID.  
Parâmetros: O ID do livro a ser buscado.

Funcionamento:
Abre o arquivo catalogo.txt e lê os livros.
Se encontrar o livro com o ID correspondente, o retorna.
Se não encontrar, imprime uma mensagem de aviso e retorna um livro com livroId igual a -1.

7. `carrinhoDeCompras()`  
Objetivo: Gerenciar o carrinho de compras do usuário.  
Parâmetros: Um ponteiro para Usuario.

Funcionamento:  
Inicializa o carrinho chamando inicializarCarrinho.
Exibe um menu com opções para adicionar, remover, exibir livros e finalizar a compra.
Para adicionar um livro, busca pelo ID e verifica se o livro está disponível antes de adicioná-lo ao carrinho.
Ao finalizar a compra, verifica a senha do usuário e, se correta, gera um histórico e libera a memória do carrinho.

#### Função `devolverLivro()`
A função devolverLivro gerencia o processo de devolução de livros alugados por um usuário, atualizando o histórico de empréstimos e o estoque do catálogo de livros.

Parâmetros

      Usuario *ptrUsuario: Ponteiro para a estrutura do usuário, que contém informações como o CPF e dados pessoais.

Funcionamento
      
      Abertura do Arquivo de Livros Alugados:
      A função tenta abrir o arquivo alugados.bin em modo leitura e escrita (rb+). Se o arquivo não puder ser aberto, uma mensagem de erro é exibida e a função retorna.
      
      Verificação de Registros de Aluguel:
      A função lê o arquivo em busca de registros de livros alugados que correspondam ao CPF do usuário. Se nenhum registro for encontrado, informa ao usuário e encerra.
      
      Exibição de Livros Alugados:
      A função imprime uma tabela com os livros que o usuário alugou, incluindo as colunas de data, ID, título, autor e editora.
      
      Solicitação do ID do Livro:
      O usuário é solicitado a inserir o ID do livro que deseja devolver.
      
      Processamento da Devolução:
      A função busca novamente o livro correspondente ao ID fornecido pelo usuário. Se encontrado, atualiza o registro no arquivo, marcando-o como devolvido (substituindo o CPF por *).
      
      Atualização do Estoque do Livro:
      Após a devolução, a função abre o arquivo catalogo.txt e aumenta a quantidade em estoque do livro devolvido.
      
      Atualização do Histórico de Devolução:
      A função registra a devolução no arquivo historico.bin, salvando o CPF do usuário e o tipo de transação como "Devolução".
      
      Mensagens de Sucesso ou Erro:
      O usuário é informado se a devolução foi bem-sucedida ou se o livro não foi encontrado.
      
      Retorno:
      A função retorna 0 em caso de sucesso ou 1 se houver erros (como arquivo não encontrado ou livro não alugado).

#### Função `gerarHistorico()`
A função gerarHistorico registra os detalhes dos livros alugados por um usuário em dois arquivos: historico.bin (para histórico de transações) e alugados.bin (para registrar livros atualmente alugados). Além disso, atualiza a quantidade de livros no estoque.

Parâmetros

      Carrinho *carrinho: Ponteiro para a estrutura do carrinho, contendo os livros que o usuário deseja alugar.
      Usuario *usuario: Ponteiro para a estrutura do usuário, que contém informações como o CPF e dados pessoais.

Funcionamento
      
      Abertura dos Arquivos:
      A função tenta abrir os arquivos historico.bin e alugados.bin em modo append e leitura/escrita (ab+). Se falhar em abrir qualquer um dos arquivos, uma mensagem de erro é exibida e a função retorna.
      
      Obtenção da Data e Hora:
      A função captura a data e hora atuais e formata como uma string no padrão dd/mm/aa hh:mm:ss.
      
      Preenchimento do Registro de Histórico:
      Para cada livro no carrinho, a função preenche a estrutura Historico com informações do usuário e detalhes do livro, como ID, título, autor, editora e tipo de transação ("Alugado").
      
      Gravação no Histórico:
      Os registros preenchidos são gravados nos arquivos historico.bin e alugados.bin. A contagem de livros alugados do usuário é incrementada.
      
      Atualização do Estoque:
      A função abre o arquivo catalogo.txt para atualizar a quantidade de estoque de cada livro. Para cada livro no carrinho:
         Se o livro estiver disponível, a quantidade em estoque é decrementada.
         Se o livro não estiver disponível, o status é alterado para "INDISPONÍVEL" e uma mensagem é exibida.
      
      Mensagens de Indisponibilidade:
      Se um livro estiver indisponível, a função informa ao usuário sobre isso.
      
      Retorno:
      A função retorna 0 em caso de sucesso ou -1 se houver falhas ao abrir o arquivo de catálogo

#### Função `consultarHistorico()`
A função consultarHistorico permite que um usuário visualize seu histórico de transações de aluguel de livros, acessando os dados armazenados no arquivo historico.bin.

Parâmetros

      Usuario *ptrUsuario: Ponteiro para a estrutura do usuário, que contém informações como CPF e nome.

Funcionamento
      
      Abertura do Arquivo:
      A função tenta abrir o arquivo historico.bin em modo leitura/binary (rb+). Se o arquivo não puder ser aberto (por exemplo, se não houver histórico), uma mensagem é exibida e a função retorna.
      
      Exibição do Cabeçalho:
      Se o arquivo for aberto com sucesso, a função exibe um cabeçalho com o CPF e o nome do usuário.
      
      Leitura e Exibição dos Registros:
      A função lê cada registro da estrutura Historico do arquivo.
      
      Para cada registro que corresponde ao CPF do usuário:
      Os detalhes da transação são exibidos, incluindo a data, título do livro, autor, editora e tipo de transação.
      
      Formatação da Saída:
      Os dados são apresentados em uma tabela formatada, facilitando a leitura.
      
      Retorno:
      A função retorna 0 em caso de sucesso ou 1 se não houver histórico a ser consultado.

#### Função `exibirLivrosClientes()`
A função exibirLivrosClientes permite que um usuário visualize a lista de livros disponíveis no catálogo, desde que forneça a senha correta.

Parâmetros

      Usuario *ptrUsuario: Ponteiro para a estrutura do usuário, que contém informações como CPF, nome e senha.

Funcionamento

      Solicitação de Senha:      
      A função solicita que o usuário digite sua senha. A senha é lida e armazenada na estrutura ptrUsuario.
      
      Verificação da Senha:
      A função chama verificarSenha para validar a senha fornecida. Se a senha estiver correta, prossegue para o próximo passo; caso contrário, uma mensagem de erro é exibida e a função termina.
      
      Abertura do Arquivo de Catálogo:
      A função tenta abrir o arquivo catalogo.txt em modo leitura. Se o arquivo não puder ser aberto, uma mensagem é exibida indicando que não há livros registrados.
      
      Exibição do Cabeçalho:
      Se o arquivo for aberto com sucesso, a função imprime um cabeçalho formatado para a tabela que exibirá os livros.
      
      Leitura e Exibição dos Livros: 
      A função lê cada livro do arquivo e exibe os detalhes na tabela.
      O título, autor, editora, ano, quantidade em estoque e status (Disponível ou Indisponível) são exibidos.
      As strings são tratadas para remover caracteres de nova linha.
      
      Fechamento do Arquivo:
      Após exibir todos os livros, o arquivo é fechado.
      
      Retorno:
      A função retorna 0 ao final, independentemente do resultado da operação (exceto em caso de erro ao abrir o arquivo).

## Compilação e execução
Para executar o programa, é necessário baixar os arquivos fonte e compilar o arquivo executável.  
Para isso, clone o repositório em um diretório local (utilize a forma que desejar, o exemplo abaixo clona a partir do link HTTPS).

```
git clone https://github.com/GabrielSantana013/CCP230-project2_2024.git
```

Em seguida, dirija-se a pasta principal do repositório e utilize o Makefile para compilação.

```
cd .\CCP230-project2_2024\
make
```

Com isso, o arquivo "livraria.exe" será criado na pasta principal do projeto. Para utilizá-lo, apenas abra o executável e faça suas operações!  
> Obs.: O programa funciona completamente através do terminal do seu sistema operacional.

## Autores
Esse é o projeto #2 da disciplina CCP230 (Desenvolvimento de Algoritmos) do curso de Ciência da Computação do Centro Universitário FEI, criado pelos alunos:
- [@Pedro Schneider](https://github.com/PedroSchneider1) (RA 24.124.072-0)
- [@Gabriel Santana Dias](https://github.com/GabrielSantana013) (RA 24.124.071-2)

