#include <stdio.h>

int main(void) {
  
  float n1, n2, n3, notafinal;
  
  printf("\nDigite o valor da primeira nota:");
  scanf("%f",&n1);
  
  printf("\nDigite o valor da segunda nota:");
  scanf("%f",&n2);

  printf("\nDigite o valor da terceira nota:");
  scanf("%f",&n3);

  notafinal = ((n1 * 2)  + (n2 * 3) + (n3 * 5)) / (2 + 3 + 5);

  printf("\n\nA media da nota final é: %f",notafinal);
  
  
  return 0;
}