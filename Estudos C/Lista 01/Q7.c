int main() {
    int n, n1 = 0, n2 = 1, n3;

    printf("Digite um número inteiro maior ou igual a zero: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("O numero digitado não e maior ou igual a zero!!!\n");
    }

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            n3 = n1;
        } else if(i == 1) {
            n3 = n2;
        } else {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
    }

    printf("O %da numero da sequencia de Fibonacci e: %d\n", n, n3);

    return 0;
}





