#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int cadastrarLivro(){
    FILE *ptrArquivo;
    Livro novo_livro;
    size_t bytes = sizeof(Livro);

    printf("\n===CADASTRANDO LIVRO===\n");
    ptrArquivo = fopen("livros.txt", "a+");
    if (ptrArquivo == NULL)
    {
        ptrArquivo = fopen("livros.txt", "w");
        if (ptrArquivo == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }
    }
    fseek(ptrArquivo, 0, SEEK_END); // Aponta para o final do arquivo
    long fileSize = ftell(ptrArquivo); // Pega o tamanho do arquivo
    if (fileSize == 0) {
        novo_livro.livroId = 1; // Primeiro livro
    } else {
        fseek(ptrArquivo, -bytes, SEEK_END); // Aponta para o ultimo livro
        fread(&novo_livro, bytes, 1, ptrArquivo);
        novo_livro.livroId += 1;
    }
    
    printf("Digite o titulo do livro: ");
    fgets(novo_livro.titulo, sizeof(novo_livro.titulo), stdin);
    printf("Digite o autor do livro: ");
    fgets(novo_livro.autor, sizeof(novo_livro.autor), stdin);
    printf("Digite a editora do livro: ");
    fgets(novo_livro.editora, sizeof(novo_livro.editora), stdin);
    printf("Digite o ano do livro: ");
    scanf("%d", &novo_livro.ano);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novo_livro.qttEstoque);
    printf("Digite o preco do livro: ");
    scanf("%f", &novo_livro.preco);
    novo_livro.status = 0;
    fprintf(ptrArquivo, "ID: %d\nTitulo: %sAutor: %sEditora: %sAno: %d\nQuantidade: %d\nPreco: %.2f\nStatus: %d\n", novo_livro.livroId, novo_livro.titulo, novo_livro.autor, novo_livro.editora, novo_livro.ano, novo_livro.qttEstoque, novo_livro.preco, novo_livro.status);
    
    fclose(ptrArquivo);
    return 0;
}