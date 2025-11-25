// 
//Encontra nome em arquivo CSV de Servidores que está indexado através de uma árvore AVL
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

NoAVL *achaRaiz(NoAVL *no) {
    while(no->pai) 
        no = no->pai;
    return no;
}

int altura(NoAVL *arv) {
    int he,hd;

    if( !arv ) return -1;
    he = altura(arv->fe);
    hd = altura(arv->fd);   
    if(he>hd) return he+1;
    return hd+1;
}

int fb(NoAVL *nodo) {
    return altura(nodo->fd) - altura(nodo->fe);
}

NoAVL *avl(NoAVL *nodo) {
    int fbn;
    NoAVL *p;

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

NoAVL *criaNo(NoAVL *pai, RegIndNome registro) {
    NoAVL *novoNo=NULL;

    // printf("Criando nó %d\n", val);
    novoNo = malloc( sizeof(NoAVL) );
    if(!novoNo) {
        printf("ERRO de alocação de memória");
        exit(-1);
    }
    strcpy( novoNo->reg.nome, registro.nome );
    novoNo->reg.localiza = registro.localiza;
    novoNo->pai=pai;
    novoNo->fd=NULL;
    novoNo->fe=NULL;
    
    return novoNo;
}


void rotacaoDireita( NoAVL **arv ) {
    NoAVL *p = *arv;
    NoAVL *u = p->fe;

    p->fe = u->fd;
    u->fd = p;
    *arv = u;
}

void rotacaoEsquerda( NoAVL **arv ) {
    NoAVL *p = *arv;
    NoAVL *u = p->fd;

    p->fd = u->fe;
    u->fe = p;
    *arv = u;
}

void rotacaoDuplaDireita( NoAVL **arv ) {
    rotacaoEsquerda( &( (*arv)->fe) );
    rotacaoDireita( arv );
}

void rotacaoDuplaEsquerda( NoAVL **arv ) {
    rotacaoDireita( &( (*arv)->fd) );
    rotacaoEsquerda( arv );
}

void balanceia( NoAVL **arv ) {
    NoAVL *p, *q, **apontaq;
    int fbq;

    if( *arv == NULL ) return;
    p = *arv;
    while(p->pai !=NULL )
        p = p->pai;
    
    q = avl( p );
    if(!q) return; // q é NULO, árvore AVL

     // quem está apontando para o q? faça ser apontaq   
    if( q->pai == NULL )
        apontaq = arv;
    else {
        if( q->pai->fe == q )
            apontaq = &(q->pai->fe);
        else
            apontaq = &(q->pai->fd);
    }

    fbq = fb(q);
    if(fbq>1) {
        if( fb(q->fd)>0 )
            rotacaoEsquerda( apontaq );
        else
            rotacaoDuplaEsquerda( apontaq );
    }
    else {
        if( fb(q->fe)>0 )
            rotacaoDireita( apontaq );
        else
            rotacaoDuplaDireita( apontaq );
    }
}


void insereAVL(NoAVL **arv, RegIndNome registro) {
    if(! *arv ) {     // arv é NULO
        *arv = criaNo(NULL, registro);
        return;
    }
    
    if( strcmp( (*arv)->reg.nome, registro.nome   ) < 0 )  { 
        if( (*arv)->fd )
            insereAVL( &((*arv)->fd), registro );
        else  {// fd é NULL
            (*arv)->fd = criaNo(*arv, registro);
            balanceia( arv );
        }
    }
    else if( strcmp( (*arv)->reg.nome, registro.nome  )> 0 )  
    {
        if( (*arv)->fe )
            insereAVL( &((*arv)->fe), registro );
        else  { // fe é NULL
            (*arv)->fe = criaNo(*arv,registro);
            balanceia( arv );
        }
    }
    return;
}


void pegaRegistroCSV( char *arqcsv, RegIndNome res) {
    FILE *arq;
    char linha[MAXLIN];
    Registro reg;

    arq = fopen(arqcsv,"r");
    if(!arq) {  // arq == NULL?
            printf("ERRO de abertura de arquivo.\n");
            exit(-1);
        }

    fseek( arq, res.localiza, 0);
    fgets(linha, MAXLIN, arq);
    reg = coleta(linha);
    imprimeReg(reg);
}

NoAVL *busca(NoAVL *arvind, char *q){
    int cmpres;

    if( !arvind ) return NULL;

    cmpres = strcmp(arvind->reg.nome, q );
    if( cmpres==0 )
        return arvind;
    if(cmpres>0)     // q é menor, vai para a esquerda
        return busca(arvind->fe, q);
    else
        return busca(arvind->fd, q);
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
    NoAVL *abb = NULL;
    NoAVL *p;
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
        insereAVL(&abb, regind);
    }
    end = clock();
    fclose(arq);
    printf("Arquivo lido e indexado em lista ligada! (Tempo %f s)\n", 
                        ((double)(end - start)) / CLOCKS_PER_SEC);


    printf("\nEntre com nome completo a ser pesquisado: ");
    fgets(nomeq,100,stdin);
    limpa(nomeq);

    printf("Nome entrado: %s\n", nomeq);

    start = clock();
    p = busca(abb,nomeq);
    if(p)
        pegaRegistroCSV(ARQUIVOCSV, p->reg);
    else
        printf("\nRegistro não encontrado\n");

    end = clock();
    printf("Tempo de execução: %f\n\n", ((double)(end - start)) / CLOCKS_PER_SEC );

}