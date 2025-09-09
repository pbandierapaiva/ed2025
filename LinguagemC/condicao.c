#include <stdio.h>

int main() {
    int a, b, c;

    printf("Entre com valors de a, b e c:");
    scanf("%d %d %d", &a, &b, &c);
    if( a>b && a>c) 
        printf("a é o maior\n");
    else if( b>c )
            printf("b é o maior\n");
    else
        printf("c é o maior\n");
}
