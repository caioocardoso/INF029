#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();

void dobrar(int *x);

int menu()
{
    int op;
    printf("Digite as opcao desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma estrutura\n");
    scanf("%d", &op);
    return op;
}

int main()
{

    inicializar();
    int op;
    int sair = 0;
    int ret;
    int pos, num;
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            finalizar();
            break;
        }
        case 1:
        { // inserir
            printf("Digite uma posicao da estrutura principal (1 ate 10):\\> ");
            scanf("%d", &pos);
            printf("Digite o valor a ser inserido :\\> ");
            scanf("%d", &num);

            criarEstruturaAuxiliar(pos, 10);

            ret = inserirNumeroEmEstrutura(pos, num);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem Espaço");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar");
            }
            break;
        }

        case 2:
        { // excluir
            printf("Digite uma posicao da estrutura principal (1 ate 10):\\> ");
            scanf("%d", &pos);
            ret = excluirNumeroDoFinaldaEstrutura(pos);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso\n");
            }
            else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
            {
                printf("estrutura vazia\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição invalida para estrutura auxiliar\n");
            }
            // TODO
            break;
        }

        case 3:
        { // recuperar dados estrutura auxiliar
            int posicao, retorno;
            printf("Qual a estrutura a ser listada (1..10)?");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição invalida");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

                if (retorno == SUCESSO)
                {
                    // imprimir para os dados para o usuário
                    int i = 0;
                    for (; i < qtd; i++)
                    {
                        printf("%d ", vetorAux[i]);
                    }
                    printf("\n");
                }
            }
            break;
        }

        default:
        {
            printf("opcao invalida\n");
        }
        }
    }

    return 0;
}
