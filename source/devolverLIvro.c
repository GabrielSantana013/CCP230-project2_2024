#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int devolverLivro(Usuario *ptrUsuario)
{
    Historico historico;
    int ID;

    FILE *ptrArquivoHistorico;
    FILE *ptrArquivoAlugados;
    ptrArquivoAlugados = fopen("alugados.bin", "rb+");
    if (ptrArquivoAlugados == NULL){
        printf("Nenhum livro alugado.\n");
        return 1;
    }
    else{
        ptrArquivoHistorico = fopen("historico.bin", "rb+");
        if(ptrArquivoHistorico == NULL){
            printf("Erro ao abrir o arquivo de historico.\n");
            return 1;
        }

        int registro = 0;
        while (fread(&historico, sizeof(historico), 1, ptrArquivoAlugados))
        {
            if (strcmp(historico.CPF, ptrUsuario->CPF) == 0)
            {
                registro = 1;
                break;
            }
        }

        if (!registro)
        {
            printf("Nenhum registro encontrado para o seu CPF.\n");
            fclose(ptrArquivoAlugados);
            fclose(ptrArquivoHistorico);
            return 1;
        }

        rewind(ptrArquivoAlugados);

        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("|  Livros Alugados  |\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("|       Data        | ID |            Titulo            |      Autor      |     Editora     |\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        while (fread(&historico, sizeof(historico), 1, ptrArquivoAlugados))
        {
            if (strcmp(historico.CPF, ptrUsuario->CPF) == 0)
            {
            printf("| %10s | %-2d | %-28s | %-15s | %-15s |\n", historico.data, historico.livroId, historico.titulo, historico.autor, historico.editora);
            }
        }
        printf("-----------------------------------------------------------------------------------------------------\n");

        printf("\nDigite o ID do livro que deseja devolver: \n");
        scanf("%d", &ID);

        while (fread(&historico, sizeof(historico), 1, ptrArquivoAlugados))
        {
            if (strcmp(historico.CPF, ptrUsuario->CPF) == 0 && historico.livroId == ID)
            {
                strcpy(historico.tipo, "Devolvido");
                historico.tipo[strcspn(historico.tipo, "\n")] = 0;
                fseek(ptrArquivoHistorico, sizeof(historico), SEEK_END);
                fwrite(&historico, sizeof(historico), 1, ptrArquivoHistorico);

                fseek(ptrArquivoAlugados, -sizeof(historico), SEEK_CUR);
                fwrite(&historico, sizeof(historico), 1, ptrArquivoAlugados);
                break;
            }
        }

        fclose(ptrArquivoAlugados);

        FILE *ptrArquivoCatalogo;
        ptrArquivoCatalogo = fopen("catalogo.txt", "r+");
        if (ptrArquivoCatalogo == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        else
        {
            Livro livro_atual;
            size_t bytes = sizeof(Livro);
            while (fread(&livro_atual, bytes, 1, ptrArquivoCatalogo))
            {
                if (livro_atual.livroId == ID)
                {
                    livro_atual.qttEstoque++;
                    fseek(ptrArquivoCatalogo, -bytes, SEEK_CUR);
                    fwrite(&livro_atual, bytes, 1, ptrArquivoCatalogo);
                    break;
                }
            }
        }

        fclose(ptrArquivoCatalogo);
        return 0;
    }
}