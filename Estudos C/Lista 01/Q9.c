int main(void){

int menu;
int total, quantidade;
  
  do{
    
    printf("\n");
    printf("---------------------------------\n");
    printf("    Bem vindo ao mercadinho!\n");
    printf("---------------------------------\n");
    printf("\n");

    printf("Opcao 01 -> Abacaxi <-  5 Reais\n");
    printf("Opcao 02   -> Maca <-   1 Reais\n");
    printf("Opcao 03   -> Pera <-   4 Reais\n");
    printf("Opcao 04      --> Para sair <--\n");


    printf("\n");
    printf("---------------------------------\n");
    printf("   Escolha uma opcao (1 a 4) !\n");
    printf("---------------------------------\n");
    printf("\n");
  
    scanf("%d", &menu);

    switch(menu) {
            case 1:
                printf("\nDigite a quantidade de abacaxis desejada: ");
                scanf("%d", &quantidade);
                total += quantidade * 5.0;
                break;
            case 2:
                printf("\nDigite a quantidade de macas desejada: ");
                scanf("%d", &quantidade);
                total += quantidade * 1.0;
                break;
            case 3:
                printf("\nDigite a quantidade de peras desejada: ");
                scanf("%d", &quantidade);
                total += quantidade * 4.0;
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        
        }
  }while(menu != 0);
  
  return 0;
}