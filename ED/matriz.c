// implementação de matriz alocada dinamicamente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
    int *matriz;
    int dimLin, dimCol;
} MATRIZ;


int le(MATRIZ mat, int lin, int col) {
    if(lin>=mat.dimLin || col>=mat.dimCol || lin<0 || col<0) {
        printf("ERRO de índices\n");
        exit(-1); 
    }
    return mat.matriz [ mat.dimCol*lin+col ];
}

void seta(MATRIZ mat, int lin, int col, int valor) {
    if(lin>=mat.dimLin || col>=mat.dimCol || lin<0 || col<0) {
        printf("ERRO de índices\n");
        exit(-1); 
    }
    mat.matriz [ mat.dimCol*lin+col ] = valor;
}

void imprimeMatriz(MATRIZ m) {
    for( int i=0; i<m.dimLin; i++) {
        for(int j=0; j<m.dimCol; j++){
            printf("%d\t", le(m,i,j));
        }
        printf("\n");
    }

}

MATRIZ inicializaMatriz(int linhas, int colunas){
    MATRIZ m;
    m.dimLin = linhas;
    m.dimCol = colunas;
    m.matriz = malloc( m.dimLin*m.dimCol*sizeof(int) );
    if(!m.matriz){
         printf("ERRO de alocação de memória\n");
        exit(-1);        
    }   
    // Coloca zero em toda a matriz alocada
    memset( m.matriz, 0, m.dimLin*m.dimCol*sizeof(int) );
    printf("Matriz (%d x %d)\n", m.dimLin, m.dimCol);
    return m;
}


int main(){

    MATRIZ m;
    int dL, dC;

    printf("Entre com número de linhas e colunas da matriz: ");
    scanf("%d %d", &dL, &dC);

    m = inicializaMatriz(dL,dC);

    for(int i=0;i<m.dimLin;i++) {
        for(int j=0;j<m.dimCol;j++)
            seta(m, i, j, i+j);
    }

    imprimeMatriz(m);

}