// Ler uma string e retornar o número de palavras (separadas por ' ' ou '\t' ou '\n')

#include <stdio.h>

#define MAXS 200

int main() {
    char entrada[MAXS];
    char *p;
    int conta=0;

    printf("> ");
    fgets( entrada, MAXS, stdin);
    printf("Cadeia de char lida: %s\n\n", entrada);

    p = entrada;
    while(*p==' ' || *p=='\t') p++;

    while(*p!='\0' &&  *p!='\n' ) {
        while( *p!=' ' && *p!='\t' && *p!='\0'){
            p++;
        }
        while( (*p==' '|| *p=='\t') && *p!='\0') {
            p++;
        }
        conta++;
    }

    printf("A cadeia de caracteres tem %d palavras\n", conta);

}