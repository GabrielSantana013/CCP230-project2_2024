#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int consultarLivro()
{
    FILE *ptrArquivoLivro;
    ptrArquivoLivro = fopen("catalogo.txt", "r");
    if (ptrArquivoLivro == NULL){
        printf("Nao ha nenhum livro registrado.\n");
        return 1;
    }
    else{
        Livro livro_atual;
        int ID, opcao;
        char nome[50], autor[50], editora[50];
        printf("\n===CONSULTA DE LIVROS===\n");
        printf("1. Consultar por ID\n2. Consultar pelo nome do livro\n3. Consultar por autor\n4. Consultar por editora\n");
        scanf("%d", &opcao);
        limpaBuffer();

        switch(opcao) {
            case 1:
                printf("Digite o ID do livro: ");
                scanf("%d", &ID);
                break;
            case 2:
                printf("Digite o nome do livro: ");
                fgets(nome, 50, stdin);
                break;
            case 3:
                printf("Digite o nome do autor: ");
                fgets(autor, 50, stdin);
                break;
            case 4:
                printf("Digite o nome da editora: ");
                fgets(editora, 50, stdin);  
                break;
            default:
                printf("Opcao invalida.\n");
                fclose(ptrArquivoLivro);
                return 1;
        }
        
        long long int tamanhoArquivo;
        fseek(ptrArquivoLivro, 0, SEEK_END);
        tamanhoArquivo = ftell(ptrArquivoLivro);
        rewind(ptrArquivoLivro);
        int numRegistros = tamanhoArquivo / sizeof(Livro);

        int match;
        int found = 0; // Variável para verificar se algum livro foi encontrado
        int cabecalho = 0; // Variável para verificar se o cabeçalho da tabela foi impresso

        while (fread(&livro_atual, sizeof(livro_atual), 1, ptrArquivoLivro)){
            match = 0;
            switch(opcao){
                case 1:
                    if (livro_atual.livroId == ID && (ID > 0 && ID <= numRegistros)) match = 1;
                    break;
                case 2:
                    if (strcmp(livro_atual.titulo, nome) == 0) match = 1;
                    break;
                case 3:
                    if (strcmp(livro_atual.autor, autor) == 0) match = 1;
                    break;
                case 4:
                    if (strcmp(livro_atual.editora, editora) == 0) match = 1;
                    break;
            }

            if (match){
                if (!cabecalho) {
                    // Imprime o cabeçalho da tabela
                    printf("\n");
                    printf("%5s | %-50s | %-50s | %-50s | %-5s | %-10s | %-7s\n", 
                            "ID", "Titulo", "Autor", "Editora", "Ano", "Quantidade", "Status");
                    printf("--------------------------------------------------------------------------");
                    printf("--------------------------------------------------------------------------");
                    printf("-------------------------------------------------------------\n");
                    cabecalho = 1;
                }

                found = 1;

                // Retira o '\n' das strings
                livro_atual.titulo[strcspn(livro_atual.titulo, "\n")] = '\0';
                livro_atual.autor[strcspn(livro_atual.autor, "\n")] = '\0';
                livro_atual.editora[strcspn(livro_atual.editora, "\n")] = '\0';
                
                if (livro_atual.status == 0) {
                    printf("%5d | %-50s | %-50s | %-50s | %-5d | %-10d | %-7s\n", 
                    livro_atual.livroId, livro_atual.titulo, livro_atual.autor, livro_atual.editora, 
                    livro_atual.ano, livro_atual.qttEstoque, "Disponivel");
                } else if (livro_atual.status == 1) {
                    printf("%5d | %-50s | %-50s | %-50s | %-5d | %-10d | %-7s\n", 
                    livro_atual.livroId, livro_atual.titulo, livro_atual.autor, livro_atual.editora, 
                    livro_atual.ano, livro_atual.qttEstoque, "Alugado");
                } else if (livro_atual.status == 2) {
                    printf("%5d | %-50s | %-50s | %-50s | %-5d | %-10d | %-7s\n", 
                    livro_atual.livroId, livro_atual.titulo, livro_atual.autor, livro_atual.editora, 
                    livro_atual.ano, livro_atual.qttEstoque, "Vendido");
                }
            }
        }

        if (!found) {
            printf("Opcao invalida. Nenhum livro encontrado.\n");
        }
    }

    fclose(ptrArquivoLivro);
    return 0;
}