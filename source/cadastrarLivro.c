#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int cadastrarLivro(){
    
    FILE *ptrArquivoLivro;
    Livro novo_livro, livro_anterior;

    printf("\n===CADASTRANDO LIVRO===\n");
    ptrArquivoLivro = fopen("livros.txt", "a+");
    if (ptrArquivoLivro == NULL)
    {
        ptrArquivoLivro = fopen("livros.txt", "w");
        if (ptrArquivoLivro == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }
    }
    
    printf("Digite o titulo do livro: ");
    fgets(novo_livro.titulo, sizeof(novo_livro.titulo), stdin);
    printf("Digite o autor do livro: ");
    fgets(novo_livro.autor, sizeof(novo_livro.autor), stdin);
    printf("Digite a editora do livro: ");
    fgets(novo_livro.editora, sizeof(novo_livro.editora), stdin);
    printf("Digite o ano do livro: ");
    scanf("%d", &novo_livro.ano);
    limpaBuffer();
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novo_livro.qttEstoque);
    limpaBuffer();
    printf("Digite o preco do livro: ");
    scanf("%f", &novo_livro.preco);
    limpaBuffer();
    novo_livro.status = DISPONIVEL;
    
    long long int tamanhoArquivo;

    fseek(ptrArquivoLivro, 0, SEEK_END);
    tamanhoArquivo = ftell(ptrArquivoLivro);

    if(tamanhoArquivo == 0)
    {
        novo_livro.livroId = 1;
    }
    else
    {
        fseek(ptrArquivoLivro, -sizeof(Livro), SEEK_END);
        fread(&livro_anterior, sizeof(livro_anterior), 1, ptrArquivoLivro);
        novo_livro.livroId = livro_anterior.livroId + 1;
    }
    
    fwrite(&novo_livro, sizeof(novo_livro), 1, ptrArquivoLivro);
    fclose(ptrArquivoLivro);
    return 0;
}