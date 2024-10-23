#include <stdio.h>
#include "funcoes.h"

int exibirMenuCliente(Usuario *ptrUsuario){
    
    int menu;

    do
    {
        printf("\nBem-vindo, %s\n", ptrUsuario->nome);
        printf("1 - Exibir Catalogo\n");
        printf("2 - Alugar livro\n");
        printf("3 - Devolver livro\n");
        printf("4 - Consultar historico de alugueis\n");
        printf("5 - Sair\n");
        scanf("%d", &menu);
        limpaBuffer();


    }while(menu < 1 || menu > 5);

    return menu;
}