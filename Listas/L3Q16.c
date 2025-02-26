#include <stdlib.h>
#include <stdio.h>

int fatorialduplo(int num){
    if(num <= 1)
        return 1;
    
    int valor = fatorialduplo(num - 2);
    return valor*= num;
}


void main(){
    int num = 7;
    int valor = num;

    valor = fatorialduplo(num);
    
    printf("%d", valor);

}