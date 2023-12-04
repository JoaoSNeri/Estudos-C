#include <stdio.h>

int main(void) {
    
    int x1,x2,y1,y2;
    int operacao1, operacao2, soma;
    float distancia;

    printf("\n\nInsira o valor do X1: ");
    scanf("%i",&x1);
    printf("\nInsira o valor do Y1: ");
    scanf("%i",&y1);
    printf("\nInsira o valor do X2: ");
    scanf("%i",&x2);
    printf("\nInsira o valor de Y2: ");
    scanf("%i",&y2);

    operacao1 = x2 - x1;
    operacao2 = y2 - y1;

    operacao1 = (operacao1 * operacao1);
    operacao2 = (operacao2 * operacao2);

    soma = operacao1 + operacao2;

    distancia = sqrt(soma);
    
    printf("\n\nO resultado e: %.4f", distancia);
    
  return 0;
}