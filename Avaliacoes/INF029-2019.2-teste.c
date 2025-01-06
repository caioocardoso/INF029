#include <stdio.h>

void limpaVetor(int vetor[10]);
void preencherVetor(int vetor[10]);
void descobreMaiorMenor(int vetor[], int * maior, int * menor);
void imprimeMaiorMenor(int maior, int menor);

void main()
{
    int vetor[10], maior, menor;
    
    maior = 0;
    menor = 0;
    
    limpaVetor(vetor);
    
    preencherVetor(vetor);
    
    descobreMaiorMenor(vetor, &maior, &menor);
    
    imprimeMaiorMenor(maior, menor);
}

void limpaVetor(int vetor[]){
    for(int i = 0; i<10;i++)
        vetor[i]=0;
}

void preencherVetor(int vetor[]){
    for(int i = 0; i<10;i++)
        scanf("%d", &vetor[i]);
}

void descobreMaiorMenor(int vetor[], int *maior, int *menor){
    *menor = vetor[0];
    for (int i =0;i<10;i++){
        if(vetor[i]>*maior)
            *maior=vetor[i];
        if(vetor[i]<*menor)
            *menor=vetor[i];
    }
}

void imprimeMaiorMenor(int maior, int menor){
    printf("Maior: %d", maior);
    printf("\nMenor:%d", menor);
}
