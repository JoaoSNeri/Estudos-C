#include <stdio.h>

int main(void) {

  int n1, n2;

  printf("Digite o primeiro numero: ");
  scanf("%i",&n1);

  printf("Digite o segundo numero:");
  scanf("%i",&n2);

  if(n1 > n2){
    printf("O primeiro numero é o maior: %i",n1);
  }
  else if(n2 > n1){
    printf("\n\nO segundo numero é o maior: %i",n2);
  }
  
  return 0;
}