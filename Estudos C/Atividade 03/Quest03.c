#include <stdio.h>

int main(void) {

  int idade;
  
  printf("Digite sua idade: ");
  scanf("%i",&idade);

  if (idade >= 70){
    printf("Novos 50");
  }
  else if (idade >= 21){ 
    printf("Adulto");
  }
  if (idade < 21){
    printf("Jovem");
  }
  return 0;
}
