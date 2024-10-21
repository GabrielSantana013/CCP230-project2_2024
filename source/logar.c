#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int logar(Usuario *ptrUsuario)
{

    FILE *ptrArquivo;
    Usuario usuario;

    printf("\n===FAÇA LOGIN===\n");

    ptrArquivo = fopen("clientes.bin", "rb");
    if (ptrArquivo == NULL)
    {
        printf("Nenhum usuario cadastrado.\n");
        return 1;
    }
    else
    {
        verificarCPF(ptrUsuario);

        printf("Digite sua senha: \n");
        fgets(ptrUsuario->senha, sizeof(ptrUsuario->senha), stdin);

        while (fread(&usuario, sizeof(usuario), 1, ptrArquivo) == 1)
        {
            if (strcmp(usuario.CPF, ptrUsuario->CPF) == 0 &&
                strcmp(usuario.senha, ptrUsuario->senha) == 0 &&
                strcmp(usuario.nome, "admin\n") == 0)
            {
                printf("Logado com sucesso!\n");
                fclose(ptrArquivo);
                return 3;
            }
            else if (strcmp(usuario.CPF, ptrUsuario->CPF) == 0 &&
                     strcmp(usuario.senha, ptrUsuario->senha) == 0)
            {
                printf("Logado com sucesso!\n");

                //passar os dados do usuario para o ponteiro
                strcpy(ptrUsuario->nome, usuario.nome);
                ptrUsuario->qttLivrosAlugados = usuario.qttLivrosAlugados;
                ptrUsuario->qttLivrosComprados = usuario.qttLivrosComprados;
                
                fclose(ptrArquivo);
                return 2;
            }
        }
        printf("Usuario ou senha incorretos.\n");
    }
    fclose(ptrArquivo);
    return 0;
}