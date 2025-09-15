#include <stdio.h>

int main() {

    char q[60];
    int cont=0;

    printf("Entre seu nome: ");

    fgets( q, 60, stdin);

    while( q[cont]!='\0' && q[cont]!='\n') {
        cont++;
    }
    q[cont]='\0';

    printf("O tamanho da string \"%s\" é %d\n", q, cont);

}
