

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int valor;
    int coluna;
    struct no *prox;
} NO;

typedef struct {
    NO **vetlin;
    int linhas;
    int colunas;
} MATRIZ;

MATRIZ *inicializa(int l, int c){
    MATRIZ  *m;
    NO **p;

    m = malloc(sizeof(MATRIZ));
    if(!m){
        printf("ERRO de alocação de memória\n");
        exit(-1);
    }
    m->linhas = l;
    m->colunas = c;
    m->vetlin = malloc(m->linhas*sizeof(NO *));
    if(!m->linhas){
        printf("ERRO de alocação de memória de vetor de linhas\n");
        exit(-1);
    }   
    p = m->vetlin;
    for(int i=0;i<m->linhas;i++){
        p[i] = NULL;
    }

}

NO *criaNo(int col, int val){
    NO *p;
    p = malloc(sizeof(NO)); 
    if(!p){
        printf("ERRO de alocação de memória de vetor de linhas\n");
        exit(-1);
    }   
    p->coluna=col;
    p->valor=val;
    p->prox=NULL;
    return p;
}

void seta(MATRIZ *m, int lin, int col, int val){
    NO *ptr;
    NO *novoNo;

    if( lin>=m->linhas || lin<0 || col>=m->colunas || col<0 ){
        printf("ERRO - índice\n");
        return;
    }

    if ( m->vetlin[ lin ]==NULL ) {
        m->vetlin[ lin ] = criaNo(col,val);
        return;
    }

    if( m->vetlin[ lin ]->coluna == col ) {
        m->vetlin[ lin ]->valor = val;
        return;
    }

    novoNo =  criaNo(col,val);

    ptr = m->vetlin[ lin ];

    while ( 1 ) {
        if(ptr->coluna > col ){
            novoNo->prox = m->vetlin[ lin ];
            m->vetlin[ lin ] = novoNo;
            break;
        }
        if( m->vetlin[ lin ]->coluna == col ) {
            m->vetlin[ lin ]->valor = val;
            break;
        }
        if(ptr->prox==NULL) {
            ptr->prox = novoNo;
            break;
        }
        ptr = ptr->prox;
    }
}

int pega(MATRIZ *m, int lin, int col) {
    NO *ptr;

    if( lin>=m->linhas || lin<0 || col>=m->colunas || col<0 ){
        printf("ERRO - índice\n");
        exit(-1);
    }
    
    ptr = m->vetlin[lin];

    while(ptr) {
        if(ptr->coluna=col)
            return ptr->valor;
        if(ptr->coluna>col) 
            return 0;
        ptr = ptr->prox;
    }
    return 0;
}

void imprime(MATRIZ *m){
    for(int i=0;i<m->linhas;i++) {
        for(int j=0;j<m->colunas;j++)
            printf("%d\t", pega(m,i,j));
        printf("\n");
    }
}

int main(){
   MATRIZ *mat=NULL;

   mat = inicializa(10,9);

    for(int i=0;i<mat->linhas;i++) {
        for(int j=0;j<mat->colunas;j++)
            seta(mat, i, j, i+j);
    }
    imprime(mat);
}