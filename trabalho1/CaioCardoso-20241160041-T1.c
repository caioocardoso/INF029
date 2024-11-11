// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Caio Oliveira Cardoso
//  email: caiooliveiracardosoo@gmail.com
//  Matrícula: 20241160041
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "CaioCardoso-20241160041-T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */

int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */

int fatorial(int x)
{ // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

int q1(char str[])
{
  // int datavalida = 1;

  // quebrar a string data em strings sDia, sMes, sAno

  char sDia[3];
  char sMes[3];
  char sAno[5];
  int iDia = 0;
  int iMes = 0;
  int iAno = 0;
  int i;

  for (i = 0; str[i] != '/'; i++)
  {
    sDia[i] = str[i];
  }
  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sDia[i] = '\0'; // coloca o barra zero no final
  }
  else
    return 0;

  int j = i + 1; // anda 1 casa para pular a barra
  i = 0;

  for (; str[j] != '/'; j++)
  {
    sMes[i] = str[j];
    i++;
  }

  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sMes[i] = '\0'; // coloca o barra zero no final
  }
  else
    return 0;

  j = j + 1; // anda 1 casa para pular a barra
  i = 0;

  for (; str[j] != '\0'; j++)
  {
    sAno[i] = str[j];
    i++;
  }

  if (i == 2 || i == 4) // testa se tem 2 digitos
  {
    sAno[i] = '\0'; // coloca o barra zero no final
  }
  else
    return 0;

  for (i = 0; sDia[i] != '\0'; i++)
  {
    if ((sDia[i] - '0') < 0 || (sDia[i] - '0') > 9 && sDia[i] != '\0')
      return 0;
    iDia += sDia[i] - '0';
    iDia *= 10;
  }
  iDia /= 10;

  for (i = 0; sMes[i] != '\0'; i++)
  {
    if ((sMes[i] - '0') < 0 || (sMes[i] - '0') > 9 && sMes[i] != '\0')
      return 0;
    iMes += sMes[i] - '0';
    iMes *= 10;
  }
  iMes /= 10;

  for (i = 0; sAno[i] != '\0'; i++)
  {
    if ((sAno[i] - '0') < 0 || (sAno[i] - '0') > 9 && sAno[i] != '\0')
      return 0;
    iAno += sAno[i] - '0';
    iAno *= 10;
  }
  iAno /= 10;

  if (i == 2)
  {
    if (iAno > 24)
      iAno += 1900;
    else
      iAno += 2000;
  }

  if (iDia < 1 || iDia > 31)
    return 0;

  if (iMes < 1 || iMes > 12)
    return 0;

  if (iMes == 2 && iDia == 29) // Bissexto?
  {
    if ((iAno % 4 == 0 && iAno % 100 != 0) || (iAno % 400 == 0))
      ;
    else
      return 0;
  }

  return 1;

  // printf("%s\n", data);
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DataQuebrada dqInicial, dqFinal;
  int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  dqInicial = quebraData(datainicial);
  dqFinal = quebraData(datafinal);
  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  if (q1(datainicial) == 0)
  {
    dma.retorno = 2;
    return dma;
  }
  else if (q1(datafinal) == 0)
  {
    dma.retorno = 3;
    return dma;
  }
  else
  {
    // verifique se a data final não é menor que a data inicial
    if (dqInicial.iAno > dqFinal.iAno)
    {
      dma.retorno = 4;
      return dma;
    }
    else if (dqInicial.iAno == dqFinal.iAno)
    {
      if (dqInicial.iMes > dqFinal.iMes)
      {
        dma.retorno = 4;
        return dma;
      }
      else if (dqInicial.iMes == dqFinal.iMes)
      {
        if (dqInicial.iDia > dqFinal.iDia)
        {
          dma.retorno = 4;
          return dma;
        }
      }
    }

    // calcule a distancia entre as datas
    dma.qtdAnos = dqFinal.iAno - dqInicial.iAno;
    dma.qtdMeses = dqFinal.iMes - dqInicial.iMes;
    dma.qtdDias = dqFinal.iDia - dqInicial.iDia;

    if ((dqFinal.iAno % 4 == 0 && dqFinal.iAno % 100 != 0) || (dqFinal.iAno % 400 == 0))
      diasMes[1] = 29;

    if (dma.qtdMeses < 0)
    {
      dma.qtdAnos--;
      dma.qtdMeses += 12;
    }
    if (dma.qtdDias < 0)
    {
      dma.qtdMeses--;
      dma.qtdDias += diasMes[dqFinal.iMes - 2];
    }
    // se tudo der certo
    dma.retorno = 1;
    return dma;
  }
}

// /*
//  Q3 = encontrar caracter em texto
//  @objetivo
//     Pesquisar quantas vezes um determinado caracter ocorre em um texto
//  @entrada
//     uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
//         Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
//  @saida
//     Um número n >= 0.
//  */

int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  int iCont;
  char copiaTexto[250];

  for (iCont = 0; texto[iCont]; iCont++)
    copiaTexto[iCont] = texto[iCont];
  copiaTexto[iCont] = '\0';

  if (isCaseSensitive != 1)
  {
    if (c >= 'a' && c <= 'z')
      c -= 32;
    for (iCont = 0; copiaTexto[iCont] != '\0'; iCont++)
      if (copiaTexto[iCont] >= 'a' && copiaTexto[iCont] <= 'z')
        copiaTexto[iCont] -= 32;
  }
  for (iCont = 0; copiaTexto[iCont]; iCont++)
  {
    if (c == copiaTexto[iCont])
      qtdOcorrencias++;
  }

  printf("%s [%d]: ", copiaTexto, qtdOcorrencias);
  return qtdOcorrencias;
}

// /*
//  Q4 = encontrar palavra em texto
//  @objetivo
//     Pesquisar todas as ocorrências de uma palavra em um texto
//  @entrada
//     uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
//  @saida
//     Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
//     O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
//         posicoes[0] = 13;
//         posicoes[1] = 16;
//         Observe que o índice da posição no texto deve começar ser contado a partir de 1.
//         O retorno da função, n, nesse caso seria 1;
//  */

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = -1;
  return qtdOcorrencias;
}

// /*
//  Q5 = inverte número
//  @objetivo
//     Inverter número inteiro
//  @entrada
//     uma int num.
//  @saida
//     Número invertido
//  */

int q5(int num)
{
  int aux = 0;
  while (num > 0)
  {
    aux += num % 10;
    num /= 10;
    aux *= 10;
  }
  num = aux / 10;
  return num;
}

// /*
//  Q6 = ocorrência de um número em outro
//  @objetivo
//     Verificar quantidade de vezes da ocorrência de um número em outro
//  @entrada
//     Um número base (numerobase) e um número de busca (numerobusca).
//  @saida
//     Quantidade de vezes que número de busca ocorre em número base
//  */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0;
  int divisor = 1;
  int aux = numerobusca;

  while (aux > 0)
  {
    aux /= 10;
    divisor *= 10;
  }

  aux = numerobase;

  while (aux > 0)
  {
    if (aux % divisor == numerobusca)
    {
      qtdOcorrencias++;
      aux /= divisor;
    }
    else
      aux /= 10;
  }
  return qtdOcorrencias;
}

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++)
  {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sDia[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++)
  {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sMes[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++)
  {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4)
  {                 // testa se tem 2 ou 4 digitos
    sAno[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
