#include <stdio.h>

int main(void) {
    
    float x, y;

    printf("\n\nInsira o valor de X: ");
    scanf("%.1f",&x);
    printf("\n\nInsira o valor de Y: ");
    scanf("%.1f",&y);

    if (x == 0 && y == 0) {
        printf("Está sobre a origem\n");
    } else if (x == 0) {
        printf("Está sobre o eixo Y\n");
    } else if (y == 0) {
        printf("Está sobre o eixo X\n");
    } else {
        if (x > 0 && y > 0) {
            printf("Quadrante 1\n");
        } else if (x < 0 && y > 0) {
            printf("Quadrante 2\n");
        } else if (x < 0 && y < 0) {
            printf("Quadrante 3\n");
        } else {
            printf("Quadrante 4\n");
        }
    }
   
  return 0;
}