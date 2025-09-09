#include <stdio.h>

int main() {

    int i;

    printf("\nCom for:\n");
    for(int j=0; j<11; j++) printf("%d\n", j); 

    printf("\nCom while:\n");
    i=0;
    while(i<11){
        printf("%d\n", i);
        i++;
    }

    printf("\nCom do-while:\n");
    i=0;
    do 
        printf("%d\n", i++); 
    while(i<11);

    printf("\nCom for infinito:\n");
    i=0;
    for(;;) {
       printf("%d\n", i++); 
        if(i>10) break;
    }


}