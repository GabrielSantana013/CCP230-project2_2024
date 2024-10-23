#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int consultarHistorico(Usuario *usuario)
{
    FILE *ptrArquivo;
    ptrArquivo = fopen("historico.bin", "rb+");
    if (ptrArquivo == NULL)
    {
        printf("Nao ha nenhum historico a ser consultado.\n");
        exit(1);
    }
    else
    {
        Historico historico;
        while (fread(&historico, sizeof(historico), 1, ptrArquivo))
        {
            if (strcmp(historico.CPF, usuario->CPF) == 0)
            {
                printf("CPF: %s\tNome: %s\n", historico.CPF, historico.nome);
                printf("Data: %s\n", historico.data);
                printf("Tipo: %s\n", historico.tipo);
                printf("Titulo: %s\n", historico.titulo);
                printf("Autor: %s\n", historico.autor);
                printf("Quantidade: %d\n", historico.quantidade);
                printf("Total: %.2f\n", historico.total);
                printf("\n");
            }
        }
    }
    fclose(ptrArquivo);
    return 0;
}