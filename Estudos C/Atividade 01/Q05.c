#include <stdio.h>

int anos, dias, messes;

int main(void) {
  
  printf("Digite a sua idade em anos: ");
  scanf("%i",&anos);
  printf("Digite a sua idade em messes: ");
  scanf("%i",&messes);
  printf("Digite a sua idade em dias: ");
  scanf("%i",&dias);

  
  dias = (dias + (anos * 365) + ( messes * 30 ));

  printf("%i",dias);

  
  
  return 0;
}