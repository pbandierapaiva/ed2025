// 
// Lê arquivo CSV e monta lista de registro de ORG especificada
//
// Paulo Bandiera Paiva
// 06/10/2025
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"

int main(int argc, char **argv) {
    char query[100];
    int encontrados=0;

    Registro *listaRegistros;

    if(argc<2) {  // Não passou parâmetros para  o programa
        printf("\nEntre com parte da ORG desejada: ");
        fgets(query, 100, stdin);
        }
    else {
        strcpy(query, argv[1]);
    }
    limpa(query);

    encontrados = encontraRegs(query, ORG, &listaRegistros);

    printf("\n%d Registros encontrados\n", encontrados);

    imprimeVetorRegs(listaRegistros, encontrados);

}
    