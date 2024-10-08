#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{

    int (*ptrFuncoesVisitante[])(Usuario *) = {cadastrar};
    Usuario usuario, *ptrUsuario;
    ptrUsuario = &usuario;

    int menu;

    do
    {
        
        menu = (exibirMenuVisitante()) - 1;
        if(menu>3 && menu<1)
        {
            printf("Opcao invalida\n");
        }
        else
        {
            ptrFuncoesVisitante[menu](ptrUsuario);
        }

    } while (menu != 3);

    return 0;
}