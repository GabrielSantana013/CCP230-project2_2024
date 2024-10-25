#ifndef FUNCOES_H
#define FUNCOES_H

#define DISPONIVEL 0;
#define INDISPONIVEL 1;

typedef struct{

    char nome[50];
    char CPF[12];
    char senha[50];
    int qttLivrosAlugados;

}Usuario;

typedef struct{

    int livroId;
    char titulo[50];
    char autor[50];
    char editora[50];
    int ano;
    int qttEstoque;
    int status; //0 - disponivel, 1 - indisponivel

}Livro;

typedef struct{
    char CPF[12];
    char nome[50];
    char data[20];
    int livroId;
    char titulo[50];
    char autor[50];
    char editora[50];
    char tipo[20];
} Historico;

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

#endif