// Implementação de árvore binária

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int numero;
    struct no *pai;
    struct no *fe;
    struct no *fd;
} No;

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

int fb(No *nodo) {
    return altura(nodo->fd) - altura(nodo->fe);
}

No *avl(No *nodo) {
    int fbn;
    No *p;

    fbn = fb(nodo);
    if( fbn>1 || fbn<-1 )
        return nodo;
    if(nodo->fe) {
        p = avl(nodo->fe);
        if(p)
            return p;
    }
    if(nodo->fd) {
        p = avl(nodo->fd);
        if(p)
            return p;
    }   
    return NULL;
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
            if(p->fd) 
                p->fd->pai = p;
            q->fe = raiz->fe;
            if(q->fe)
                q->fe->pai = q;
        }
        
        q->fd = raiz->fd;
        if(q->fd)
            q->fd->pai = q;
    }
    q->pai = raiz->pai;
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


No *achaRaiz(No *nodo){
    while(nodo->pai!=NULL)
        nodo = nodo->pai;
    return nodo;
}

No *criaNo(No *pai, int val) {
    No *novoNo=NULL;

    printf("Criando nó %d\n", val);

    novoNo = malloc( sizeof(No) );
    if(!novoNo) {
        printf("ERRO de alocação de memória");
        exit(-1);
    }
    novoNo->numero=val;
    novoNo->pai=pai;
    novoNo->fd=NULL;
    novoNo->fe=NULL;
    
    if( avl( achaRaiz(novoNo) ) )
        printf("A árvore foi desbalanceada/deixou de ser AVL\n");

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

int main() {

    No *arvore = NULL;
    No *p;

    for(int i=1;i<5;i++) 
        insereNo(&arvore, i);

    printf("Altura da árvore é %d\n", altura(arvore));

    printf("FB da raiz é: %d\n", fb(arvore));

    p = avl(arvore);
    if(!p)
        printf("A árvore está balanceada\n");
    else
        printf("Árvore não balanceada\n");

    
    // imprimeEmOrdem(arvore);

    // Teste remoção de nós
    // printf("Removendo %d\n",arvore->fd->numero);
    // arvore = removeNo(arvore->fd);
    // printf("Removendo %d\n",arvore->numero);
    // arvore = removeNo(arvore);
    // printf("Removendo %d\n",arvore->fe->fd->numero);
    // arvore = removeNo(arvore->fe->fd);

    // printf("---PRE-ORDEM---\n");
    // imprimePreOrdem(arvore);
    // printf("---POS-ORDEM---\n");
    // imprimePosOrdem(arvore);


    // p = proximo(arvore);
    // printf("o próximo da raiz tem valor %d\n", p->numero);
    return 0;
}