#include <stdio.h>

int main(void) {

  int carrosvendidos, vendas, salariofixo, salariofinal, valorpcarro;
  
  printf("\nDigite o numero de carros vendidos: ");
  scanf("%i",&carrosvendidos);

  printf("\nDigite o valor das total das vendas: ");
  scanf("%i",&vendas);

  printf("\nDigite o valor do salario fixo: ");
  scanf("%i",&salariofixo);

  printf("\nDigite o valor da comissão fixa: ");
  scanf("%i",&valorpcarro);

  salariofinal = salariofixo + (valorpcarro * carrosvendidos) + ((vendas * 5) / 100);

  printf("\n\nO salorio final é de R$: %i",salariofinal);

  
  return 0;
}