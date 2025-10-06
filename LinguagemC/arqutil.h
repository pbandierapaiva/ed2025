// 
// Arquivo de cabeçalho para utilitários
//
// Paulo Bandiera Paiva
// 06/10/2025
//
#define MAXLIN 900

#define NOME    0
#define CARGO   1
#define ORG     2
#define UORG    3

typedef struct 
{
    char ids[20];      // CPO 1
    char nome[100];    // CPO 2
    char cargo[60];    // CPO 5
    char org[100];     // CPO 17
    char uorg[100];    // CPO 19
} Registro;


Registro coleta(char *);
void limpa(char *);
void imprimeReg(Registro );
void imprimeVetorRegs(Registro *r, int n);
int encontraRegs(char *q, int tipo, Registro **);
