#include <stdio.h>

int main(void) {

  float altura;
  float largura;
  float areapintada;
  float totaltinta;
  
  printf("Digite a altura da parede em metros: ");
  scanf("%f",&altura);

  printf("Digite a largura de parede em metros: ");
  scanf("%f",&largura);

  areapintada = largura * altura;

  totaltinta = (areapintada * 300) / 2000.0;

  printf("%f",totaltinta);

  
  return 0;
}