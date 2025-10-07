// 
// Cria arquivo índice baseado no campo ORG
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
    RegIndOrg regind;
    int contador = 0;

    arq = fopen("/home/pub/ed/CadEstruturado.db","r");
    arqsai = fopen("/tmp/indiceOrg.db","w");

    if(!arq || !arqsai) {  // arq == NULL?
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }
        

    while(!feof(arq)) {
        fread( &reg, sizeof(Registro),1, arq);
        strcpy(regind.org, reg.org);
        regind.indice=contador;
        contador++;
        fwrite(&regind, sizeof(RegIndOrg), 1, arqsai);
    }

}
