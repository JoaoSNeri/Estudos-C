#include <stdio.h>

int main() {
    int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
    float media;
   
    printf("Digite o primeiro numero: ");
    scanf("%i", &n1);
    printf("Digite o segundo numero: ");
    scanf("%i", &n2);
    printf("Digite o terceiro numero: ");
    scanf("%i", &n3);
    printf("Digite o quarto numero: ");
    scanf("%i", &n4);
    printf("Digite o quinto numero: ");
    scanf("%i", &n5);
    printf("Digite o sexto numero: ");
    scanf("%i", &n6);
    printf("Digite o setimo numero: ");
    scanf("%i", &n7);
    printf("Digite o oitavo numero: ");
    scanf("%i", &n8);
    printf("Digite o nono numero: ");
    scanf("%i", &n9);
    printf("Digite o decimo numero: ");
    scanf("%i", &n10);

    media = (float) (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10) / 10;

    printf("A media e: %.1f", media);

    return 0;
}