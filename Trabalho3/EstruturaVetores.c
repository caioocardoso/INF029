#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 11

#include "EstruturaVetores.h"

typedef struct aux
{
    int *vet;
    int head;
    int tamanho;
    int tem;
} Eauxiliar;

Eauxiliar *vetorPrincipal;

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;

    // a posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao].tem == true)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;

    // se posição é um valor válido {entre 1 e 10}
    else if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    // o tamanho ser muito grande
    else if (tamanho > 50)
        retorno = SEM_ESPACO_DE_MEMORIA;

    // o tamanho nao pode ser menor que 1
    else if (tamanho < 1)
        retorno = TAMANHO_INVALIDO;

    // deu tudo certo, crie
    else
    {
        vetorPrincipal[posicao].vet = malloc(tamanho * sizeof(int));
        vetorPrincipal[posicao].tamanho = tamanho;
        vetorPrincipal[posicao].tem = true;
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (vetorPrincipal[posicao].tem == true)
        existeEstruturaAuxiliar = 1;

    if (vetorPrincipal[posicao].head < vetorPrincipal[posicao].tamanho)
        temEspaco = 1;

    if (posicao < 1 || posicao > 10)
        posicao_invalida = 1;

    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            if (temEspaco)
            {
                // insere
                vetorPrincipal[posicao].head += 1;
                vetorPrincipal[posicao].vet[vetorPrincipal[posicao].head] = valor;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if (vetorPrincipal[posicao].tem == false)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (vetorPrincipal[posicao].head < 1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        vetorPrincipal[posicao].head -= 1;
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
    int achou = false;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if (vetorPrincipal[posicao].tem == false)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (vetorPrincipal[posicao].head < 1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else
    {
        for (int icont = 1; icont <= vetorPrincipal[posicao].head; icont++)
        {
            if (vetorPrincipal[posicao].vet[icont] == valor)
            {
                for (int jcont = icont; jcont < vetorPrincipal[posicao].head; jcont++)
                    vetorPrincipal[posicao].vet[jcont] = vetorPrincipal[posicao].vet[jcont + 1];
                vetorPrincipal[posicao].head -= 1;
                achou = true;
                break;
            }
        }
        if (achou == false)
            retorno = NUMERO_INEXISTENTE;
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = SUCESSO;
    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao].tem)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
        for (int icont = 0; icont < vetorPrincipal[posicao].head; icont++)
        {
            vetorAux[icont] = vetorPrincipal[posicao].vet[icont + 1];
        }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao].tem)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {
        for (int i = 0; i <= vetorPrincipal[posicao].head; i++)
        {
            vetorAux[i] = vetorPrincipal[posicao].vet[i];
        }

        for (int i = 0; i <= vetorPrincipal[posicao].head; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j <= vetorPrincipal[posicao].head; j++)
            {
                if (vetorAux[j] < vetorAux[minIndex])
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                int temp = vetorAux[i];
                vetorAux[i] = vetorAux[minIndex];
                vetorAux[minIndex] = temp;
            }
        }

        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int count = 0;
    int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    for (int icont = 1; icont < TAM; icont++)
    {
        if (vetorPrincipal[icont].head != 0 && vetorPrincipal[icont].tem)
        {
            retorno = SUCESSO;
            for (int jcont = 1; jcont <= vetorPrincipal[icont].head; jcont++)
            {
                vetorAux[count++] = vetorPrincipal[icont].vet[jcont];
            }
        }
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int count = 0;
    int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    for (int icont = 1; icont < TAM; icont++)
    {
        if (vetorPrincipal[icont].head != 0 && vetorPrincipal[icont].tem)
        {
            for (int jcont = 1; jcont <= vetorPrincipal[icont].head; jcont++)
            {
                vetorAux[count++] = vetorPrincipal[icont].vet[jcont];
            }
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < count; j++)
        {
            if (vetorAux[j] < vetorAux[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = vetorAux[i];
            vetorAux[i] = vetorAux[minIndex];
            vetorAux[minIndex] = temp;
        }
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao].tem)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {
        int tamanhoResultante = vetorPrincipal[posicao].tamanho + novoTamanho;

        if (tamanhoResultante < 1)
            retorno = NOVO_TAMANHO_INVALIDO;
        else
        {
            int *novoVetor = realloc(vetorPrincipal[posicao].vet, tamanhoResultante * sizeof(int));
            if (novoVetor == NULL)
                retorno = SEM_ESPACO_DE_MEMORIA;
            else
            {
                vetorPrincipal[posicao].vet = novoVetor;
                vetorPrincipal[posicao].tamanho = tamanhoResultante;
                if (novoTamanho < 0)
                    vetorPrincipal[posicao].head += novoTamanho;
                retorno = SUCESSO;
            }
        }
    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int counter = 0;
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (!vetorPrincipal[posicao].tem)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
        retorno = vetorPrincipal[posicao].head;
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    const char *fileName = "db.txt";
    FILE *fp;

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Arquivo '%s' não existe. Criando '%s'.\n", fileName, fileName);
        fp = fopen(fileName, "w");
        if (fp == NULL)
        {
            printf("Erro ao criar o arquivo '%s'.\n", fileName);
            return;
        }
        printf("Arquivo criado com sucesso!\n");
    }
    else
    {
        printf("Arquivo '%s' encontrado!\n", fileName);
    }
    fclose(fp);

    vetorPrincipal = malloc(TAM * sizeof(Eauxiliar));
    for (int icont = 1; icont < TAM; icont++)
    {
        vetorPrincipal[icont].vet = NULL;
        vetorPrincipal[icont].tem = false;
        vetorPrincipal[icont].head = 0;
        vetorPrincipal[icont].tamanho = 0;
    }

    readFile(fileName);
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    printf("Salvando arquivo...\n");
    const char *fileName = "db.txt";
    int save = saveFile(fileName);

    if (save == 1)
    {
        printf("Arquivo salvo com sucesso!\n");
    }
    else
    {
        printf("Erro ao salvar arquivo!\n");
    }

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vet != NULL)
        {
            free(vetorPrincipal[i].vet);
            vetorPrincipal[i].vet = NULL;
        }
    }
    free(vetorPrincipal);
    vetorPrincipal = NULL;
}

