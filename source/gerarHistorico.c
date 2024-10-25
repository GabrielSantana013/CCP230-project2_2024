#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int gerarHistorico(Carrinho *carrinho, Usuario *usuario)
{
    FILE *ptrArquivoHistorico;
    FILE *ptrArquivoAlugados;
    Historico historico;

    ptrArquivoHistorico = fopen("historico.bin", "ab+");
    if (ptrArquivoHistorico == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    else
    {
        ptrArquivoAlugados = fopen("alugados.bin", "ab+");
        if (ptrArquivoAlugados == NULL){
            printf("Erro ao abrir o arquivo.\n");
            fclose(ptrArquivoAlugados);
            return 1;
        }
    
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        char data[20];
        sprintf(data, "%02d/%02d/%02d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year % 100, tm.tm_hour, tm.tm_min, tm.tm_sec);

        strcpy(historico.CPF, usuario->CPF);
        historico.CPF[strcspn(historico.CPF, "\n")] = 0; // retira o \n
        strcpy(historico.nome, usuario->nome);
        historico.nome[strcspn(historico.nome, "\n")] = 0;
        strcpy(historico.data, data);
        for (int i = 0; i < carrinho->tamanho; i++)
        {
            historico.livroId = carrinho->livros[i].livroId;
            strcpy(historico.titulo, carrinho->livros[i].titulo);
            historico.titulo[strcspn(historico.titulo, "\n")] = 0;
            strcpy(historico.autor, carrinho->livros[i].autor);
            historico.autor[strcspn(historico.autor, "\n")] = 0;
            strcpy(historico.editora, carrinho->livros[i].editora);
            historico.editora[strcspn(historico.editora, "\n")] = 0;
            strcpy(historico.tipo, "Alugado");
            historico.tipo[strcspn(historico.tipo, "\n")] = 0;
            fwrite(&historico, sizeof(historico), 1, ptrArquivoHistorico);

            fwrite(&historico, sizeof(historico), 1, ptrArquivoAlugados);
            usuario->qttLivrosAlugados++;
        }
    }

    fclose(ptrArquivoAlugados);
    fclose(ptrArquivoHistorico);

    FILE *ptrArquivoCatalogo;
    // decrementa 1 da quantidade de livros no estoque
    ptrArquivoCatalogo = fopen("catalogo.txt", "r+");

    if (ptrArquivoCatalogo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }
    else
    {
        Livro livro_atual;
        size_t bytes = sizeof(Livro);

        for (int i = 0; i < carrinho->tamanho; i++)
        {
            rewind(ptrArquivoCatalogo); // Volta ao início do arquivo para cada livro no carrinho
            while (fread(&livro_atual, bytes, 1, ptrArquivoCatalogo) == 1)
            {
                if (carrinho->livros[i].livroId == livro_atual.livroId)
                {
                    if (livro_atual.status || livro_atual.qttEstoque <= 0)
                    {
                        printf("O livro %s está indisponível no momento.\n", livro_atual.titulo);
                        fseek(ptrArquivoCatalogo, -bytes, SEEK_CUR);
                        livro_atual.status = INDISPONIVEL;
                        fwrite(&livro_atual, bytes, 1, ptrArquivoCatalogo);
                        break;
                    }
                    else
                    {
                        // Ajusta a quantidade de estoque
                        livro_atual.qttEstoque--;

                        // Volta o ponteiro para o início do registro atual
                        fseek(ptrArquivoCatalogo, -bytes, SEEK_CUR);

                        // Reescreve o livro com a quantidade ajustada
                        fwrite(&livro_atual, bytes, 1, ptrArquivoCatalogo);
                    }
                    break;
                }
            }
        }
    }

    fclose(ptrArquivoCatalogo);

    return 0;
}