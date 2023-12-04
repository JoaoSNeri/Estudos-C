#include <stdio.h>

int main(void) {
    
    float raio, pi = 3.14159, area = 0.0, volume = 0.0;

    printf("\n\nInsira o valor do raio: ");
    scanf("%f",&raio);

    area = 4 * pi * (raio * raio); 
    volume = (4/3) * pi * (raio*raio*raio) * area;

    printf("\n O resultado e: %f", volume);
   
  return 0;
}