// Lendo dados de arquivo CSV Cadastro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"

int main(int argc, char **argv) {
    FILE *arq;
    Registro reg;
    char linha[MAXLIN];
    char query[100];

    if(argc<2) {  // Não passou parâmetros para  o programa
        printf("\nEntre com parte do nome do servidor: ");
        fgets(query, 100, stdin);
        }
    else {
        strcpy(query, argv[1]);
    }
    limpa(query);

    arq = fopen("/home/pub/ed/Cadastro.csv","r");
    if(!arq) {  // arq == NULL?
        printf("ERRO de abertura de arquivo.\n");
        exit(-1);
    }

    while(!feof(arq)) {
        fgets(linha, MAXLIN, arq);
        reg = coleta(linha);
        if( strstr(reg.nome, query) ) {
            imprimeReg(reg);
        }
    }
    


}