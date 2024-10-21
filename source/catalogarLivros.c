#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void catalogarLivros(){
    FILE *ptrArquivo;
    Livro livro_atual;
    size_t bytes = sizeof(Livro);

    ptrArquivo = fopen("livros.txt", "r");
    if(ptrArquivo == NULL){
        printf("ERRO: O arquivo ainda não existe.\n");
        exit(1);
    }

    printf("\n");
    // Imprime o cabeçalho da tabela
    printf("%-5s | %-30s | %-20s | %-20s | %-5s | %-10s | %-13s | %-7s\n", 
           "ID", "Titulo", "Autor", "Editora", "Ano", "Quantidade", "Preco", "Status");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&livro_atual, bytes, 1, ptrArquivo) == 1) {
        // Remove the newline character from the strings
        livro_atual.titulo[strcspn(livro_atual.titulo, "\n")] = '\0';
        livro_atual.autor[strcspn(livro_atual.autor, "\n")] = '\0';
        livro_atual.editora[strcspn(livro_atual.editora, "\n")] = '\0';

        printf("%-5d | %-30s | %-20s | %-20s | %-5d | %-10d | R$ %-10.2f | %-7d\n", 
               livro_atual.livroId, livro_atual.titulo, livro_atual.autor, livro_atual.editora, 
               livro_atual.ano, livro_atual.qttEstoque, livro_atual.preco, livro_atual.status);
        }

    fclose(ptrArquivo);
}
