#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100

int main() {

    float notas[MAXN];
    int i=0;
    float soma=0, media, desvio;

    printf("Você alocou estaticamente %ld bytes\n", 
        sizeof(notas));

    printf("Entre com notas, -1 termina\n1 > ");
    while(1){
        scanf("%f", &notas[i]);
        if(notas[i]<0)
            break;
        i++;
        printf("%d > ", i+1);
    }

    printf("\nVocê entrou com %d valores\n",i);
    for(int j=0; j<i; j++ ){
        printf("%.2f\n", notas[j]);
        soma += notas[j];
    }
    if(i<=0)
        exit(0);

    media = soma/i;

    soma=0;
    for(int j=0; j<i; j++ ){
        soma += (notas[j]-media)*(notas[j]-media);
    }
    desvio = sqrt(soma);
    printf("\nMédia: %.2f, DP: %.2f", media, desvio);
}