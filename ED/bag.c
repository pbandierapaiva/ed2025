// Implementa uma EAD "saco" ou bag

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;

// Exemplo se fosse o caso de uma "Bag of Words"
typedef struct bow {
    char palavra[50];
    int conta=0;
    struct bow *proximo;
} BoW;
///////////////////////////////////////////////////

void insereNo(NoListaLigada **lista, int carga) {
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

int tamanhoBag(NoListaLigada *lista) {
    int contador = 0;

    while(lista){
        contador++;
        lista= lista->proximo;
    }
    return contador;
}

int sorteiaNum(NoListaLigada *sacola) {
    return random()%tamanhoBag(sacola);
}

int pegaItem(NoListaLigada **sacola, int *resultado){
    int item;
    NoListaLigada *ptr;

    if( *sacola==NULL ) { // sacola vazia
        return 0;
    }
    item= sorteiaNum(*sacola);
    ptr = *sacola;
    for(int i=0; i<item; i++) ptr = ptr->proximo;
    *resultado = ptr->numero;
    removeNoPtr(sacola, ptr);
    return 1;
}

int main() {
    NoListaLigada *bag=NULL;
    int valitem;

    // gera semente de número aleatório
    srandom(time(NULL));

    for(int i=0; i<20;i++)
        insereNo( &bag, i );

    printf("Tamanho da sacola: %d\n", tamanhoBag(bag));

    while( pegaItem(&bag, &valitem) )
        printf("Sorteado: %d\n", valitem);

}