/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void todosNaturais(int n);

int main()
{
    todosNaturais(10);
}

void todosNaturais(int n){
    if (n > 0) {
        todosNaturais(n - 1);
    }
    printf("%d ", n);
}
