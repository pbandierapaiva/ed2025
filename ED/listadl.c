// Implementa lista duplamente ligada

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
} noListaDL;


void insereNo(noListaDL **lista, int carga){
    noListaDL *novoNo=NULL;

    novoNo = malloc(sizeof(noListaDL));
    if(!novoNo) {
        printf("ERRO de alocação de memória.\n");
        exit(-1);
    }

    novoNo->numero = carga;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if( *lista==NULL )
        *lista=novoNo;
    else {
        novoNo->proximo = *lista;
        (*lista)->anterior = novoNo;
        *lista=novoNo;
    }
}

void removeNoPtr(noListaDL **lista, noListaDL *elemento) {
    noListaDL *paux;

    if(*lista == elemento){   // elemento é o primeiro da lista
        *lista = elemento->proximo;
        (*lista)->anterior = NULL;
        free(elemento);
        return;
    }
    paux = *lista;
    while( paux->proximo != elemento && paux!=NULL )  {
        paux = paux->proximo;
    }
    if(paux) {
        paux->proximo = elemento->proximo;
        if(paux->proximo)
            paux->proximo->anterior = paux;
        free(elemento);
    }
}

noListaDL *encontraNo(noListaDL *lista, int q) {
    while(lista) {     // paux != NULL
        if(lista->numero == q)
            return lista;
        lista = lista->proximo;
    }
    return NULL;
}

void removeNo(noListaDL **lista, int q) {
    removeNoPtr( lista, encontraNo( *lista, q));
}

noListaDL *ultimoNo(noListaDL *lista) {
    if(!lista) return NULL;
    while(lista->proximo)
        lista = lista->proximo;
    return lista;
}

void imprime(noListaDL *lista) {
    while(lista) {
        printf("%d\n", lista->numero);
        lista = lista->proximo;
    }
}

void imprimeReverso(noListaDL *lista) {
    noListaDL *ptr;

    ptr = ultimoNo(lista);
    while(ptr) {
        printf("%d\n", ptr->numero);
        ptr = ptr->anterior;
    }
}
noListaDL *noAnterior(noListaDL *no){
    return no->anterior;
}



int main() {
    noListaDL *listaDL=NULL;

    insereNo( &listaDL, 99 );
    insereNo( &listaDL, 11 );
    insereNo( &listaDL, 12 );
    insereNo( &listaDL, 13 );

    removeNo(&listaDL, 99);

    imprime(listaDL);

    imprimeReverso(listaDL);
}



