// Implementa pilha

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;


void push(NoListaLigada **pilha, int valor) {
    NoListaLigada *novoNo=NULL;

    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) { // Erro de alocação de memória
        printf("\nERRO de alocação de memória\n");
        exit(-1);
    }
    novoNo->numero = valor;
    novoNo->proximo = *pilha;
    *pilha = novoNo;
}

int pop(NoListaLigada **pilha, int *valor) {
    NoListaLigada *ptr;

    ptr = *pilha;
    if(!ptr) {  //Pilha vazia
        return 0;
    }
    *pilha = ptr->proximo;
    *valor = ptr->numero;
    free(ptr);
    return 1;
}

int peek(NoListaLigada *pilha, int *valor) {
    if(pilha==NULL){//Pilha vazia
        return 0;
    }
    *valor = pilha->numero;
    return 1;
}


// Função para ler apenas 1 caracter do teclado
int pegacara() {
    struct termios old_tio, new_tio;
    char ch;

    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    ch = getchar(); // Reads a single character without waiting for Enter
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return toupper(ch);  
}
void clear_stdin_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//////////////////////////////////////////////////

int main() {
    NoListaLigada *pilha=NULL;
    int valor;
    char op;


    while(op!='X') {
        printf("\nQual operação Push(I), Pop(O), peek(P) ou Sai(x): ");
        op = pegacara();
        printf("Entrou com: %c\n",op);

        switch (op)
        {
        case 'I':
            /* code PUSH */
            printf("Entre com valor: ");
            scanf("%d", &valor);
            clear_stdin_buffer();        
            push(&pilha, valor);
            break;
        case 'O':
            /* code POP */
            if( pop(&pilha, &valor) )
                printf("Valor: %d\n", valor);
            else
                printf("Pilha vazia\n");
            break;
        case 'P':
            /* code PEEK */
            if( peek(pilha, &valor) )
                printf("Valor no topo da pilha: %d", valor);
            else
                printf("Pilha vazia\n");
            break;
        case 'X':
            break;
        default:
            printf("Opção inválida: %c\n", op);
            break;
        }
    }

}






