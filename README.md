# CCP230-project2_2024

## Projeto: Gerenciador de Livraria

### Objetivos: 

O objetivo do projeto **Gerenciador de Livraria** é criar um sistema que permita o gerenciamento eficiente de livros, clientes e vendas. 
O sistema deve possibilitar o cadastro e armazenamento de informações detalhadas sobre livros e clientes, incluindo a manutenção de históricos de compras. 

Além disso, deve oferecer funcionalidades para realizar vendas, gerenciar o carrinho de compras de clientes e gerar relatórios de vendas. 
O projeto utiliza arquivos de texto e binários para persistência dos dados, enquanto structs, ponteiros e arrays são usados para manipular dinamicamente as informações.

## Funcionalidades:

### 1. Cadastro de Livros:
   - Armazenar informações como título, autor, sinopse, preço e quantidade.
   - Usar um arquivo de texto para guardar os livros.

### 2. Cadastro de Clientes:
   - Armazenar nome, CPF, e senha.
   - Um arquivo binário simples pode ser utilizado para armazenar os dados dos clientes.
   - Armazenar o histórico de compras dos clientes.

### 3. Gerenciamento de Vendas:
   - Realizar a venda de um livro, atualizando a quantidade disponível e registrando a compra para o cliente.
   - Usar ponteiros para acessar e modificar informações de clientes e livros.
   - Implementar uma função “carrinho” como nos e-commerces da internet utilizando vetores dinamicamente alocados (`malloc`) e realocando conforme o cliente adicionar mais itens.
   - Permitir ao cliente adicionar e remover itens do carrinho.

### 4. Consulta de Livros/Clientes:
   - Buscar livros pelo título, autor, ou nome.
   - Somente o ADM e o cliente específico podem visualizar o histórico de compras do cliente.

### 5. Relatório de Vendas:
   - Geração de um relatório em formato de texto contendo as vendas realizadas durante um dia X.

## Estrutura do Projeto:
   - **Arquivos binários**: Armazenamento dos clientes.
   - **Arquivos de texto**: Armazenamento dos livros e relatórios de vendas.
   - **Structs**: Para definir as entidades do projeto, como Livro e Cliente.
   - **Ponteiros**: Para manipulação dinâmica dos registros.
   - **Arrays**: Para armazenar listas temporárias de livros e clientes.
