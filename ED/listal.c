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

void imprimeNo(NoListaLigada *no){
    if(!no) 
        printf("Nó Null\n");
    else
        printf("%d\n",no->numero);
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

void imprimeLLReversa(NoListaLigada *lista){
    if(lista == NULL) return;  
    imprimeLLReversa( lista->proximo);
    printf("%d\n", lista->numero);
}

NoListaLigada *encontraNo(NoListaLigada *lista, int q) {
    NoListaLigada *paux;

    paux = lista;
    while(paux) {     // paux != NULL
        if(paux->numero == q)
            return paux;
        paux = paux->proximo;
    }
    return NULL;
}

void removeNoPtr(NoListaLigada **lista, NoListaLigada *elemento) {
    NoListaLigada *paux;

    if(*lista == elemento){   //elemento é o primeiro da lista
        *lista = elemento->proximo;
        free(elemento);
        return;
    }
    paux = *lista;
    while( paux->proximo != elemento && paux!=NULL )  {
        paux = paux->proximo;
    }
    if(paux) {
        paux->proximo = elemento->proximo;
        free(elemento);
    }
}

void removeNo(NoListaLigada **lista, int q) {
    removeNoPtr( lista, encontraNo( *lista, q));
}

NoListaLigada *noAnterior(NoListaLigada *lista, NoListaLigada *no) {
    NoListaLigada *paux;

    if(no==lista) return NULL;
    paux = lista;
    while(paux->proximo!=no && paux->proximo!=NULL)
        paux = paux->proximo;
    if(paux->proximo==no) return paux;
    return NULL;
}


int main() {
    NoListaLigada *noAux;

    NoListaLigada *registro=NULL;

    insereNoInicio( &registro, 10 );
    insereNoInicio( &registro, 9 );
    insereNoInicio( &registro, 8 );
    
    insereNo( &registro, 99 );
   
    insereNo( &registro, 11 );
    insereNo( &registro, 12 );
    insereNo( &registro, 13 );

    removeNo( &registro, 99 );

    imprimeLLReversa( registro );

    printf("\nEncontrando nó anterior ao '12'\n");
    noAux = noAnterior(registro, encontraNo(registro,12) );

    imprimeNo(noAux);


}