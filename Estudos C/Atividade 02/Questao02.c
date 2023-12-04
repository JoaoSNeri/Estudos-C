#include <stdio.h>

int main(void) {

  int n1, n2;

  printf("Digite o primeiro numero: ");
  scanf("%i",&n1);

  printf("Digite o segundo numero: ");
  scanf("%i",&n2);

  if(n1 > n2){
    printf("\n\nO primeiro numero é o maior: %i",n1);
  }
  if(n2 > n1){
    printf("\n\nO segundo numero é o maior: %i",n2);
  }
  else if(n1 == n2){
    printf("\n\nOs numeros são iguais %i e %i",n1,n2);
  }
  
  return 0;
}