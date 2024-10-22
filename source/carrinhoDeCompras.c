#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void inicializarCarrinho(Carrinho *carrinho){

    carrinho->capacidade = 10;
    carrinho->tamanho = 0;

    carrinho->livros = (Livro *)malloc(carrinho->capacidade * sizeof(Livro));
    if(carrinho->livros == NULL){
        printf("Erro ao alocar memoria na criacao do carrinho.\n");
        exit(1);
    }
}

void adicionarLivro(Carrinho *carrinho, Livro livro){

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

void removerLivro(Carrinho *carrinho, size_t id){

    for(int i = 0; i < carrinho->tamanho; i++){
        //procura o item pelo id
        if(carrinho->livros[i].livroId == id)
        {
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
}

void exibirCarrinho(Carrinho *carrinho)
{
    float total = 0.0;

    printf("===Seu carrinho atual===\n");
    for(int i = 0; i < carrinho->tamanho; i++)
    {
        printf("ID: %d\n", carrinho->livros[i].livroId);
        printf("Titulo: %s", carrinho->livros[i].titulo);
        printf("Autor: %s", carrinho->livros[i].autor);
        printf("Editora: %s", carrinho->livros[i].editora);
        printf("Ano: %d\n", carrinho->livros[i].ano);
        printf("Preco: %.2f\n", carrinho->livros[i].preco);
        printf("Status: %d\n", carrinho->livros[i].status);
        printf("\n");
        total += carrinho->livros[i].preco;
    }
    printf("Total: %.2f\n", total);
    printf("Voce tem %lu livros no carrinho.\n", carrinho->tamanho);
    printf("===Fim do carrinho===\n");
}

void apagaCarrinho(Carrinho *carrinho){

    free(carrinho->livros);
    //Boas práticas p/ evitar erros de memória
    carrinho->livros = NULL;
    carrinho->capacidade = 0;
    carrinho->tamanho = 0;

}


/*int carrinhoDeCompras(Usuario *ptrUsuario){


    Carrinho *carrinho;
    Livro livro;

}*/
