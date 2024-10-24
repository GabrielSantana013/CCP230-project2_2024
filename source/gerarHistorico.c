#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int gerarHistorico(Carrinho *carrinho, Usuario *usuario)
{
    FILE *ptrArquivo;
    ptrArquivo = fopen("historico.bin", "ab+");
    if (ptrArquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    else
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        char data[20];
        sprintf(data, "%02d/%02d/%02d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year % 100, tm.tm_hour, tm.tm_min, tm.tm_sec);

        Historico historico;
        strcpy(historico.CPF, usuario->CPF);
        historico.CPF[strcspn(historico.CPF, "\n")] = 0; // retira o \n
        strcpy(historico.nome, usuario->nome);
        historico.nome[strcspn(historico.nome, "\n")] = 0;
        strcpy(historico.data, data);
        for (int i = 0; i < carrinho->tamanho; i++)
        {
            strcpy(historico.titulo, carrinho->livros[i].titulo);
            historico.titulo[strcspn(historico.titulo, "\n")] = 0;
            strcpy(historico.autor, carrinho->livros[i].autor);
            historico.autor[strcspn(historico.autor, "\n")] = 0;
            strcpy(historico.editora, carrinho->livros[i].editora);
            historico.editora[strcspn(historico.editora, "\n")] = 0;
            historico.quantidade = 1;
            fwrite(&historico, sizeof(historico), 1, ptrArquivo);
        }
    }

    fclose(ptrArquivo);
    return 0;
}