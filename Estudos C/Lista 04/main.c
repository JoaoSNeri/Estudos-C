#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRICAO 100
#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50

typedef struct {
  char descricao[MAX_DESCRICAO];
  float peso;
  float valorCompra;
  float valorVenda;
  float valorLucro;
  float percentualLucro;
  int fabricanteIndex; // Índice do fabricante no vetor de fabricantes
} Produto;

typedef struct {
  char marca[MAX_DESCRICAO];
  char site[MAX_DESCRICAO];
  char telefone[MAX_DESCRICAO];
  char uf[3];
} Fabricante;

void leValidaFloat(float *valor, const char *mensagem) {
  do {
    printf("%s: ", mensagem);
    if (scanf("%f", valor) != 1) {
      scanf("%*[^\n]"); // Limpa o buffer do teclado
      printf("Entrada invalida. Tente novamente.\n");
      continue;
    }
    if (*valor <= 0) {
      printf("Valor invalido. Tente novamente.\n");
      continue;
    }
    break;
  } while (1);
}

void leValidaString(char *string, int tamanho, const char *mensagem) {
  do {
    printf("%s: ", mensagem);
    if (scanf("%99s", string) != 1) {
      scanf("%*[^\n]"); // Limpa o buffer do teclado
      printf("Entrada invalida. Tente novamente.\n");
      continue;
    }
    break;
  } while (1);
}

void cadastrarFabricante(Fabricante *fabricante) {
  leValidaString(fabricante->marca, MAX_DESCRICAO, "Marca do fabricante");
  leValidaString(fabricante->site, MAX_DESCRICAO, "Site do fabricante");
  leValidaString(fabricante->telefone, MAX_DESCRICAO, "Telefone do fabricante");
  leValidaString(fabricante->uf, 3, "UF do fabricante");
}

void cadastrarProduto(Produto *produto, Fabricante *fabricantes,
                      int numFabricantes) {
  leValidaString(produto->descricao, MAX_DESCRICAO, "Descricao do produto");
  leValidaFloat(&produto->peso, "Peso do produto (em gramas)");
  leValidaFloat(&produto->valorCompra, "Valor de compra do produto");
  leValidaFloat(&produto->valorVenda, "Valor de venda do produto");

  produto->valorLucro = produto->valorVenda - produto->valorCompra;
  produto->percentualLucro =
      (produto->valorLucro / produto->valorCompra) * 100.0;

  int i, escolha;
  printf("\nEscolha o fabricante (1-%d):\n\n", numFabricantes);
  for (i = 0; i < numFabricantes; i++) {
    printf("%d. %s\n", i + 1, fabricantes[i].marca);
  }
  scanf("%d", &escolha);
  produto->fabricanteIndex = escolha - 1;
}

void listarProdutosOrdenados(Produto *produtos, int numProdutos,
                             Fabricante *fabricantes, int numFabricantes) {
  int i;
  printf("Lista de produtos em ordem alfabetica crescente (A-Z):\n\n");
  printf("---------------------------------------------------------------------"
         "---------------------------------------------\n");
  printf("| %-10s | %-10s | %-15s | %-15s | %-15s | %-10s | %-10s |\n",
         "Descricao", "Peso (g)", "Valor Compra", "Valor Venda", "Valor Lucro",
         "Perc. Lucro", "Fabricante");
  printf("---------------------------------------------------------------------"
         "---------------------------------------------\n");
  for (i = 0; i < numProdutos; i++) {
    printf("| %-10s | %-10.2f | R$ %-11.2f | R$ %-11.2f | R$ %-11.2f | "
           "%-10.2f%% | %-10s |\n",
           produtos[i].descricao, produtos[i].peso, produtos[i].valorCompra,
           produtos[i].valorVenda, produtos[i].valorLucro,
           produtos[i].percentualLucro,
           fabricantes[produtos[i].fabricanteIndex].marca);
  }
  printf("---------------------------------------------------------------------"
         "---------------------------------------------\n");
}

void listarFabricantesOrdenados(Fabricante *fabricantes, int numFabricantes) {
  int i;
  printf("Lista de fabricantes em ordem alfabetica decrescente (Z-A):\n\n");
  printf(
      "-------------------------------------------------------------------\n");
  printf("| %-15s | %-15s | %-15s | %-3s |\n", "Marca", "Site", "Telefone",
         "UF");
  printf(
      "-------------------------------------------------------------------\n");
  for (i = 0; i < numFabricantes; i++) {
    printf("| %-15s | %-15s | %-15s | %-3s |\n", fabricantes[i].marca,
           fabricantes[i].site, fabricantes[i].telefone, fabricantes[i].uf);
  }
  printf(
      "-------------------------------------------------------------------\n");
}

void limparTela() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int main() {
  char opcao;
  int numFabricantes = 0;
  int numProdutos = 0;

  Fabricante *fabricantes =
      (Fabricante *)malloc(MAX_FABRICANTES * sizeof(Fabricante));
  Produto *produtos = (Produto *)malloc(MAX_PRODUTOS * sizeof(Produto));

  if (fabricantes == NULL || produtos == NULL) {
    printf("Erro de alocacao de memoria!\n");
    return 1;
  }
  limparTela();
  do {
    printf("<-------x Menu x------->\n\n");
    printf("[1] Cadastrar fabricante\n");
    printf("[2] Cadastrar produto\n");
    printf(
        "[A] Listar todos os produtos em ordem alfabetica crescente (A-Z)\n");
    printf(
        "[Z] Listar todas as marcas em ordem alfabetica decrescente (Z-A)\n");
    printf("[0] Sair\n\n");
    printf("Digite a opcao desejada: ");
    scanf(" %c", &opcao);

    switch (opcao) {
    case '1':
      if (numFabricantes == MAX_FABRICANTES) {
        printf("Limite maximo de fabricantes atingido!\n");
      } else {
        limparTela();
        printf("<-----x Cadastro de Fabricante x----->\n\n");
        cadastrarFabricante(&fabricantes[numFabricantes]);
        numFabricantes++;
        limparTela();
        printf("Fabricante cadastrado com sucesso!\n");
      }
      break;
    case '2':
      if (numProdutos == MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido!\n");
      } else if (numFabricantes == 0) {
        limparTela();
        printf("Nenhum fabricante cadastrado!\n");
      } else {
        limparTela();
        printf("<-----x Cadastro de Produto x----->\n\n");
        cadastrarProduto(&produtos[numProdutos], fabricantes, numFabricantes);
        numProdutos++;
        limparTela();
        printf("Produto cadastrado com sucesso!\n");
      }
      break;
    case 'A':
    case 'a':
      if (numProdutos == 0) {
        limparTela();
        printf("Nenhum produto cadastrado!\n");
      } else {
        limparTela();
        listarProdutosOrdenados(produtos, numProdutos, fabricantes,
                                numFabricantes);
      }
      break;
    case 'Z':
    case 'z':
      if (numFabricantes == 0) {
        printf("Nenhum fabricante cadastrado!\n");
      } else {
        limparTela();
        listarFabricantesOrdenados(fabricantes, numFabricantes);
      }
      break;
    case '0':
      printf("\n\nSaindo...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }

    printf("\n");
  } while (opcao != '0');

  free(fabricantes);
  free(produtos);

  return 0;
}

