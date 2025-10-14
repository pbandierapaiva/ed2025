// Implementação das funções de acesso ao Cadastro CSV usando lista ligada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadlista.h"



void insereNo(ListaReg **lista, Registro reg){
    ListaReg *novoNo;
    ListaReg *aux;

    novoNo = malloc(sizeof(ListaReg));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);   
    }
    memcpy( &(novoNo->registro) , &reg, sizeof(Registro) );
    novoNo->proximo=NULL;

    if( *lista==NULL )
        *lista = novoNo;
    else {
        aux = *lista;
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo=novoNo;
    }
}

void imprimeLista(ListaReg *lista){
    if(lista==NULL) return;
    imprimeReg(lista->registro);
    imprimeLista(lista->proximo);
}

int encontraListaRegs(char *q, int tipo, ListaReg **listaregs) {
    FILE *arq;
    Registro reg;
    char linha[MAXLIN];
    int conta=0;

    arq = fopen("/home/pub/ed/Cadastro.csv","r");
    if(!arq) {  // arq == NULL?
        printf("ERRO de abertura de arquivo.\n");
        return -1;
    }

    while(!feof(arq)) {
        fgets(linha, MAXLIN, arq);
        reg = coleta(linha);
        if( (tipo==ORG && strstr(reg.org, q)) ||
            (tipo==UORG && strstr(reg.uorg, q)) ||
            (tipo==NOME && strstr(reg.nome, q)) ||
            (tipo==CARGO && strstr(reg.cargo, q))
            ) {
            conta++;
 
            insereNo(listaregs, reg);
        }
    }
    return conta;
}

int main(int argc, char **argv) {
    char query[100];
    int encontrados=0;

    ListaReg *listaRegistros=NULL;

    if(argc<2) {  // Não passou parâmetros para  o programa
        printf("\nEntre com parte da ORG desejada: ");
        fgets(query, 100, stdin);
        }
    else {
        strcpy(query, argv[1]);
    }
    limpa(query);

    encontraListaRegs( query,  ORG, &listaRegistros);
    imprimeLista(listaRegistros);
}