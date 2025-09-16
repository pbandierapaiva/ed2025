#include <stdio.h>

#define MAXN 100

int main() {
    int conta=0;
    float notas[MAXN];

    printf("Entre com notas, -1 termina\n1 > ");
    while(1){
        scanf("%f", &notas[conta]);
        if(notas[conta]<0)
            break;
        conta++;
        printf("%d > ", conta+1);
    }

    for(int i=conta-1; i>=0; i--){
        printf("%.2f\n", notas[i]);
    }
}