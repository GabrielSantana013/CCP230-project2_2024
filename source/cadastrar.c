#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes.h"


int verificarCadastro(Usuario *ptrUsuario){

    FILE *ptrArquivo = fopen("clientes.bin", "rb");
    Usuario usuario;

    if(ptrArquivo == NULL)
    {
        return 0;
    }
    else
    {
        while(fread(&usuario, sizeof(usuario), 1, ptrArquivo) == 1)
        {
            if(strcmp(usuario.CPF, ptrUsuario->CPF) == 0)
            {
                printf("CPF ja cadastrado\n");
                fclose(ptrArquivo);
                return 1;
            }
        }
    }
    fclose(ptrArquivo);
    return 0;

}

int validarCPF(Usuario *ptrUsuario){

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
            printf("CPF Invalido\n");
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
            printf("O CPF deve conter apenas valores numericos\n");
            continue;
        }

    } while(tamanhoCPF != 12 || !numerico);

    CPF[tamanhoCPF-1] = '\0';
    strcpy(ptrUsuario->CPF, CPF);

    return 0;
}

int cadastrar(Usuario *ptrUsuario){

    FILE *ptrArquivo;
    int retorno;

    printf("\nFuncao cadastrar\n");

    printf("Digite seu nome:\n");
    fgets(ptrUsuario->nome, sizeof(ptrUsuario->nome), stdin);

    validarCPF(ptrUsuario);
    retorno = verificarCadastro(ptrUsuario);

    if(retorno){return 1;} //usuario já cadastrado

    printf("Digite sua senha:\n");
    fgets(ptrUsuario->senha, sizeof(ptrUsuario->senha), stdin);

    ptrArquivo = fopen("clientes.bin", "ab+");

    if(ptrArquivo == NULL)
    {
        ptrArquivo = fopen("clientes.bin", "ab+");
    }
    
    ptrUsuario->qttLivrosAlugados = 0;
    ptrUsuario->qttLivrosComprados = 0;
    
    fwrite(ptrUsuario, sizeof(Usuario), 1, ptrArquivo);
    
    fclose(ptrArquivo);

    return 0; //nenhum erro ao cadastrar

}