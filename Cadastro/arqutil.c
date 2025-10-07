// 
// Utilitários para ler arquivo CSV 
//
// Paulo Bandiera Paiva
// 06/10/2025
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"


char *extrai(char *ptr, char *str){
    while(*ptr!='"'){
        *str = *ptr;
        ptr++;
        str++;
    }
    *str = '\0';
    ptr++;
    return ptr;
}

Registro coleta(char *lin){
    Registro r;
    char *p, *q;
    int cpon=0;

    p = lin;

    while(*p!='\0'){
        if( *p=='"' ){ //achou um campo
            cpon++;
            p++;
            switch(cpon){
                case 1:
                    p = extrai(p,r.ids);
                    break;
                case 2:
                    p = extrai(p,r.nome);
                    break;
                case 5:
                    p = extrai(p,r.cargo);
                    break;
                case 17:
                    p = extrai(p,r.org);
                    break;
                case 19:
                    p = extrai(p,r.uorg);
                    p++;
                    return r;
                    break;
                default:
                    while(*p!='"') p++;
                    p++;
                    break;
            }
        }
        p++;
    }
    return r;
}

void limpa(char *p){
    while(*p!='\n' && *p!='\0') {
        *p = toupper(*p);
        p++;
    }
    *p = '\0';
}

void imprimeVetorRegs(Registro *r, int n) {
    for(int i=0; i<n; i++) {
        imprimeReg(r[i]);
    }
}

void imprimeReg(Registro r){
    printf("ID: \t%s\nNome:\t%s\nCargo:\t%s\nORG:\t%s\nUORG:\t%s\n\n",
        r.ids,r.nome,r.cargo,r.org, r.uorg);
}


int encontraRegs(char *q, int tipo, Registro **regvet) {
    FILE *arq;
    Registro reg;
    char linha[MAXLIN];
    int conta=0;
    Registro *pregs;
    int alocado=0;
    int passo=1000;

    pregs = NULL;

    arq = fopen("/home/pub/ed/Cadastro.csv","r");
    if(!arq) {  // arq == NULL?
        printf("ERRO de abertura de arquivo.\n");
        return -1;
    }

    while(!feof(arq)) {
        fgets(linha, MAXLIN, arq);
        reg = coleta(linha);
        if( (tipo==ORG && strstr(reg.org, q)) ||
            (tipo==UORG && strstr(reg.uorg, q)) ||
            (tipo==NOME && strstr(reg.nome, q)) ||
            (tipo==CARGO && strstr(reg.cargo, q))
            ) {
            conta++;
            if(conta>alocado) {
                alocado += passo;
                pregs = realloc(pregs, alocado * sizeof(Registro));
            }
            memcpy( pregs+conta-1, &reg, sizeof(Registro));
            }
        
    }
    *regvet = pregs;
    return conta;
}

int encontraRegsEstruturado(char *q, int tipo, Registro **regvet) {
    FILE *arq;
    Registro reg;
    int conta=0;

    Registro *pregs;
    int alocado=0;
    int passo=1000;

    pregs = NULL;

    arq = fopen("/home/pub/ed/CadEstruturado.db","r");
    if(!arq) {  // arq == NULL?
        printf("ERRO de abertura de arquivo.\n");
        return -1;
    }

    while(!feof(arq)) {
        fread(&reg, sizeof(Registro), 1, arq);

        if( (tipo==ORG && strstr(reg.org, q)) ||
            (tipo==UORG && strstr(reg.uorg, q)) ||
            (tipo==NOME && strstr(reg.nome, q)) ||
            (tipo==CARGO && strstr(reg.cargo, q))
            ) {
            conta++;
            if(conta>alocado) {
                alocado += passo;
                pregs = realloc(pregs, alocado * sizeof(Registro));
            }
            memcpy( pregs+conta-1, &reg, sizeof(Registro));
            }
        
    }
    *regvet = pregs;
    return conta;
}

int encontraRegsIndiceOrg(char *q, Registro **regvet) {
    FILE *arq, *arqindice;
    Registro reg;
    RegIndOrg regio;

    Registro *pregs=NULL;
    int conta=0;
    int alocado=0;
    int passo=1000;

    arqindice = fopen("/tmp/indiceOrg.db","r");
    arq = fopen("/home/pub/ed/CadEstruturado.db","r");
    if(!arq || !arqindice) {  // arq == NULL?
        printf("ERRO de abertura de arquivo.\n");
        return -1;
    }

    while(!feof(arqindice)) {
        fread(&regio, sizeof(RegIndOrg), 1, arqindice);

        if(strstr(regio.org,q)) {
            fseek(arq, regio.indice*sizeof(Registro), SEEK_SET);
            fread( &reg, sizeof(Registro),1, arq);
            conta++;
            if(conta>alocado) {
                alocado += passo;
                pregs = realloc(pregs, alocado * sizeof(Registro));
            }
            memcpy( pregs+conta-1, &reg, sizeof(Registro));
        }
    }
    *regvet = pregs;
    return conta;
}
   