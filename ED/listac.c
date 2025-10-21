// Implementa lista duplamente ligada

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
} listaCircular;


void insereNo(listaCircular **lista, int carga){
    listaCircular *novoNo=NULL;

    novoNo = malloc(sizeof(listaCircular));
    if(!novoNo) {
        printf("ERRO de alocação de memória.\n");
        exit(-1);
    }

    novoNo->numero = carga;
    novoNo->anterior = novoNo;
    novoNo->proximo = novoNo;

    if( *lista==NULL )
        *lista=novoNo;
    else {
        novoNo->proximo = *lista;
        novoNo->anterior= (*lista)->anterior;
        (*lista)->anterior = novoNo;
        *lista=novoNo;
    }
}

void removeNoPtr(listaCircular **lista, listaCircular *elemento) {
    listaCircular *paux;

    if(*lista == elemento){   // elemento é o primeiro da lista
        *lista = elemento->proximo;
        (*lista)->anterior = elemento->anterior;
        free(elemento);
        return;
    }
    paux = *lista;
    while( paux->proximo != elemento && paux->proximo!=*lista )  {
        paux = paux->proximo;
    }
    if(paux->proximo==elemento) {
        paux->proximo = elemento->proximo;
        paux->proximo->anterior = paux;
        free(elemento);
    }
}

listaCircular *encontraNo(listaCircular *lista, int q) {
    listaCircular *ptr;

    if(!lista) return NULL;
    if(lista->numero==q) return lista;
    ptr = lista->proximo;
    while(ptr!=lista) {     // lista != NULL
        if(ptr->numero == q)
            return ptr;
        ptr = ptr->proximo;
    }
    return NULL;
}

void removeNo(listaCircular **lista, int q) {
    removeNoPtr( lista, encontraNo( *lista, q));
}

listaCircular *ultimoNo(listaCircular *lista) {
    if(!lista) return NULL;
    while(lista->proximo)
        lista = lista->proximo;
    return lista;
}

void imprime(listaCircular *lista) {
    listaCircular *ptr;

    if(!lista) return;
    if(lista->proximo==lista) {
        printf("%d\n", lista->numero);
        return;
    }
    ptr = lista;
    while(ptr->proximo!=lista) {
        printf("%d\n", ptr->numero);
        ptr = ptr->proximo;
    }
}

void imprimeReverso(listaCircular *lista) {
    listaCircular *ptr;

    ptr = ultimoNo(lista);
    while(ptr) {
        printf("%d\n", ptr->numero);
        ptr = ptr->anterior;
    }
}
listaCircular *noAnterior(listaCircular *no){
    return no->anterior;
}



int main() {
    listaCircular *listaDL=NULL;

    insereNo( &listaDL, 99 );
    insereNo( &listaDL, 11 );
    insereNo( &listaDL, 12 );
    insereNo( &listaDL, 13 );

    removeNo(&listaDL, 99);

    imprime(listaDL);
}



