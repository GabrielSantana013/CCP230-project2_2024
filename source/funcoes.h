#ifndef FUNCOES_H
#define FUNCOES_H

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
    float preco;

}Livro;

int exibirMenuVisitante();
int exibirMenuAdm();
void limpaBuffer();
int verificaDigito(char *entrada);
int cadastrar(Usuario *ptrUsuario);
int logar(Usuario *ptrUsuario);
int verificarCPF(Usuario *ptrUsuario);


#endif