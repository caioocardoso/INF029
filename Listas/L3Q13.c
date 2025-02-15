/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int valor;
    int i = 0;
    
    scanf("%d", &valor);
    
    while (i <= valor){
        printf("%d ", i);
        todosNaturais(&i);
    }
}

todosNaturais(int *i){
    *i = *i + 1;
}
