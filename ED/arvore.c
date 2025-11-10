// Implementação de árvore binária

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int numero;
    struct no *pai;
    struct no *fe;
    struct no *fd;
} No;

No *criaNo(No *pai, int val) {
    No *novoNo=NULL;

    novoNo = malloc( sizeof(No) );
    if(!novoNo) {
        printf("ERRO de alocação de memória");
        exit(-1);
    }
    novoNo->numero=val;
    novoNo->pai=pai;
    novoNo->fd=NULL;
    novoNo->fe=NULL;
    return novoNo;
}

void insereNo(No **arv, int valor){
    if(! *arv ) {     // arv é NULO
        *arv = criaNo(NULL, valor);
        return;
    }
    if( (*arv)->numero < valor ) {
        if( (*arv)->fd )
            insereNo( &((*arv)->fd), valor );
        else  // fd é NULL
            (*arv)->fd = criaNo(*arv,valor);
    }
    else
    {
        if( (*arv)->fe )
            insereNo( &((*arv)->fe), valor );
        else  // fe é NULL
            (*arv)->fe = criaNo(*arv,valor);
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
    int he,hd;

    if( !arv ) return -1;
    he = altura(arv->fe);
    hd = altura(arv->fd);   
    if(he>hd) return he+1;
    return hd+1;
}

int profundidade(No *arv) {
    if(arv==NULL) return -1;
    return 1+profundidade(arv->pai);
}

No *proximo(No *meuno) {
    No *paux;

    if(meuno->fd==NULL) {
        if( meuno->pai == NULL ) //é a raiz
            return NULL;
        if(meuno->pai->fe==meuno)
            return meuno->pai;
        return meuno->pai->pai;
    }
    // tem filho direito meuno->fd != NULL
    if( meuno->fd->fe==NULL )
        return meuno->fd;
    paux = meuno->fd->fe;
    while(paux->fe!=NULL)
        paux = paux->fe;
    return paux;
}

No *removeRaiz( No *raiz ) {
    No *p, *q;

    if( ! raiz->fe ) {// Filho à esquerda é NULL
        q = raiz->fd;
        q->pai = raiz->pai;
    }
    else {
        p = raiz;
        q = raiz->fe;
        while( q->fd ) {  // q->fd não é NULL
            p=q;
            q=q->fd;    
        }
        if( p != raiz ) {
            p->fd = q->fe;
            q->fe = raiz->fe;
        }
        q->pai = raiz->pai;
        q->fd = raiz->fd;
    }
    free(raiz);
    return q;
}

No *removeNo( No *no ) {
    No *p;

    if( no->pai==NULL)   // É RAIZ
        return removeRaiz( no );
    p = no->pai;
    if( p->fe == no )
        p->fe = removeRaiz( no );
    else
        p->fd = removeRaiz( no );
    while( p->pai )
        p = p->pai;
    return p;
}


int main() {

    No *arvore = NULL;
    No *p;

    insereNo(&arvore, 10);
    insereNo(&arvore, 20);
    insereNo(&arvore, 30);
    insereNo(&arvore, 4);
    insereNo(&arvore, 5);
    insereNo(&arvore, 6);
    insereNo(&arvore, 7);
    insereNo(&arvore, 8);
    insereNo(&arvore, 9);
    insereNo(&arvore, 11);
    insereNo(&arvore, 12);
    insereNo(&arvore, 13);
    insereNo(&arvore, 14);
    insereNo(&arvore, 15);
    insereNo(&arvore, 16);
    insereNo(&arvore, 17);
    insereNo(&arvore, 18);
    insereNo(&arvore, 19);
    insereNo(&arvore, 21);
    insereNo(&arvore, 22);
    insereNo(&arvore, 23);
    insereNo(&arvore, 24);
    insereNo(&arvore, 25);
    insereNo(&arvore, 26);
    insereNo(&arvore, 27);
    insereNo(&arvore, 28);


    printf("Removendo %d\n",arvore->fd->numero);
    arvore = removeNo(arvore->fd);


    printf("Removendo %d\n",arvore->numero);
    arvore = removeNo(arvore);
    
    
    printf("Removendo %d\n",arvore->fe->fd->numero);
    arvore = removeNo(arvore->fe->fd);

    imprimeEmOrdem(arvore);
    // printf("---PRE-ORDEM---\n");
    // imprimePreOrdem(arvore);
    // printf("---POS-ORDEM---\n");
    // imprimePosOrdem(arvore);

    printf("Altura da árvore é %d\n", altura(arvore));

    p = proximo(arvore);
    printf("o próximo da raiz tem valor %d\n", p->numero);
    return 0;
}