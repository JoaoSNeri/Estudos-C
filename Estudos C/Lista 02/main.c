#include <stdio.h>
#include <string.h>

#define MAX_PROFESSORES 3
#define MAX_ESTUDANTES 15

// Estruturas
typedef struct {
    char nome[50];
    int funcional;
    char titulacao[20];
} Professor;

typedef struct {
    int codigo;
    int carga_horaria;
    Professor professor_responsavel;
} Disciplina;

typedef struct {
    char nome[50];
    int matricula;
    int idade;
} Estudante;

// Função para validar a idade do estudante
int le_valida_idade() {
    int idade;
    do {
        printf("Informe a idade do estudante (entre 16 e 26): ");
        scanf("%d", &idade);
        if (idade < 16 || idade > 26) {
            printf("Idade inválida. Tente novamente.\n");
        }
    } while (idade < 16 || idade > 26);
    return idade;
}

// Procedimento para ordenar estudantes por idade usando Bubble Sort
void bubble_sort(Estudante *estudantes, int num_estudantes) {
    int i, j;
    Estudante temp;
    for (i = 0; i < num_estudantes - 1; i++) {
        for (j = 0; j < num_estudantes - i - 1; j++) {
            if (estudantes[j].idade > estudantes[j + 1].idade) {
                // Troca os elementos
                temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Cadastro dos professores
    Professor professores[MAX_PROFESSORES];
    int i;
    for (i = 0; i < MAX_PROFESSORES; i++) {
        printf("Cadastro do Professor %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", professores[i].nome);
        printf("Funcional: ");
        scanf("%d", &professores[i].funcional);
        printf("Titulação (especialista, mestre ou doutor): ");
        scanf("%s", professores[i].titulacao);
        printf("\n");
    }

    // Definição das disciplinas
    Disciplina disciplina1;
    disciplina1.codigo = 1;
    disciplina1.carga_horaria = 60;
    disciplina1.professor_responsavel = professores[0];

    Disciplina disciplina2;
    disciplina2.codigo = 2;
    disciplina2.carga_horaria = 80;
    disciplina2.professor_responsavel = professores[1];

    // Cadastro dos estudantes nas disciplinas
    Estudante estudantes1[MAX_ESTUDANTES];
    Estudante estudantes2[MAX_ESTUDANTES];
    int num_estudantes1, num_estudantes2;

    printf("Quantidade de estudantes matriculados na Disciplina 1 (até 10): ");
    scanf("%d", &num_estudantes1);
    if (num_estudantes1 < 1 || num_estudantes1 > MAX_ESTUDANTES) {
        printf("Quantidade inválida.\n");
        return 1; // Código de erro
    }
    for (i = 0; i < num_estudantes1; i++) {
        printf("Cadastro do Estudante %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", estudantes1[i].nome);
        printf("Matrícula: ");
        scanf("%d", &estudantes1[i].matricula);
        estudantes1[i].idade = le_valida_idade();
        printf("\n");
    }

    printf("Quantidade de estudantes matriculados na Disciplina 2 (até 10): ");
    scanf("%d", &num_estudantes2);
    if (num_estudantes2 < 1 || num_estudantes2 > MAX_ESTUDANTES) {
        printf("Quantidade inválida.\n");
        return 1; // Código de erro
    }
    for (i = 0; i < num_estudantes2; i++) {
        printf("Cadastro do Estudante %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", estudantes2[i].nome);
        printf("Matrícula: ");
        scanf("%d", &estudantes2[i].matricula);
        estudantes2[i].idade = le_valida_idade();
        printf("\n");
    }

    // Ordenação dos estudantes da primeira disciplina por idade
    bubble_sort(estudantes1, num_estudantes1);

    // Relatório dos alunos matriculados na primeira disciplina ordenados por idade
    printf("\nRelatório dos alunos matriculados na primeira disciplina ordenados por idade:\n");
    for (i = 0; i < num_estudantes1; i++) {
        printf("%d\t%s\t%s\t%d\n", disciplina1.codigo, disciplina1.professor_responsavel.nome,
               estudantes1[i].nome, estudantes1[i].idade);
    }

    // Ordenação dos estudantes da segunda disciplina por idade em ordem decrescente
    bubble_sort(estudantes2, num_estudantes2);

    // Relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente
    printf("\nRelatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n");
    for (i = num_estudantes2 - 1; i >= 0; i--) {
        printf("%d\t%s\t%s\t%d\n", disciplina2.codigo, disciplina2.professor_responsavel.nome,
               estudantes2[i].nome, estudantes2[i].idade);
    }

    return 0;
}