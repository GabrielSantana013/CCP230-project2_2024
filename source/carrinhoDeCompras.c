#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void inicializarCarrinho(Carrinho **carrinho){

    *carrinho = (Carrinho *) malloc(sizeof(Carrinho)); 
    
    if(*carrinho == NULL){
        printf("Erro ao alocar memoria na criacao do carrinho.\n");
        exit(1);
    }

    (*carrinho)->capacidade = 10;
    (*carrinho)->tamanho = 0;
    

    (*carrinho)->livros = (Livro *)malloc((*carrinho)->capacidade * sizeof(Livro));
    if((*carrinho)->livros == NULL){
        printf("Erro ao alocar memoria para os livros do carrinho.\n");
        exit(1);
    }
}


void removerLivro(Carrinho *carrinho, size_t id){

    int encontrado = 0;

    for(int i = 0; i < carrinho->tamanho; i++){
        //procura o item pelo id
        if(carrinho->livros[i].livroId == id)
        {
            encontrado = 1;
            //pega os itens a partir do encontrado e joga o próximo na posição atual
            //assim ele desloca todos os itens para a esquerda
            for(int j = i; j < carrinho->tamanho -1; j++)
            {
                carrinho->livros[j] = carrinho->livros[j+1];
            }
            carrinho->tamanho--;
            break;
        }
    }

    if(!encontrado)
    {
        printf("Livro nao encontrado no carrinho.\n");
    }
}

void exibirCarrinho(Carrinho *carrinho)
{

    printf("\n\n===Seu carrinho atual===\n");
    for(int i = 0; i < carrinho->tamanho; i++)
    {
        printf("ID: %d\n", carrinho->livros[i].livroId);
        printf("Titulo: %s", carrinho->livros[i].titulo);
        printf("Autor: %s", carrinho->livros[i].autor);
        printf("Editora: %s", carrinho->livros[i].editora);
        printf("Ano: %d\n", carrinho->livros[i].ano);
        printf("Status: %d\n", carrinho->livros[i].status);
        printf("\n");
    }
    printf("Voce tem %lu livros no carrinho.\n", carrinho->tamanho);
    printf("===Fim do carrinho===\n\n");
}

void apagaCarrinho(Carrinho *carrinho){

    free(carrinho->livros);
    //Boas práticas p/ evitar erros de memória
    carrinho->livros = NULL;
    carrinho->capacidade = 0;
    carrinho->tamanho = 0;

}

void adicionarLivro(Carrinho *carrinho, Livro livro){

    for(int i = 0; i < carrinho->tamanho; i++)
    {
        if(carrinho->livros[i].livroId == livro.livroId)
        {
            printf("Livro ja adicionado ao carrinho.\n");
            return;
        }
    }


    if(carrinho->tamanho >= carrinho->capacidade)
    {
        carrinho->capacidade += 5;
        carrinho->livros = (Livro *)realloc(carrinho->livros, carrinho->capacidade * sizeof(Livro));
        if(carrinho->livros == NULL){
            printf("Erro ao alocar memoria para adicionar livro.\n");
            exit(1);
        }
    }

    carrinho->livros[carrinho->tamanho] = livro;
    carrinho->tamanho++;
}


Livro buscaLivro(int id)
{
    FILE *ptrArquivo;
    Livro livro;

    int achado = 0;

    ptrArquivo = fopen("catalogo.txt", "r");

    if (ptrArquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    else
    {
        while (fread(&livro, sizeof(livro), 1, ptrArquivo) == 1)
        {
            if (livro.livroId == id)
            {
                fclose(ptrArquivo);
                achado = 1;
                return livro;
            }
        }
    }

    if (!achado)
    {
        printf("Livro nao encontrado.\n");
        fclose(ptrArquivo);
        livro.livroId = -1;
    }
    return livro;
}

int carrinhoDeCompras(Usuario *ptrUsuario)
{
    Carrinho *carrinho;
    Livro livro;

    printf("=== Carrinho de compras ===\n");
    inicializarCarrinho(&carrinho); // Modificado para passar o ponteiro corretamente

    char escolha;
    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar livro ao carrinho\n");
        printf("2. Remover livro do carrinho\n");
        printf("3. Exibir carrinho\n");
        printf("4. Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
        {
            case 1:
            {
                int id;
                printf("Digite o ID do livro que voce deseja adicionar ao carrinho: ");
                scanf("%d", &id);
                limpaBuffer();

                livro = buscaLivro(id);

                if (livro.livroId == -1)
                {
                    printf("Livro nao encontrado!\n");
                    continue;
                }

                printf("Deseja adicionar o livro: %s ao carrinho? (s/n): ", livro.titulo);
                scanf("%c", &escolha);
                limpaBuffer();

                if (escolha == 's')
                {
                    adicionarLivro(carrinho, livro);
                }
                else
                {
                    printf("Livro nao adicionado ao carrinho.\n");
                }
                break;
            }
            case 2:
            {
                int id;
                printf("Digite o ID do livro que deseja remover do carrinho: ");
                scanf("%d", &id);
                limpaBuffer();

                removerLivro(carrinho, id);
                break;
            }
            case 3:
                exibirCarrinho(carrinho);
                break;

            case 4:
                char senha[255];
                int retorno;

                printf("Finalizando compra...\n");
                printf("Digite sua senha: ");
                fgets(senha, sizeof(senha), stdin);
                strcpy(ptrUsuario->senha, senha);
                retorno = verificarSenha(ptrUsuario);

                if (retorno)
                {
                    gerarHistorico(carrinho, ptrUsuario);
                    apagaCarrinho(carrinho);
                }
                else
                {
                    printf("Senha incorreta.\n");
                }
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}