// 
// Lê arquivo CSV e cria arquivo com tamanho fixo de registro
//
// Para compilar você deve incluir o arquivo "arqutil.c"
//
// Paulo Bandiera Paiva
// 07/10/2025
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arqutil.h"

int main() {
    FILE *arq, *arqsai;
    Registro reg;
    char linha[MAXLIN];

    arq = fopen("/home/pub/ed/Cadastro.csv","r");
    arqsai = fopen("/tmp/CadEstruturado.db","w");

    if(!arq || !arqsai) {  // arq == NULL?
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }
        
    fgets(linha, MAXLIN, arq);

    while(!feof(arq)) {
        fgets(linha, MAXLIN, arq);
        reg = coleta(linha);
        fwrite(&reg, sizeof(Registro), 1, arqsai);
    }

}