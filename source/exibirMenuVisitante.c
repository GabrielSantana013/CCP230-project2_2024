#include <stdio.h>
#include "funcoes.h"

int exibirMenuVisitante() {
    int menu;
    char input[255];
    char *ptrInput;

    do {
        printf("\nBem vindo a Livraria!\n");
        printf("1 - Realizar cadastro\n");
        printf("2 - Realizar login\n");
        printf("3 - Sair\n");
        
        fgets(input, sizeof(input), stdin);
        ptrInput = input;
        menu = verificaDigito(ptrInput);

    } while (menu < 1 || menu > 3);

    return menu;
}
