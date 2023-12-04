#include <stdio.h>

int main(void) {

  int salario, reajuste, salariofinal;
  printf("Digite o salario atual: \n");
  scanf("%i",&salario);
  printf("Digite o percentual de reajuste:");
  scanf("%i",&reajuste);

  salariofinal = salario + ((salario * reajuste) / 100);

  printf("Seu salário pós reajuste é de R$: %i", salariofinal);
  return 0;
}