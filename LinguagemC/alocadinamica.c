#include <stdio.h>
#include <stdlib.h>


int main() {

    int *vet;
    int vetor[100];

    //aloca espaço para 100 inteiros
    vet = malloc( 100 * sizeof(int) );

    printf("tamanho do vet: %ld\n", sizeof(vet));
    printf("tamanho do vetor alocado estaticamente: %ld\n", 
        sizeof(vetor));


    // para a struct data
    typedef struct  {
        unsigned char dia;
        unsigned char mes;
        short int ano;
    } Data;

    Data d;
    Data *pd;
    
    pd = &d;

    printf("tamanho da variavel 'd': %ld\n", sizeof(d));
    // d.dia = 23;
    // d.mes = 9;
    // d.ano = 2025;
    //     OU
    pd->dia = 23;
    pd->mes = 9;
    pd->ano = 2025;


    printf("tamanho da variavel ponteiro 'pd': %ld\n", sizeof(pd));
    printf("Endereço armazenado em pd %ld\n", (long int)pd);
    
    pd = &d;
    printf("Endereço armazenado em pd %ld\n", (long int)pd);

    printf("Dia %d, mês %d, ano %d\n", d.dia, d.mes, d.ano);
    printf("Dia %d, mês %d, ano %d\n", pd->dia, pd->mes, pd->ano);

    // Quero armazenar 100 datas alocadas dinamicamente
    pd = malloc( (long int)1 * 1024*1024*1024 * sizeof(Data));
    if( !pd ){   //alocação Não foi bem sucedida =>  pd == NULL
        printf("ERRO de alocação dinâmica de memória!\n");
    }
    else {
        printf("alocação dinâmica de memória OK!\n");
    }
    free(pd);
}    