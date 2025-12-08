// 
// Cria arquivo hash para coluna Nome do Cadastro
//
// Paulo Bandiera Paiva
// 08/12/2025
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arqutil.h"

#define TAMHASH 10000

int hash (char *v, int M) {
   int h = v[0];
   for (int i = 1; v[i] != '\0'; i++) 
      h = h * 256 + v[i];
   return h % M;
}


int main() {
    FILE *arq;
    Registro reg;
    char linha[MAXLIN];

    char *nomes;
    char *ptr;
    int contador,i;

    int hashes[TAMHASH];
    for(int j=0; j< TAMHASH;j++) hashes[j]=0;


    nomes = malloc(75000000);
    if(!nomes){
        printf("ERRO DE ALOCAÇÃO\n");
        exit(1);
    }

    // arq = fopen("/home/pub/ed/Cadastro.csv","r");
    arq = fopen("CadHead.csv","r");

    if(!arq ) {  // arq == NULL?
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }
    
    fgets(linha, MAXLIN, arq);
    contador = 0;

    while(!feof(arq)) {
        fgets(linha, MAXLIN, arq);
        reg = coleta(linha);
        if(contador) {
            for(i=contador-1;i>0;i--) {
                ptr = nomes+(i*100);
                if( ! strcmp( reg.nome, ptr ) ) break;
            }
        }
        else {
            i=0;
        }
        if(i==0) { //Nome único
            ptr = nomes+(contador*100);
            memcpy( ptr, reg.nome, 100 );
            contador++;
            // if(! (contador%10) ) printf("\r%d",contador);
        }
    }
    printf( "\n\n %d registros únicos\n", contador);

    for(i=0;i<contador;i++){
        ptr = nomes+(i*100);
        hashes[ hash(ptr, TAMHASH) ]++;
    }

    FILE *outfile;
    outfile=fopen("hashes.txt","w");
    if(!outfile){
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }
    for(i=0;i<TAMHASH;i++){
        fprintf(outfile, "%d\t%d\n", i, hashes[i]);
    }
    fclose(outfile);
}





