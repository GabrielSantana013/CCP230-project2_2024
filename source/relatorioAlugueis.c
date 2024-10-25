#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int relatorioAlugueis(){
    FILE *ptrArquivo;
    Historico historico;
    ptrArquivo = fopen("historico.bin", "rb");
    if(ptrArquivo == NULL){
        printf("Nao ha nenhum registro de aluguel.\n");
        return 1;
    }
    else{
        printf("%-15s %-20s %-12s %-20s %-20s %-10s\n", 
               "CPF", "Nome", "Data", "Titulo", "Autor", "Tipo de transação");
        printf("----------------------------------------------------------------------------------------------------\n");
        while(fread(&historico, sizeof(historico), 1, ptrArquivo)){
            printf("%-15s %-20s %-12s %-20s %-20s %-17s\n", 
                   historico.CPF, historico.nome, historico.data, 
                   historico.titulo, historico.autor, historico.tipo);
        }
    }
    fclose(ptrArquivo);
    return 0;
}