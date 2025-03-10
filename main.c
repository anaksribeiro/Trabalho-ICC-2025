#include <stdio.h>
#include <string.h>

// Função para imprimir cliente
void imprimir_cliente(int id, char nome[100][50], char cpf[100][15]) {
  printf("\nID: %d\nNome: %s\nCPF: %s\n", id, nome[id], cpf[id]);
}

void imprimir_ponto_de_parada(int id, int codigo[5], char cidade[5][50]){
  printf("\nID: %d\nCodigo: %d\nCidade: %s\n", id, codigo[id], cidade[id]);
}
// Funções para cadastrar
void cadastrar_cliente(int id, char nome[100][50], char cpf[100][15]) {
  printf("Insira o nome do cliente: ");
  scanf("%s", nome[id]);

  printf("Insira o CPF do cliente: ");
  scanf("%14s", cpf[id]);
}

void cadastrar_ponto_de_parada(int id, char ponto[5][50], int codigo[5]){
  printf("Insira o código do ponto de parada:");
  scanf("%d", &codigo[id]);

  printf("Insira a cidade do ponto de parada:");
  scanf("%s", ponto[id]);
}

int main() {
  // Clientes
  int index_cliente = 0; // max = 100
  char nome_cliente[100][50];
  char cpf_cliente[100][15];

  //pontos de parada
  int index_ponto_de_parada = 0; //max = 5
  char nome_ponto_de_parada[5][50];
  int codigo_ponto_de_parada[5];

  //
  int menu = 0;
  while (menu != -1) {
    printf("\nMenu:\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Ponto de Parada\n");
    printf("-1. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &menu);

    switch (menu) {
      case 1:
        if (index_cliente == 100)
          printf("Número máximo de clientes atingido!\n");
        else {
          cadastrar_cliente(index_cliente, nome_cliente, cpf_cliente);
          imprimir_cliente(index_cliente, nome_cliente, cpf_cliente);
          index_cliente++;
        }
      break;
      case 2:
        if (index_ponto_de_parada == 5) printf("Número máximo de pontos de partida atingido!\n");
        else{
          cadastrar_ponto_de_parada(index_ponto_de_parada, nome_ponto_de_parada, codigo_ponto_de_parada);
          imprimir_ponto_de_parada(index_ponto_de_parada, codigo_ponto_de_parada,nome_ponto_de_parada);
          index_ponto_de_parada++;
        }
        break;
      case -1:
        printf("Saindo...\n");
      break;

      default:
        printf("Opção inválida!\n");
    }
  }

  return 0;
}
