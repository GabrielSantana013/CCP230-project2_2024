#include <stdio.h>

int exibirMenuCliente(){
    int menu;
    char input[255];
    char *ptrInput;

    do
    {
        printf("\nBem-vindo, cliente!\n");
        printf("1 - Comprar livro\n");
        printf("2 - Alugar livro\n");
        printf("3 - Devolver livro\n");
        printf("4 - Consultar historico de alugueis\n");
        printf("5 - Sair\n");
        
        fgets(input, sizeof(input), stdin);
        ptrInput = input;
        menu = verificaDigito(ptrInput);

    }while(menu < 1 || menu > 5);

    return menu;
}