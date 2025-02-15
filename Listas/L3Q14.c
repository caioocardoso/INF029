/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int todosNaturais(int n);

int main()
{
    todosNaturais(20);
}

int todosNaturais(int n){
    if(n % 2 != 0)
        return -1;
    if (n > 0) {
        todosNaturais(n - 2);
    }
    printf("%d ", n);
}
