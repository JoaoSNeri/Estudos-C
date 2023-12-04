#include <stdio.h>

int main(void) {

  int idade;
  
  printf("Digite a sua idade: ");
  scanf("%i",& idade);

  if(idade <= 0 ){
    printf("Ainda não nasceu");
  }
  if(idade >= 1 && idade <= 15){
    printf("Não Vota");
  }
  if(idade >= 16 && idade <= 17){
    printf("Opcional");
  }
  if(idade >= 18 && idade < 40){
    printf("Obrigatorio");
  } 
  if(idade == 41){
    printf("Bonus Não vota");
  }
  if(idade >= 42 && idade < 64){
    printf("Obrigatorio");
  }
  if(idade == 65){
    printf("Opcional");
  }
  if(idade == 88){
    printf("Bonous Não vota");
  }
  
  return 0;
}