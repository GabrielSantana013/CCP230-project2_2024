#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes.h"

int verificarSenha(Usuario *ptrUsuario){

    FILE *ptrArquivo = fopen("clientes.bin", "rb");
    Usuario usuario;

    if(ptrArquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    while(fread(&usuario, sizeof(usuario), 1, ptrArquivo) == 1)
    {
        if(strcmp(usuario.senha, ptrUsuario->senha) == 0 && strcmp(usuario.CPF, ptrUsuario->CPF) == 0)
        {
            fclose(ptrArquivo);
            return 1;
        }
    }

    fclose(ptrArquivo);
    return 0;

}

int verificarCadastro(Usuario *ptrUsuario){

    FILE *ptrArquivo = fopen("clientes.bin", "rb");
    Usuario usuario;

    if(ptrArquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    while(fread(&usuario, sizeof(usuario), 1, ptrArquivo) == 1)
    {
        if(strcmp(usuario.CPF, ptrUsuario->CPF) == 0)
        {
            fclose(ptrArquivo);
            return 1;
        }
    }

    fclose(ptrArquivo);
    return 0;

}

int verificarCPF(Usuario *ptrUsuario){

    char CPF[255];
    size_t tamanhoCPF;
    int numerico = 1;

    do
    {
        printf("Digite seu CPF:\n");
        fgets(CPF, sizeof(CPF), stdin);
        tamanhoCPF = strlen(CPF);

        if(tamanhoCPF <12 || tamanhoCPF > 13)
        {
            printf("CPF invalido.\n");
        }

        numerico = 1;
        for(int i = 0; i <tamanhoCPF-1; i++)
        {
            if(!isdigit(CPF[i]))
            {
                numerico = 0;
                break;
            }
        }
        if(!numerico)
        {
            printf("O CPF deve conter apenas valores numericos.\n\n");
            continue;
        }

        printf("\n");
    } while(tamanhoCPF != 12 || !numerico);

    CPF[tamanhoCPF-1] = '\0';
    strcpy(ptrUsuario->CPF, CPF);

    return 0;
}

int cadastrarUsuario(Usuario *ptrUsuario){

    FILE *ptrArquivo;
    int retorno;

    printf("\n===CADASTRAR NOVO USUARIO===\n");
    
    verificarCPF(ptrUsuario);
    retorno = verificarCadastro(ptrUsuario);

    if(retorno){
        printf("CPF ja cadastrado\n");
        return 1;
    } //usuario já cadastrado

    printf("Digite seu nome:\n");
    fgets(ptrUsuario->nome, sizeof(ptrUsuario->nome), stdin);

    printf("\nDigite sua senha:\n");
    fgets(ptrUsuario->senha, sizeof(ptrUsuario->senha), stdin);

    ptrArquivo = fopen("clientes.bin", "ab+");
    fwrite(ptrUsuario, sizeof(Usuario), 1, ptrArquivo);
    
    fclose(ptrArquivo);

    return 0; //nenhum erro ao cadastrar

}