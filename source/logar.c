#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int logar(Usuario *ptrUsuario){

    FILE *ptrArquivo;
    Usuario usuario;

    printf("\nFuncao logar\n");

    ptrArquivo = fopen("clientes.bin", "rb");
    if(ptrArquivo == NULL)
    {
        printf("Nenhum usuario cadastrado\n");
        return 1;
    }
    else
    {
        limpaBuffer();
        verificarCPF(ptrUsuario);

        printf("Digite sua senha: \n");
        fgets(ptrUsuario->senha, sizeof(ptrUsuario->senha), stdin);

        while(fread(&usuario, sizeof(usuario), 1, ptrArquivo) == 1)
        {
            if(strcmp(usuario.CPF, ptrUsuario->CPF) == 0 && strcmp(usuario.senha, ptrUsuario->senha) == 0)
            {
                printf("Logado com sucesso\n");
                fclose(ptrArquivo);
                return 2;
            }
        }
    }
    fclose(ptrArquivo);
    return 0;
}