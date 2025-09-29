// manipulação de arquivos em C 
// contando campos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIN 900

int contapv(char *s){
    int conta=0;

    while(*s!='\0'){
        if(*s==';') conta++;
        s++;
    }
    return conta;
}

int main() {
    FILE *arq;
    char linha[MAXLIN];
    int maxcpos=0;
    long int pos, maxpos;

    arq = fopen("CadLimpo.csv","r");

    while(!feof(arq)){
        pos = ftell(arq);
        fgets(linha, MAXLIN, arq);
        if( contapv(linha)>maxcpos ){
            maxcpos = contapv(linha);
            maxpos = pos;
            printf("Número máximo de campos %d\n",maxcpos);
        }
    }
    fseek(arq, maxpos,SEEK_SET);
    fgets(linha, MAXLIN, arq);
    printf("\n%s\n", linha);
    fclose(arq);
}


