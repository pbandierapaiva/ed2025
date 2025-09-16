#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int main() {
    int conta=0;
    float vetM[MAXN], vetN[MAXN], vetor[MAXN];
    int m=0, n=0, c=0;
    int i=0, j=0;

    printf("Vetor M\nEntre com notas, -1 termina\n1 > ");
    while(1){
        scanf("%f", &vetM[m]);
        if(vetM[m]<0)
            break;
        if(m>0){
            if(vetM[m]<vetM[m-1]){
                printf("ERRO - vetores tem que estar em ordem crescente\n");
                exit(-1);
            }
        }
        m++;
        printf("%d > ", m+1);
    }

    printf("Vetor N\nEntre com notas, -1 termina\n1 > ");
    while(1){
        scanf("%f", &vetN[n]);
        if(vetN[n]<0)
            break;
        if(n>0){
            if(vetN[n]<vetN[n-1]){
                printf("ERRO - vetores tem que estar em ordem crescente\n");
                exit(-1);
            }
        }
        n++;
        printf("%d > ", n+1);
    }

    while( i<m && j<n ) {
        if( vetM[i] < vetN[j] ){
            vetor[c] = vetM[i];
            i++;
        } 
        else {
            if( vetM[i] > vetN[j]) {
                vetor[c] = vetN[j];
                j++;
                } 
            else {    // vetM[i] == vetN[j]
                vetor[c] = vetN[j];
                i++;
                j++;
            }
        }
        c++;
    }
    while(i<m){
        vetor[c] = vetM[i];
        i++;
        c++;
    }
    while(j<n){
        vetor[c] = vetN[j];
        j++;
        c++;
    }
    printf("\nVetor mesclado-ordenado %d:\n",c);
    for(int k=0; k<c; k++) {
        printf("%f\n",vetor[k]);
    }

}