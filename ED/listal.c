// Implementa lista ligada

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;


void insereNo(NoListaLigada **lista, int carga){
    NoListaLigada *novoNo;
    NoListaLigada *aux;

    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);   
    }
    novoNo->numero = carga;
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

void insereNoInicio(NoListaLigada **lista, int carga) {
    NoListaLigada *novoNo;

    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);   
    }
    novoNo->numero = carga;
    novoNo->proximo=NULL;
    if( *lista==NULL )
        *lista = novoNo;   
    else {
        novoNo->proximo = *lista;
        *lista = novoNo;
    }

}

void imprimeLLvelho(NoListaLigada *lista){
    NoListaLigada *aux;

    aux = lista;
    while(aux!=NULL){
        printf("%d\n", aux->numero);
        aux= aux->proximo;
    }
}

void imprimeLL(NoListaLigada *lista){
    if(lista == NULL) return;  
    printf("%d\n", lista->numero);
    imprimeLL( lista->proximo);
}

int main() {

    NoListaLigada *registro=NULL;

    insereNoInicio( &registro, 10 );
    insereNoInicio( &registro, 9 );
    insereNoInicio( &registro, 8 );
    
    insereNo( &registro, 11 );
    insereNo( &registro, 12 );
    insereNo( &registro, 13 );

    imprimeLL(registro);

}