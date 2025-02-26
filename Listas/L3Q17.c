#include <stdio.h>
#include <stdlib.h>


int fatorial(int valor){
    if(valor <= 1)
        return 1;
    
    int fat = fatorial(valor - 1);
    return fat *= valor;
}

int fatorialQuadruplo(int num){
    int a = fatorial(num*2);
    int b = fatorial (num);
    return a / b;
}


void main(){
    int num = 2;

    num = fatorialQuadruplo(num);
    printf("%d", num);
}