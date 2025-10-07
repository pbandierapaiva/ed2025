// 
// Encontra em arquivo Estruturado USANDO ÍNDICE e monta lista de registro de ORG especificada, alocando memória dinamicamente
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

int main(int argc, char **argv) {
    char query[100];
    int encontrados=0;

    Registro *listaRegistros;

    // DEFINIÇÃO DO query
    if(argc<2) {  // Não passou parâmetros para  o programa
        printf("\nEntre com parte da ORG desejada: ");
        fgets(query, 100, stdin);
        }
    else {
        strcpy(query, argv[1]);
    }
    limpa(query);


    encontrados = encontraRegsIndiceOrg(query, &listaRegistros);

    // imprimeVetorRegs(listaRegistros, encontrados);
    printf("\n%d Registros encontrados\n", encontrados);
}
    
