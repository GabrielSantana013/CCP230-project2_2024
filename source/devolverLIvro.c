#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int devolverLivro(Usuario *ptrUsuario)
{
    FILE *ptrArquivoAlugados;

    Historico historico;
    int ID;

    ptrArquivoAlugados = fopen("alugados.bin", "rb+");

    if (ptrArquivoAlugados == NULL)
    {
        printf("Nenhum livro alugado.\n");
        return 1;
    }
    else
    {
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
            return 1;
        }

        //rewind(ptrArquivoAlugados);
        fseek(ptrArquivoAlugados, 0, SEEK_SET);

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

        rewind(ptrArquivoAlugados);

        int achado = 0;
        size_t bytesHitorico = sizeof(Historico);
        while(fread(&historico, sizeof(historico), 1, ptrArquivoAlugados))
        {
            if (strcmp(historico.CPF, ptrUsuario->CPF) == 0 && historico.livroId == ID)
            {
                fseek(ptrArquivoAlugados, -bytesHitorico, SEEK_CUR);
                strcpy(historico.CPF, "*");
                printf("Livro devolvido com sucesso.\n");
                fwrite(&historico, sizeof(historico), 1, ptrArquivoAlugados);
                fclose(ptrArquivoAlugados);

                //atualizar o catalogo
                FILE *ptrArquivoCatalogo;
                Livro livro;
                ptrArquivoCatalogo = fopen("catalogo.txt", "r+");
                while(fread(&livro, sizeof(livro), 1, ptrArquivoCatalogo))
                {
                    if(livro.livroId == ID)
                    {
                        fseek(ptrArquivoCatalogo, -sizeof(livro), SEEK_CUR);
                        livro.qttEstoque += 1;
                        fwrite(&livro, sizeof(livro), 1, ptrArquivoCatalogo);
                        fclose(ptrArquivoCatalogo);
                        break;
                    }
                }

                //atualiza
                FILE *ptrArquivoHistorico;
                ptrArquivoHistorico = fopen("historico.bin", "ab");
                if(ptrArquivoHistorico == NULL)
                {
                    printf("Erro ao abrir o arquivo de historico.\n");
                    return 1;
                }
                else
                {
                    strcpy(historico.CPF, ptrUsuario->CPF);
                    strcpy(historico.tipo, "Devolucao");
                    fwrite(&historico, sizeof(historico), 1, ptrArquivoHistorico);
                    printf("Historico atualizado.\n");
                }
                fclose(ptrArquivoHistorico);

                achado = 1;
                break;
            }
        }

        if(!achado)
        {
            printf("Livro não encontrado.\n");
        }
        
        return 0;
    }
}
