#include "stdio.h"
#include "math.h"

int main(void) {

  float n1, n2, raiz, quadrado;

  printf("Digite um numero: ");
  scanf("%f",&n1);

  if(n1 > 0){
    n2 = n1;
    raiz = sqrt(n1);
    quadrado = n2 * n2;
    printf("A raiz do numero digitado é %.3f e o numero ao quadrado é %.1f",raiz,quadrado);
  }
  else{
    printf("O numero é negativo");
  }

  return 0;
}