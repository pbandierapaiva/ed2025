#include <stdio.h>
#include <string.h>

int main() {

    char *s = "Bem-vindo";
    char q[60];

    char texto[500];

    printf("Entre seu nome: ");

    fgets( q, 60, stdin);

    strcpy(texto, s);
    strcat(texto, " ");
    strcat(texto, q);
    strcat(texto, "!\n");

    printf("%s", texto);
    printf("Tamanho do string: %ld\n", strlen(texto));

    // o string q é terminado com '\n' ao ser lido pelo fgets

    for( int i=0; i<60; i++){
        if(q[i] == '\n'){
            q[i]='\0';
            break;
        }
    }


    printf("Agora com a variável q sem '\\n' \n");
    strcpy(texto, s);
    strcat(texto, " ");
    strcat(texto, q);
    strcat(texto, "!\n");

    printf("%s", texto);
    printf("Tamanho do string: %ld\n", strlen(texto));

}