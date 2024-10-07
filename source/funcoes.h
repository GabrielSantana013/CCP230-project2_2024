#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct{

    int usuarioId;
    char nome[50];
    char CPF[12];
    char senha[50];


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
void limpabuffer();


#endif