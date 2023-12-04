#include "stdio.h"

int main(void) {

  int salario, emprestimo;
  
  printf("Digite o salario: ");
  scanf("%i",&salario);

  printf("Digite o valor do emprestimo: ");
  scanf("%i",&emprestimo);

  if( emprestimo > ((salario * 20) /100 )){
    printf("Empretimo negado");
  }
  else{
    printf("Emprestimo aprovado");
  }

  return 0;
}