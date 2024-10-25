#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int relatorioAlugueis(){
    FILE *ptrArquivo;
    Historico historico;
    int opcao;

    ptrArquivo = fopen("historico.bin", "rb");
    if(ptrArquivo == NULL){
        printf("Nao ha nenhum registro de aluguel.\n");
        return 1;
    }
    else{
        printf("\n===Relatorio de Alugueis===\nSelecione a opção desejada:");
        printf("\n1 - Relatorio de alugueis geral\n2 - Relatorio de alugueis por dia\n3 - Relatorio de alugueis por mes\n4 - Relatorio de alugueis por usuario\n");
        scanf("%d", &opcao);
        limpaBuffer();

        if(opcao < 1 || opcao > 4){
            printf("Opcao invalida.\n");
            return 1;
        }

        switch (opcao)
        {
        case 1:
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|     CPF     |        Nome        |       Data        |            Titulo            |      Autor      |     Editora     | Tipo de Transacao |\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&historico, sizeof(historico), 1, ptrArquivo)){
                printf("| %-11s | %-18s | %10s | %-28s | %-15s | %-15s | %-17s |\n",  historico.CPF, historico.nome, historico.data, historico.titulo, historico.autor, historico.editora, historico.tipo);
            }
            break;
        case 2:
            printf("Digite a data para gerar o relatorio (dd/mm/aa): ");
            char data[20];
            fgets(data, 20, stdin);
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|     CPF     |        Nome        |       Data        |            Titulo            |      Autor      |     Editora     | Tipo de Transacao |\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&historico, sizeof(historico), 1, ptrArquivo)){
                if(strncmp(historico.data, data, strcspn(historico.data, " ")) == 0){
                    printf("| %-11s | %-18s | %10s | %-28s | %-15s | %-15s | %-17s |\n",  historico.CPF, historico.nome, historico.data, historico.titulo, historico.autor, historico.editora, historico.tipo);
                }
            }
            break;
        case 3:
            printf("Digite o mes para gerar o relatorio (mm/aa): ");
            char mes[20];
            fgets(mes, 20, stdin);
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|     CPF     |        Nome        |       Data        |            Titulo            |      Autor      |     Editora     | Tipo de Transacao |\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&historico, sizeof(historico), 1, ptrArquivo)){
                if (strncmp(historico.data + 3, mes, 5) == 0)
                {
                    printf("| %-11s | %-18s | %10s | %-28s | %-15s | %-15s | %-17s |\n",  historico.CPF, historico.nome, historico.data, historico.titulo, historico.autor, historico.editora, historico.tipo);
                }
                
            }
            break;
        case 4:
            printf("Digite o CPF do usuario para gerar o relatorio: ");
            char CPF[12];
            fgets(CPF, 12, stdin);
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|     CPF     |        Nome        |       Data        |            Titulo            |      Autor      |     Editora     | Tipo de Transacao |\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&historico, sizeof(historico), 1, ptrArquivo)){
                if (strncmp(historico.CPF, CPF, 11) == 0)
                {
                    printf("| %-11s | %-18s | %10s | %-28s | %-15s | %-15s | %-17s |\n",  historico.CPF, historico.nome, historico.data, historico.titulo, historico.autor, historico.editora, historico.tipo);
                }
            }
            limpaBuffer();
            break;
        default:
            printf("Erro.\n");
            return 1;
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(ptrArquivo);
    return 0;
}