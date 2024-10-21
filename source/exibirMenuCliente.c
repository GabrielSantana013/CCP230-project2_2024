#include <stdio.h>
#include "funcoes.h"

int exibirMenuCliente(Usuario *ptrUsuario){
    int menu;
    char input[255];
    char *ptrInput;

    do
    {
        printf("\nBem-vindo, %s\n", ptrUsuario->nome);
        printf("1 - Comprar livro\n");
        printf("2 - Catalogar livros\n");
        printf("3 - Alugar livro\n");
        printf("4 - Devolver livro\n");
        printf("5 - Consultar historico de alugueis\n");
        printf("6 - Sair\n");
        
        fgets(input, sizeof(input), stdin);
        ptrInput = input;
        menu = verificaDigito(ptrInput);

    }while(menu < 1 || menu > 6);

    return menu;
}

/*

ARRUMAR A MENSAGEM DE BEM-VINDO PARA VIR CORRETAMENTE COM O NOME DO USUÁRIO


*/