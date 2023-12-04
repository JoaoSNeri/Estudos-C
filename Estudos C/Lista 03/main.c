#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define UF_SIZE 3

// Structs
typedef struct {
    char marca[50];
    char site[100];
    char telefone[20];
    char uf[UF_SIZE];
} Fabricante;

typedef struct {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

// Variaveis globais
Fabricante fabricantes[MAX_FABRICANTES];
int numFabricantes = 0;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

// Prototipos de funções
void LimpartTela();
void aguardarEnter();
void cadastrarFabricante();
void cadastrarProduto();
void listarTodasMarcas();
void listarTodosProdutos();
void listarProdutosEstado();
void listarProdutosMarca();
void listarEstadoProdutoMaisCaro();
void listarFabricanteProdutoMaisBarato();
void listarProdutosOrdemCrescenteValor();
void listarProdutosOrdemCrescenteLucro();
void listarProdutosOrdemCrescentePercentualLucro();

// Função principal
int main() {
    int opcao;

    do {
        printf("\n=== Menu ===\n\n");
        printf("[1] Cadastrar Fabricante\n");
        printf("[2] Cadastrar Produto\n");
        printf("[3] Listar todas as marcas\n");
        printf("[4] Listar todos os produtos\n");
        printf("[5] Listar os produtos de um determinado estado\n");
        printf("[6] Listar os produtos de uma determinada marca\n");
        printf("[7] Apresentar o(s) estado(s) onde estÃ¡ registrado o produto mais caro\n");
        printf("[8] Apresentar o(s) fabricante(s) onde estÃ¡ registrado o produto mais barato\n");
        printf("[9] Listar todos os produtos em ordem crescente de valor\n");
        printf("[10] Listar todos os produtos em ordem crescente de maior lucro\n");
        printf("[11] Listar todos os produtos em ordem crescente de maior percentual de lucro\n");
        printf("[0] Sair do programa\n");

        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                cadastrarFabricante();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                listarTodasMarcas();
                break;
            case 4:
                listarTodosProdutos();
                break;
            case 5:
                listarProdutosEstado();
                break;
            case 6:
                listarProdutosMarca();
                break;
            case 7:
                listarEstadoProdutoMaisCaro();
                break;
            case 8:
                listarFabricanteProdutoMaisBarato();
                break;
            case 9:
                listarProdutosOrdemCrescenteValor();
                break;
            case 10:
                listarProdutosOrdemCrescenteLucro();
                break;
            case 11:
                listarProdutosOrdemCrescentePercentualLucro();
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para cadastrar um fabricante
void cadastrarFabricante() {
    if (numFabricantes == MAX_FABRICANTES) {
        printf("Limite maximo de fabricantes atingido.\n");
        return;
    }
    
    limparTela();

    printf("=== Cadastro de Fabricante ===\n");

    printf("Marca: ");
    fgets(fabricantes[numFabricantes].marca, sizeof(fabricantes[numFabricantes].marca), stdin);
    fabricantes[numFabricantes].marca[strcspn(fabricantes[numFabricantes].marca, "\n")] = '\0';

    printf("Site: ");
    fgets(fabricantes[numFabricantes].site, sizeof(fabricantes[numFabricantes].site), stdin);
    fabricantes[numFabricantes].site[strcspn(fabricantes[numFabricantes].site, "\n")] = '\0';

    printf("Telefone: ");
    fgets(fabricantes[numFabricantes].telefone, sizeof(fabricantes[numFabricantes].telefone), stdin);
    fabricantes[numFabricantes].telefone[strcspn(fabricantes[numFabricantes].telefone, "\n")] = '\0';

    printf("UF: ");
    fgets(fabricantes[numFabricantes].uf, sizeof(fabricantes[numFabricantes].uf), stdin);
    fabricantes[numFabricantes].uf[strcspn(fabricantes[numFabricantes].uf, "\n")] = '\0';

    numFabricantes++;
    printf("\nFabricante cadastrado com sucesso.\n");
    
    limparTela();
}

// Função para cadastrar um produto
void cadastrarProduto() {
    if (numProdutos == MAX_PRODUTOS) {
        printf("Limite mÃ¡ximo de produtos atingido.\n");
        return;
    }
	
	limparTela();
	
    printf("=== Cadastro de Produto ===\n");

    printf("Descricao: ");
    fgets(produtos[numProdutos].descricao, sizeof(produtos[numProdutos].descricao), stdin);
    produtos[numProdutos].descricao[strcspn(produtos[numProdutos].descricao, "\n")] = '\0';

    printf("Peso: ");
    scanf("%f", &produtos[numProdutos].peso);
    getchar();

    printf("Valor de Compra: ");
    scanf("%f", &produtos[numProdutos].valorCompra);
    getchar();

    printf("Valor de Venda: ");
    scanf("%f", &produtos[numProdutos].valorVenda);
    getchar();

    // Calculos automaticos
    produtos[numProdutos].valorLucro = produtos[numProdutos].valorVenda - produtos[numProdutos].valorCompra;
    produtos[numProdutos].percentualLucro = (produtos[numProdutos].valorLucro / produtos[numProdutos].valorCompra) * 100;

    printf("Marca do Fabricante: ");
    fgets(produtos[numProdutos].fabricante.marca, sizeof(produtos[numProdutos].fabricante.marca), stdin);
    produtos[numProdutos].fabricante.marca[strcspn(produtos[numProdutos].fabricante.marca, "\n")] = '\0';

    printf("UF do Fabricante: ");
    fgets(produtos[numProdutos].fabricante.uf, sizeof(produtos[numProdutos].fabricante.uf), stdin);
    produtos[numProdutos].fabricante.uf[strcspn(produtos[numProdutos].fabricante.uf, "\n")] = '\0';

    numProdutos++;
    printf("Produto cadastrado com sucesso.\n");
}

// Funçãoo para listar todas as marcas
void listarTodasMarcas() {
	
	limparTela();
	
    printf("=== Lista de Marcas ===\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("%s\n", fabricantes[i].marca);
    }
}

// Função para listar todos os produtos
void listarTodosProdutos() {

	limparTela();
	
    printf("=== Lista de Produtos ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("DescriÃ§Ã£o: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}

// Função para listar os produtos de um determinado estado
void listarProdutosEstado() {
    char estado[UF_SIZE];
    
    limparTela();

    printf("Digite o estado: ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';
    
    limparTela();

    printf("=== Lista de Produtos do Estado %s ===\n", estado);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.uf, estado) == 0) {
            printf("DescriÃ§Ã£o: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
        }
    }
}

// Função para listar os produtos de uma determinada marca
void listarProdutosMarca() {
    char marca[50];
    
    limparTela();

    printf("Digite a marca: ");
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = '\0';
    
    limparTela();

    printf("=== Lista de Produtos da Marca %s ===\n", marca);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.marca, marca) == 0) {
            printf("DescriÃ§Ã£o: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
        }
    }
}

// Função para listar o(s) estado(s) onde estÃ¡ registrado o produto mais caro
void listarEstadoProdutoMaisCaro() {
    float maiorValor = 0;
    char estadoMaisCaro[UF_SIZE];

    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > maiorValor) {
            maiorValor = produtos[i].valorVenda;
            strcpy(estadoMaisCaro, produtos[i].fabricante.uf);
        }
    }

    printf("=== Estado(s) onde estÃ¡ registrado o produto mais caro ===\n");
    printf("%s\n", estadoMaisCaro);
}

