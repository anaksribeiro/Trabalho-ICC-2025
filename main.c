#include <stdio.h>
#include <string.h>

// Função para imprimir cliente
void imprimir_cliente(int id, char nome[100][50], char cpf[100][15]) {
  printf("\nID: %d\nNome: %s\nCPF: %s\n", id, nome[id], cpf[id]);
}

// Função para cadastrar cliente
void cadastrar_cliente(int id, char nome[100][50], char cpf[100][15]) {

  printf("Insira o nome do cliente: ");
  scanf("%s", nome[id]);

  printf("Insira o CPF do cliente: ");
  scanf("%14s", cpf[id]);
}

int main() {
  // Clientes
  int index_cliente = 0; // max = 100
  char nome_cliente[100][50];
  char cpf_cliente[100][15];

  //pontos de parada

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
        if (id)
      case -1:
        printf("Saindo...\n");
      break;

      default:
        printf("Opção inválida!\n");
    }
  }

  return 0;
}
