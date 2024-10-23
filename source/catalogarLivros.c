#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int catalogarLivros()
{
    FILE *ptrArquivo;
    Livro livro_atual;
    size_t bytes = sizeof(Livro);

    ptrArquivo = fopen("catalogo.txt", "r");
    if (ptrArquivo == NULL)
    {
        printf("Ainda nao ha catalogo.\n");
        return 1;
    }

    printf("\n");
    // Imprime o cabeçalho da tabela
    printf("%5s | %-50s | %-50s | %-50s | %-5s | %-10s | %-7s\n",
           "ID", "Titulo", "Autor", "Editora", "Ano", "Quantidade", "Status");
    printf("--------------------------------------------------------------------------");
    printf("--------------------------------------------------------------------------");
    printf("-------------------------------------------------------------\n");

    while (fread(&livro_atual, bytes, 1, ptrArquivo) == 1)
    {
        // Retira o '\n' das strings
        livro_atual.titulo[strcspn(livro_atual.titulo, "\n")] = '\0';
        livro_atual.autor[strcspn(livro_atual.autor, "\n")] = '\0';
        livro_atual.editora[strcspn(livro_atual.editora, "\n")] = '\0';

        if (livro_atual.status == 0)
        {
            printf("%5d | %-50s | %-50s | %-50s | %-5d | %-10d | %-7s\n",
                   livro_atual.livroId, livro_atual.titulo, livro_atual.autor, livro_atual.editora,
                   livro_atual.ano, livro_atual.qttEstoque, "Disponivel");
        }
        else if (livro_atual.status == 1)
        {
            printf("%5d | %-50s | %-50s | %-50s | %-5d | %-10d | %-7s\n",
                   livro_atual.livroId, livro_atual.titulo, livro_atual.autor, livro_atual.editora,
                   livro_atual.ano, livro_atual.qttEstoque, "Alugado");
        }
    }

    fclose(ptrArquivo);
    return 0;
}
