#include <stdio.h>
#include <stdlib.h>


int superfatorial(int num){
    if (num <= 1)
        return 1;

    int fat = superfatorial(num - 1);
    return fat *= fatorial(num);

}

int fatorial(int num){
    if(num <= 1)
        return 1;
    
    int valor = fatorial(num - 1);
    return valor *= num;
}

void main() {
    int num = 4;

    num = superfatorial(num);
    printf("%d", num);
}