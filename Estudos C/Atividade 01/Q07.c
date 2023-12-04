#include <stdio.h>

int main(void) {

  int custodefabrica, custofinal;
  printf("\nDigite o custo de fabrica do veiculo: ");
  scanf("%i",&custodefabrica);

  custofinal = custodefabrica + ((custodefabrica * 45) / 100) + ((custodefabrica * 28) / 100);

  printf("\n\nO custo final do veiculo é de R$: %i",custofinal);
  
  return 0;
}