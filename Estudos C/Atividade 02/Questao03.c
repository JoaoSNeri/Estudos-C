#include "stdio.h"


int main(void) {

int n1;
  
  printf("Digite um numero: ");
  scanf("%i",&n1);

  if( (n1 / 2) <= 1 ){
    printf("O numero é impar: %i",n1);
  }
  else{
    printf("O numero é par: %i",n1);
  }
  
  return 0;
}