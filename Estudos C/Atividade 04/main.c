#include <stdio.h>
#define M 25

int main(void) {

  float nota[M];
  int i,n;
  float menornota=10;
  int maionota;
  float mediadaturma= 0.0;
  int reprovados=0 ;
  int aprovados=0 ;
  float somadasmedias= 0.0;
  

  printf("-------------------------------------\n");
  printf("Relatorio da turma\n");
  printf("-------------------------------------\n\n");

  printf("Informe o numero de medias (Até 25): ");
  scanf("%d",&n);


  if (n < 1 || n > M) {
      printf("\nNumero de alunos invalido. Por favor, digite um numero entre 1 e %d.\n\n", M);
      return 1; 
    }
    
  for(i=1;i<=n;i++){
      printf("\nInforme a %ia nota: ",i);
      scanf("%f",&nota[i]);
  
      if (nota[i] < menornota) {
        menornota = nota[i];
      }
  
      if (nota[i] < 6.9) {
       reprovados++;
      } else {
          aprovados++;
      }

      somadasmedias += nota[i];
  }

  mediadaturma = somadasmedias / n;
  
  printf("\n---------------------------------------\n");
  printf("\nResultado:\n\n");
  printf("A media da turma é: %.2f\n", mediadaturma);
  printf("Quantidade de alunos reprovados: %d\n", reprovados);
  printf("Quantidade de alunos aprovados: %d\n", aprovados);
  printf("Menor nota informada: %.2f", menornota);
  printf("\n\n---------------------------------------\n");
  
return 0;
}