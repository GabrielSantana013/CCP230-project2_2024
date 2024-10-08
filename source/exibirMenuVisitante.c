#include <stdio.h>

int exibirMenuVisitante(){

    int menu;
    do
    {
        printf("Bem vindo a Livraria!\n");
        printf("1 - Realizar cadastro\n");
        printf("2 - Realizar login\n");
        printf("3 - Sair\n");
        scanf("%d", &menu);

    }while(menu < 1 || menu > 3);

    return menu;
}