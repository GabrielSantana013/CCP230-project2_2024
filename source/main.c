#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{
    //ponteiro para funcoes de visitante
    int (*ptrFuncoesVisitante[])(Usuario *) = {cadastrar, logar};
    //ponteiro para funcoes de clientes
    int (*ptrFuncoesCliente[])(Usuario *) = {};
    Usuario usuario, *ptrUsuario;
    ptrUsuario = &usuario;

    int menu, retorno;

    do
    {
        menu = (exibirMenuVisitante()) - 1;
        if(menu>3 && menu<1)
        {
            printf("Opcao invalida\n");
        }
        //opcao 3 é sair
        else if(menu == 2)
        {
            exit(0);
        }
        else
        {
            retorno = ptrFuncoesVisitante[menu](ptrUsuario);

            if(retorno == 2)
            {
                break;
            }
        }

    } while (menu != 3);

    do 
    {
        menu = exibirMenuCliente();
        if(menu == 5)
        {
            break;
        }


    }while(menu != 5);
    
    return 0;
}