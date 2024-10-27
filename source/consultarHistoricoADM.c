#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int consultarHistoricoADM() {
  FILE *ptrArquivo;
  Historico historico;
  int head = 0;
  char cpf[12];

  printf("Digite o CPF: ");
  scanf("%11s", cpf);
  limpaBuffer();
  cpf[11] = '\0';

  // Verifica se o CPF é do administrador
  if (strcmp(cpf, "12312312312") == 0) {
    printf("O administrador nao possui historico.\n");
    return 1;
  }

  ptrArquivo = fopen("historico.bin", "rb+");
  if (ptrArquivo == NULL) {
    printf("Nao ha nenhum historico a ser consultado.\n");
    return 1;
  } else {
    // Flag para verificar se algum histórico foi encontrado
    int found = 0;

    while (fread(&historico, sizeof(historico), 1, ptrArquivo) == 1) {
      // Verifica se o CPF do histórico corresponde ao CPF fornecido
      if (strcmp(historico.CPF, cpf) == 0) {
        if (!head) {
          printf("-------------------------------------------------------------"
                 "-----------------------------------------------\n");
          printf("| CPF: %s  | Nome: %s\n", historico.CPF, historico.nome);
          printf("-------------------------------------------------------------"
                 "-----------------------------------------------\n");
          printf("|       Data        |            Titulo            |      "
                 "Autor      |     Editora     | Tipo de Transacao |\n");
          printf("-------------------------------------------------------------"
                 "-----------------------------------------------\n");
          head = 1; // Define que o cabeçalho foi impresso
        }

        // Exibe os dados do histórico correspondente
        printf("| %10s | %-28s | %-15s | %-15s | %-17s |\n", historico.data,
               historico.titulo, historico.autor, historico.editora,
               historico.tipo);
        found = 1; // Indica que pelo menos um registro foi encontrado
      }
    }

    if (!found) {
      printf("Nenhum historico encontrado para o CPF: %s\n", cpf);
    }

    printf("-------------------------------------------------------------------"
           "-------------------------------------------------\n");
  }

  fclose(ptrArquivo);
  return 0;
}
