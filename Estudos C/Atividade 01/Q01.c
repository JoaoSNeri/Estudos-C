#include <stdio.h>

int main(void) {
  printf("\n\nBom Dia\n\n\n");

  int mercadoria;
  int frete;
  int valordavenda;
  int valortotal;
  int lucro;
  

  printf("Digite o valor da mercadoria: ");
  scanf("%i",&mercadoria);

  printf("Digite o valor do frete e de despesas eventuais: ");
  scanf("%i",&frete);

  printf("Digite o valo da venda: ");
  scanf("%i",&valordavenda);

  valortotal = mercadoria + frete;
  lucro = valordavenda - valortotal;
  
  if ( valordavenda > valortotal) {
    printf("\n\nO lucro é igual a R$: %i",lucro);
  }
  else if ( valordavenda < valortotal) {
    printf("\n\nO prejuiso é de R$: %i",lucro);
  }
  else if ( valordavenda == valortotal) {
     printf("\n\nNão a lucro, nem prejuiso. Pois o Valor total do produto é igual o Valor de venda");
  }

  return 0;
}