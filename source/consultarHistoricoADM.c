#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int consultarHistoricoADM()
{
    FILE *ptrArquivo;
    Historico historico;
    int head = 0;
    char cpf[12];

    printf("Digite o CPF: ");
    scanf("%11s", cpf);
    limpaBuffer();
    cpf[11] = '\0';

    if (strcmp(cpf, "12312312312") == 0){
        printf("O administrador nao possui historico.\n");
        return 1;
    }
    

    ptrArquivo = fopen("historico.bin", "rb+");
    if (ptrArquivo == NULL){
        printf("Nao ha nenhum historico a ser consultado.\n");
        return 1;
    }
    else{
        while (fread(&historico, sizeof(historico), 1, ptrArquivo))
        {
            if(!head){
                printf("------------------------------------------------------------------------------------------------------------\n");
                printf("| CPF: %s  | Nome: %s\n", historico.CPF, historico.nome);
                printf("------------------------------------------------------------------------------------------------------------\n");
                printf("|       Data        |            Titulo            |      Autor      |     Editora     | Tipo de Transacao |\n");
                printf("------------------------------------------------------------------------------------------------------------\n");
            }
            head = 1;
            if (strcmp(historico.CPF, cpf) == 0)
            {
                printf("| %10s | %-28s | %-15s | %-15s | %-17s |\n", historico.data, historico.titulo, historico.autor, historico.editora, historico.tipo);
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(ptrArquivo);
    return 0;
}