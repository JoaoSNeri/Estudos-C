#include <stdio.h>

int main() {
  int n1, i;

  printf("Digite um número: ");
  scanf("%d", &n1);

  if (n1 > 0) {

    printf("\nOs divisores do número %d sao: ", n1);

    for (int i = 1; i <= n1; i++) {
      if (n1 % i == 0) {
        printf("%d ", i);
      }
    }
  }

  if (n1 <= 0) {
    printf("Digite um numero maior que 0");
  }

  return 0;
}
