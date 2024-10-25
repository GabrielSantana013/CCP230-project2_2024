#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int consultarHistorico(Usuario *ptrUsuario)
{
    FILE *ptrArquivo;
    ptrArquivo = fopen("historico.bin", "rb+");
    if (ptrArquivo == NULL)
    {
        printf("Nao ha nenhum historico a ser consultado.\n");
        return 1;
    }
    else
    {
        Historico historico;
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("| CPF: %s  | Nome: %s", ptrUsuario->CPF, ptrUsuario->nome);
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("|       Data        |            Titulo            |      Autor      |     Editora     | Tipo de Transacao |\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        while (fread(&historico, sizeof(historico), 1, ptrArquivo))
        {
            if (strcmp(historico.CPF, ptrUsuario->CPF) == 0)
            {
                printf("| %10s | %-28s | %-15s | %-15s | %-17s |\n", historico.data, historico.titulo, historico.autor, historico.editora, historico.tipo);
            }
        }
        printf("------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(ptrArquivo);
    return 0;
}