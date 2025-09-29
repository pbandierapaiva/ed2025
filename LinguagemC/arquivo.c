// demo de manipulação de arquivos em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIN 900

int main() {

    FILE *arq;

    char linha[MAXLIN];
    int contalinhas=0;
    long int tamanhoMaximo=0;

    long int posicao, posicaoMax=0;

    arq = fopen("/home/pub/ed/Cadastro.csv","r");

    if(!arq) {  // arq == NULL?
        printf("ERRO de abertura de arquivo.\n");
        exit(-1);
    }


    while(!feof(arq)){
        posicao = ftell(arq);
        fgets(linha, MAXLIN, arq);
        if( strlen(linha)>tamanhoMaximo ) {
            tamanhoMaximo=strlen(linha);
            posicaoMax = posicao;
        }
        contalinhas++;
        printf("%ld\n", posicao);
    }

    fseek(arq, posicaoMax, SEEK_SET);
    fgets(linha, MAXLIN, arq);
    printf("\n%s\n", linha);

    printf("O arquivo tem %d linhas\n", contalinhas);
    printf("O tamanho máximo de linha é %ld\n", tamanhoMaximo);

    fclose(arq);

}