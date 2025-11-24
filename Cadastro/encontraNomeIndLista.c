// 
//Encontra nome em arquivo CSV de Servidores que está indexado através de uma lista ligada
//
// Para compilar você deve incluir o arquivo "arqutil.c"
//
// Paulo Bandiera Paiva
// 06/10/2025
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "arqutil.h"

#define ARQUIVOCSV  "/home/pub/ed/Cadastro.csv"

void insere(ListaRegNome **lista, RegIndNome registro) {
    ListaRegNome *novo;

    novo = malloc(sizeof(ListaRegNome));
    if(!novo){
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA\n\n");
        exit(-1);
    }
    strcpy( novo->registro.nome, registro.nome );
    novo->registro.localiza = registro.localiza;

    novo->proximo = *lista;
    *lista = novo;
}

void pegaRegistroCSV( char *arqcsv, long int loc) {
    FILE *arq;
    char linha[MAXLIN];
    Registro reg;

    arq = fopen(arqcsv,"r");
    if(!arq) {  // arq == NULL?
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }

    fseek( arq, loc, 0);
    fgets(linha, MAXLIN, arq);
    reg = coleta(linha);

    imprimeReg(reg);
}

void busca(ListaRegNome *lista, char *q){
    
    if(!lista) return;
    while( strstr( lista->registro.nome, q)==NULL ){
        if(lista->proximo==NULL) return; 
        lista = lista->proximo;
    }

    if(lista) {
        pegaRegistroCSV( ARQUIVOCSV, lista->registro.localiza);
    }
}

int main() {
    // Cronometro
    clock_t start, end;

    //
    char nomeq[100];
    
    // Lê arquivo CSV e cria indice em lista
    FILE *arq;
    Registro reg;
    RegIndNome regind;
    ListaRegNome *listanomes;
    char linha[MAXLIN];

    start = clock();
    arq = fopen(ARQUIVOCSV,"r");
    if(!arq) {  // arq == NULL?
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }
    
    while(!feof(arq)) {
        regind.localiza=ftell(arq);
        fgets(linha, MAXLIN, arq);
        reg = coleta(linha);
        strcpy(regind.nome, reg.nome);
        insere(&listanomes, regind);
    }
    end = clock();
    fclose(arq);
    printf("Arquivo lido e indexado em lista ligada! (Tempo %f s)\n", 
                        ((double)(end - start)) / CLOCKS_PER_SEC);

    printf("\nEntre com parte do nome a ser pesquisado: ");
    fgets(nomeq,100,stdin);
    limpa(nomeq);

    printf("Nome entrado: %s\n", nomeq);

    start = clock();
    busca(listanomes,nomeq);
    end = clock();
    printf("Tempo de execução: %f\n\n", ((double)(end - start)) / CLOCKS_PER_SEC );

}