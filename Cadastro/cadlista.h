// arquivo de cabeçalho para lista ligada

#include "arqutil.h"


typedef struct no {
    Registro registro;
    struct no *proximo;
} ListaReg;
