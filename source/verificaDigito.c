#include <stdio.h>
#include <stdlib.h>

int verificaDigito(char *entrada){
    int resultado;

    // Lê a entrada como string
    if (entrada != NULL) {
        // Tenta converter para inteiro
        if (sscanf(entrada, "%d", &resultado) != 1) {
            // Caso falhe, 'resultado' se torna 0
            resultado = 0;
        }
    } else {
        // Erro de entrada
        resultado = 0;
    }

    return resultado;
}