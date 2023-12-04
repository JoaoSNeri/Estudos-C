#include <stdio.h>

int main(void) {
  
  int base, altura, area;
  
  printf("Digite o valor da base: ");
  scanf("%i",&base);
  printf("Digite o valor da altura: ");
  scanf("%i",&altura);

  area = (base * altura) / 2; 
  
  printf("O valor da Area é: %i",area);
  
  return 0;
}