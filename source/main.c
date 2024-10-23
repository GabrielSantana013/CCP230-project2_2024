#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{

    // bloco para cadastrar o ADM caso não exista o arquivo clientes.bin
    FILE *ptrArquivo;
    ptrArquivo = fopen("clientes.bin", "rb+");
    if (ptrArquivo == NULL)
    {
        ptrArquivo = fopen("clientes.bin", "wb+");
        if (ptrArquivo == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }
        else
        {
            Usuario usuario;
            strcpy(usuario.CPF, "12312312312");
            strcpy(usuario.nome, "admin\n");
            strcpy(usuario.senha, "admin\n");
            usuario.qttLivrosAlugados = 0;
            usuario.qttLivrosComprados = 0;
            fwrite(&usuario, sizeof(usuario), 1, ptrArquivo);
        }
    }
    fclose(ptrArquivo);

    // ponteiro para funcoes de visitante
    int (*ptrFuncoesVisitante[])(Usuario *) = {cadastrarUsuario, logar};

    // ponteiro para funcoes de clientes
    int (*ptrFuncoesCliente[])(Usuario *) = {exibirLivrosClientes ,carrinhoDeCompras};

    // ponteiro para funcoes de adm
    int (*ptrFuncoesAdm[])() = {cadastrarLivro, catalogarLivros, consultarHistorico, consultarLivro};
    Usuario usuario, *ptrUsuario;
    ptrUsuario = &usuario;

    int menu, retorno;

    do
    {
        menu = (exibirMenuVisitante()) - 1;
        // opcao 3 é sair
        if (menu == 2)
        {
            exit(0);
        }
        else
        {
            retorno = ptrFuncoesVisitante[menu](ptrUsuario);

            if (retorno == 2 || retorno == 3)
            {
                break;
            }
        }

    } while (menu != 3);

    if (retorno == 3)
    {
        do
        {
            menu = (exibirMenuAdm())-1;
            // opcao 6 é sair
            if(menu == 5)
            {
                exit(0);
            }
            else
            {
                ptrFuncoesAdm[menu]();
            }

        } while (menu != 5);
    }

    else if (retorno == 2)
    {
        do
        {
            menu = (exibirMenuCliente(ptrUsuario)) - 1;
            // opcao 5 é sair
            if(menu == 4)
            {
                exit(0);
            }
            else
            {
                ptrFuncoesCliente[menu](ptrUsuario);
            }

        } while (menu != 4);
    }

    return 0;
}