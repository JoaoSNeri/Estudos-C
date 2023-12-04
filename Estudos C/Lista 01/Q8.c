#include <stdio.h>

int main() {
    int numero, mumeromaior, numeromenor;

    printf("insira um numero inteiro: ");
    scanf("%d", &numero);

    numeromaior = numero;
    numeromenor = numero;

    while(numero >= 0) {
        if(numero > maior) {
            numeromaior = numero;
        }

        if(numero < menor) {
            numeromenor = numero;
        }

        printf("Digite outro numero inteiro ou digite um numero negativo para parar: ");
        scanf("%d", &numero);
    }

    printf("O maior numero foi %d\n", numeromaior);
    printf("O menor numero foi %d\n", numeromenor);

    return 0;
}






