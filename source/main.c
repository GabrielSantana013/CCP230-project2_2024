#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){

    int menu;
    menu = exibirMenuVisitante();

    if (menu == 2){ // Condição para teste
        menu = exibirMenuAdm();
    }
    
    return 0;
}