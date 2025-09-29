// manipulação de arquivos em C eliminando aspas "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arqin, *arqout;
    int cara;

    arqin = fopen("/home/pub/ed/Cadastro.csv","r");
    arqout = fopen("CadLimpo.csv","w");

    while(1) {
        cara = fgetc(arqin);
        if(feof(arqin))
            break;
        if(cara=='"') continue;
        fputc(cara,arqout);
    }

    fclose(arqin);
    fclose(arqout);
}


