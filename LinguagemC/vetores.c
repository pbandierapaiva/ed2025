#include <stdio.h>

#define MAXN 100

int main() {

    float notas[MAXN];
    int i=0;
    float valor;

    printf("Entre com notas, -1 termina\n1 > ");
    while(1){
        scanf("%f", &valor);
        if(valor<0)
            break;
        notas[i] = valor;
        i++;
        printf("%d > ", i+1);

    }

    printf("\nVocê entrou com %d valores\n",i);
    for(int j=0; j<i; j++ ){
        printf("%.2f\n", notas[j]);
    }

}