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
    // int (*ptrFuncoesCliente[])(Usuario *) = {};
    Usuario usuario, *ptrUsuario;
    ptrUsuario = &usuario;

    int menu, retorno;

    do
    {
        menu = (exibirMenuVisitante()) - 1;
        if (menu > 3 && menu < 1)
        {
            printf("Opcao invalida.\n");
        }
        // opcao 3 é sair
        else if (menu == 2)
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
            menu = exibirMenuAdm();
            switch (menu)
            {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                catalogarLivros();
                break;
            case 7:
                break;
            default:
                continue;
            }

        } while (menu != 7);
    }

    else if (retorno == 2)
    {
        do
        {
            menu = exibirMenuCliente(ptrUsuario);
            switch (menu)
            {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                catalogarLivros();
                break;
            case 7:
                break;
            default:
                continue;
            }

        } while (menu != 6);
    }

    return 0;
}