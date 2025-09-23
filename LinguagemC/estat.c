#include <stdio.h>
#include <stdlib.h>


int main() {
    int num;

    float soma=0;
    float *vetor;

    printf("\nQuantos números na sua série (N): ");
    scanf("%d", &num);
    
    vetor = malloc( num * sizeof(float));
    if(vetor==NULL) { //ERRO DE ALOCAÇÃO DE MEMÓRIA!
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA!");
        exit(-1);
    }
    printf("Entre com os números:\n");
    for(int i=0; i<num; i++) {
        printf("> ");
        scanf("%f", &vetor[i]);
        soma+=vetor[i];
    }
    printf("Média: %.2f\n", soma/num);

}