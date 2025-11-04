// Implementação de árvore binária

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int numero;
    struct no *fe;
    struct no *fd;
} No;

void insereNo(No **arv, int valor){
    No *novoNo=NULL;


    if(! *arv ) {     // arv é NULO
        novoNo = malloc( sizeof(No) );
        if(!novoNo) {
            printf("ERRO de alocação de memória");
            exit(-1);
        }
        novoNo->numero=valor;
        novoNo->fd=NULL;
        novoNo->fe=NULL;

        *arv = novoNo;
        return;
    }
    if( (*arv)->numero < valor ) {
        insereNo( &((*arv)->fd), valor );
    }
    else
    {
        insereNo( &((*arv)->fe), valor );
    }
    return;
}

void imprimeEmOrdem(No *arv) {
    if(!arv)
        return;
    imprimeEmOrdem(arv->fe);
    printf( "%d\n", arv->numero );
    imprimeEmOrdem(arv->fd);
}

void imprimeDesOrdem(No *arv) {
    if(!arv)
        return;
    imprimeDesOrdem(arv->fd);
    printf( "%d\n", arv->numero );
    imprimeDesOrdem(arv->fe);
}

void imprimePosOrdem(No *arv) {
    if(!arv)
        return;
    imprimePosOrdem(arv->fe);
    imprimePosOrdem(arv->fd);
    printf( "%d\n", arv->numero );
}

void imprimePreOrdem(No *arv) {
    if(!arv)
        return;
    printf( "%d\n", arv->numero );
    imprimePreOrdem(arv->fe);
    imprimePreOrdem(arv->fd);
}

int altura(No *arv) {
    int h=0;
    int he,hd;

    if( !arv ) return 0;
    if(!arv->fe && !arv->fd ) return 0; // não tem filhos
    if(arv->fe)
        he = altura(arv->fe);
     if(arv->fd)
        hd = altura(arv->fd);   
    if(he>hd) return he+1;
    return hd+1;
}

int main() {

    No *arvore = NULL;

    insereNo(&arvore, 5);
    insereNo(&arvore, 9);
    insereNo(&arvore, 15);
    insereNo(&arvore, 3);
    insereNo(&arvore, 2);
    insereNo(&arvore, 7);
    insereNo(&arvore, 4);
    insereNo(&arvore, 6);
    insereNo(&arvore, 10);
    insereNo(&arvore, 12);

    imprimeEmOrdem(arvore);
    printf("---PRE-ORDEM---\n");
    imprimePreOrdem(arvore);
    printf("---POS-ORDEM---\n");
    imprimePosOrdem(arvore);

    printf("Altura da árvore é %d\n", altura(arvore));

    return 0;
}