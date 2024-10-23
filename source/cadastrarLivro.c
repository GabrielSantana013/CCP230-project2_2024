#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int cadastrarLivro(){
    
    FILE *ptrArquivoLivro;
    Livro novo_livro, livro_anterior;

    printf("\n===CADASTRANDO LIVRO===\n");
    ptrArquivoLivro = fopen("catalogo.txt", "a+");
    if (ptrArquivoLivro == NULL)
    {
        ptrArquivoLivro = fopen("catalogo.txt", "w");
        if (ptrArquivoLivro == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }
    }
    
    int dadosValidos;
    dadosValidos = 1; // Assume que os dados são válidos
    do {
        char titulo[256];
        printf("Digite o titulo do livro: ");
        fgets(titulo, sizeof(titulo), stdin);
        if (strlen(titulo) > 50) {
            printf("Titulo muito longo. Deve ter no maximo 50 caracteres.\n");
            dadosValidos = 0;
            continue;
        }
        strcpy(novo_livro.titulo, titulo);
        dadosValidos = 1;
    } while (!dadosValidos);

    do {
        char autor[256];
        printf("Digite o autor do livro: ");
        fgets(autor, sizeof(autor), stdin);
        if (strlen(autor) > 50) {
            printf("Autor muito longo. Deve ter no maximo 50 caracteres.\n");
            dadosValidos = 0;
            continue;
        }
        strcpy(novo_livro.autor, autor);
        dadosValidos = 1;
    } while (!dadosValidos);

    do {
        char editora[256];
        printf("Digite a editora do livro: ");
        fgets(editora, sizeof(editora), stdin);
        if (strlen(editora) > 50) {
            printf("Editora muito longa. Deve ter no maximo 50 caracteres.\n");
            dadosValidos = 0;
            continue;
        }
        strcpy(novo_livro.editora, editora);
        dadosValidos = 1;
    } while (!dadosValidos);

    do {
        printf("Digite o ano do livro: ");
        char anoStr[10];
        if (scanf("%s", anoStr) != 1 || verificaDigito(anoStr) == 0) {
            printf("Ano invalido.\n");
            dadosValidos = 0;
            continue;
        }
        limpaBuffer();
        novo_livro.ano = atoi(anoStr);
        dadosValidos = 1;
    } while (!dadosValidos);

    do {
        printf("Digite a quantidade em estoque: ");
        char qttEstoqueStr[10];
        if (scanf("%s", qttEstoqueStr) != 1 || verificaDigito(qttEstoqueStr) == 0) {
            printf("Quantidade em estoque invalida.\n");
            dadosValidos = 0;
            continue;
        }
        limpaBuffer();
        novo_livro.qttEstoque = atoi(qttEstoqueStr);
        dadosValidos = 1;
    } while (!dadosValidos);

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