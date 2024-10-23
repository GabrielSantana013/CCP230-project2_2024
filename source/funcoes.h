#ifndef FUNCOES_H
#define FUNCOES_H

#define DISPONIVEL 0;
#define ALUGADO 1;
#define VENDIDO 2;

typedef struct{

    char nome[50];
    char CPF[12];
    char senha[50];
    int qttLivrosAlugados;
    int qttLivrosComprados;


}Usuario;

typedef struct{

    int livroId;
    char titulo[50];
    char autor[50];
    char editora[50];
    int ano;
    int qttEstoque;
    float preco;
    int status; //0 - disponivel, 1 - alugado, 2 - vendido

}Livro;

typedef struct{

    Livro *livros;
    size_t capacidade; //quantos livros cabem no carrinho
    size_t tamanho; //quantos livros já tem no carrinho

}Carrinho;

int exibirMenuVisitante();
int exibirMenuCliente();
int exibirMenuAdm();
int exibirMenuCliente(Usuario *ptrUsuario);
void limpaBuffer();
int verificaDigito(char *entrada);
int cadastrarUsuario(Usuario *ptrUsuario);
int cadastrarLivro();
int catalogarLivros(Usuario *ptrUsuario);
int logar(Usuario *ptrUsuario);
int verificarCPF(Usuario *ptrUsuario);
int verificarCadastro(Usuario *ptrUsuario);
int carrinhoDeCompras(Usuario *ptrUsuario);


#endif