#include <stdio.h>
#include <stdlib.h>
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
    
    while (fread(&livro_atual, bytes, 1, ptrArquivo) == 1) {
        printf("\nID: %d\n", livro_atual.livroId);
        printf("Titulo: %s\n", livro_atual.titulo);
        printf("Autor: %s\n", livro_atual.autor);
        printf("Editora: %s\n", livro_atual.editora);
        printf("Ano: %d\n", livro_atual.ano);
        printf("Quantidade: %d\n", livro_atual.qttEstoque);
        printf("Preco: %.2f\n", livro_atual.preco);
        printf("Status: %d\n", livro_atual.status);
        printf("-------------------------------\n");
    }

    fclose(ptrArquivo);
    
}