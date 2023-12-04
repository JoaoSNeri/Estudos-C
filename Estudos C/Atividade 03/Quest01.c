#include <stdio.h>

int main(void) {

  float n1, n2, n3, n4, n5, media;

  printf("Digite a primeira nota:\n");
  scanf("%f",& n1);
  printf("Digite a segunda nota:\n");
  scanf("%f",& n2);
  printf("Digite a terceira nota:\n");
  scanf("%f",& n3);
  printf("Digite a quarta nota:\n");
  scanf("%f",& n4);
  printf("Digite a quinta nota:\n");
  scanf("%f",& n5);

  media = ((n1 + n2 + n3 + n4 + n5)/ 5);

  printf("\n\nA media das notas é: %.1f", media);
  return 0;
}