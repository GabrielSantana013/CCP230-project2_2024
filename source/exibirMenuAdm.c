#include <stdio.h>
#include "funcoes.h"

int exibirMenuAdm(){
    int menu;
    char input[255];
    char *ptrInput;

    do
    {
        printf("\nBem-vindo, administrador!\n");
        printf("Como deseja prosseguir?\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Consultar historico de cliente\n");
        printf("3 - Consultar livro\n");
        printf("4 - Gerar relatorio de vendas\n");
        printf("5 - Gerar desconto\n");
        printf("6 - Sair\n");
        
        fgets(input, sizeof(input), stdin);
        ptrInput = input;
        menu = verificaDigito(ptrInput);

    }while(menu < 1 || menu > 6);

    return menu;
}