int readFile(const char *fileName) {
    int index, lastPos, size, val, ret;
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Arquivo nao encontrado!\n");
        return 0;
    }

    while (fscanf(fp, "%d %d %d", &index, &lastPos, &size) == 3) {
        if (index < 1 || index > TAM) {
            printf("Indice invalido: %d\n", index);
            fclose(fp);
            return 0;
        }
        
        if (size < 0) {
            printf("Tamanho invalido: %d\n", size);
            fclose(fp);
            return 0;
        }
         if (lastPos < 0 || lastPos > size) {
            printf("lastPos invalido: %d\n", lastPos);
            fclose(fp);
            return 0;
        }

        if (size > 0) {
            ret = criarEstruturaAuxiliar(index, size);
            if (ret != SUCESSO) {
                printf("Erro ao criar estrutura auxiliar\n");
                fclose(fp);
                return 0;
            }

            for (int i = 0; i < lastPos; i++) {
                if (fscanf(fp, " %d", &val) != 1) {
                    printf("Erro ao ler valor\n");
                    fclose(fp);
                    return 0;
                }

                if (i < size) { 
                    ret = inserirNumeroEmEstrutura(index, val);
                    if (ret != SUCESSO) {
                        printf("Erro ao adicionar elemento na estrutura auxiliar\n");
                        fclose(fp);
                        return 0;
                    }
                } else {
                    printf("lastPos maior que o tamanho da estrutura auxiliar\n");
                    fclose(fp);
                    return 0;
                }
            }
        }
    }
    fclose(fp);
    return 1;
}

int saveFile(const char *fileName) {
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return 0;
    }

    for (int i = 1; i < TAM; i++) { // Começa de 1 até 10
        if (vetorPrincipal[i].tem) { // Salva apenas estruturas existentes
            fprintf(fp, "%d %d %d", i, vetorPrincipal[i].head, vetorPrincipal[i].tamanho);
            for (int j = 1; j <= vetorPrincipal[i].head; j++) { // Elementos de 1 a head
                fprintf(fp, " %d", vetorPrincipal[i].vet[j]);
            }
            fprintf(fp, "\n"); // Nova linha para próxima estrutura
        }
    }

    fclose(fp);
    return 1;
}