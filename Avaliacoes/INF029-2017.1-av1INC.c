#include <stdio.h>
#include <stdbool.h>

int insereCaractere(char vetor[], int *point);
int trocaCaractere(char vetor[], char *caractere, int *point);
int removedor(int *point);
void listarCaracteres(char vetor[], int *point);
void impressaoCaracteres(char vetor[], int *point);

void main()
{
    int TAM = 10, sair = false, escolha, retorno, point = 0;
    char vetor[TAM], caractere;
    
    while (!sair) {
        printf("MENU\n");
        printf("1 - Inserir caractere\n");
        printf("2 - Trocar caractere\n");
        printf("3 - Remover caractere\n");
        printf("4 - Listar caracteres\n");
        printf("5 - Imprimir caracteres\n");
        printf("6 - Sair\n");
        scanf("%d", &escolha);
        getchar(); // Limpar o buffer de entrada
        
        switch (escolha) {
            case 1: {
                retorno = insereCaractere(vetor, &point);
                if (retorno)
                    printf("Caractere inserido com sucesso!\n");
                else
                    printf("Falha ao inserir caractere. Vetor cheio!\n");
                break;
            }
            case 2: {
                retorno = trocaCaractere(vetor, &caractere, &point);
                if (retorno)
                    printf("Caractere trocado com sucesso!\n");
                else
                    printf("Falha ao trocar caractere.\n");
                break;
            }
            case 3: {
                retorno = removedor(&point);
                if (retorno)
                    printf("Caractere removido com sucesso!\n");
                else
                    printf("Falha ao remover caractere. Vetor vazio!\n");
                break;
            }
            case 4: {
                listarCaracteres(vetor, &point);
                break;
            }
            case 5: {
                impressaoCaracteres(vetor, &point);
                break;
            }
            case 6: {
                sair = true;
                printf("Saindo...\n");
                break;
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }
    }
}

int insereCaractere(char vetor[], int *point) {
    char aux;
    printf("Digite um caractere: ");
    scanf("%c", &aux);
    if (*point < 10) {
        vetor[*point] = aux;
        (*point)++;
        return 1;
    } else {
        return 0;
    }
}

int trocaCaractere(char vetor[], char *caractere, int *point) {
    int index;
    printf("Digite o índice do caractere a ser trocado: ");
    scanf("%d", &index);
    getchar(); // Limpar o buffer de entrada
    if (index >= 0 && index < *point) {
        printf("Digite o novo caractere: ");
        scanf("%c", caractere);
        vetor[index] = *caractere;
        return 1;
    } else {
        return 0;
    }
}

int removedor(int *point) {
    if (*point > 0) {
        (*point)--; // Decrementa a posição
        return 1;
    } else {
        return 0;
    }
}

void listarCaracteres(char vetor[], int *point) {
    if (*point > 0) {
        printf("Caractere(s) no vetor: ");
        for (int i = 0; i < *point; i++) {
            printf("[%c] ", vetor[i]);
        }
        printf("\n");
    } else {
        printf("Vetor vazio!\n");
    }
}

void impressaoCaracteres(char vetor[], int *point) {
    if (*point > 0) {
        printf("Imprimindo caracteres do vetor: ");
        for (int i = 0; i < *point; i++) {
            printf("%c ", vetor[i]);
        }
        printf("\n");
    } else {
        printf("Vetor vazio!\n");
    }
}