// Função para listar o(s) fabricante(s) onde estÃ¡ registrado o produto mais barato
void listarFabricanteProdutoMaisBarato() {
    float menorValor = produtos[0].valorVenda;

    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].valorVenda < menorValor) {
            menorValor = produtos[i].valorVenda;
        }
    }

    printf("=== Fabricante(s) onde estÃ¡ registrado o produto mais barato ===\n");
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda == menorValor) {
            printf("Marca: %s\n", produtos[i].fabricante.marca);
        }
    }
}

// Função para listar todos os produtos em ordem crescente de valor
void listarProdutosOrdemCrescenteValor() {
    Produto temp;

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    
    limparTela();

    printf("=== Lista de Produtos em Ordem Crescente de Valor ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("DescriÃ§Ã£o: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}

// Função para listar todos os produtos em ordem crescente de maior lucro
void listarProdutosOrdemCrescenteLucro() {
    Produto temp;

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    
    limparTela();

    printf("=== Lista de Produtos em Ordem Crescente de Maior Lucro ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("DescriÃ§Ã£o: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}

// Função para listar todos os produtos em ordem crescente de maior percentual de lucro
void listarProdutosOrdemCrescentePercentualLucro() {
    Produto temp;

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].percentualLucro > produtos[j + 1].percentualLucro) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    
    limparTela();

    printf("=== Lista de Produtos em Ordem Crescente de Maior Percentual de Lucro ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("DescriÃ§Ã£o: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}
