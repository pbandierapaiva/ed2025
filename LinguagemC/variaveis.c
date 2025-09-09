#include <stdio.h>

int main() {

    char caractere;
    int inteiro;
    float pontoFlutuante;
    double duplo;
    short int inteiroPequeno;
    long int inteiroLongo;

    // caractere = 'A';

    printf("\nO tamanho da variável caractere é \t%ld - %c", 
        sizeof(caractere), caractere);
    printf("\nO tamanho da variável inteiro é \t%ld - %d", 
        sizeof(inteiro), inteiro);
    printf("\nO tamanho da variável pontoFlutuante é \t%ld - %f", 
        sizeof(pontoFlutuante), pontoFlutuante);
    printf("\nO tamanho da variável duplo é \t\t%ld - %f", 
        sizeof(duplo),  duplo);
    printf("\nO tamanho da variável inteiroPequeno é \t%ld - %d", 
        sizeof(inteiroPequeno), inteiroPequeno);
    printf("\nO tamanho da variável inteiroLongo é \t%ld - %ld", 
        sizeof(inteiroLongo), inteiroLongo );


    printf("\n");
}