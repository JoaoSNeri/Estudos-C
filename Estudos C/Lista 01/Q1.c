#include <stdio.h>

int main(void) {
  
  int a,b,c,d;
  int diferenca;

    printf("\nInsira o valor de A: ");
    scanf("%i",&a);
    printf("\nInsira o valor de B: ");
    scanf("%i",&b);
    printf("\nInsira o valor de C: ");
    scanf("%i",&c);
    printf("\nInsira o valor de D: ");
    scanf("%i",&d);

    diferenca = (a * b) - (c * d); 

    printf("\no valor de A= %i vezes o valor de B= %i menos o valor de C= %i vezes o valor de D= %i", a,b,c,d);
    printf("\nO resultado e =%i", diferenca);

  return 0;
}