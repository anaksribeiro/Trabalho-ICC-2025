#include <stdio.h>
#include <string.h>

// Função para imprimir
void imprimir_cliente(int id, char nome[100][50], char cpf[100][15]) {
  printf("\nID: %d\nNome: %s\nCPF: %s\n", id, nome[id], cpf[id]);
}

void imprimir_ponto_de_parada(int id, int codigo[5], char cidade[5][50]){
  printf("\nID: %d\nCodigo: %d\nCidade: %s\n", id, codigo[id], cidade[id]);
}

void imprimir_viagem(int id, int cod[5], int qtd_filas[5], char destino[5][50], char origem[5][50], char tipo_onibus[5][50], int tipo_viagem[5], float valor_passagem[5], int qtd_assentos[5], char ponto[5][50]) {
  printf("\n=== Detalhes da Viagem (ID: %d) ===\n", id);
  printf("Código: %d\n", cod[id]);
  printf("Origem: %s\n", origem[id]);
  printf("Destino: %s\n", destino[id]);
  printf("Tipo de Ônibus: %s\n", tipo_onibus[id]);
  printf("Quantidade de Filas: %d\n", qtd_filas[id]);
  printf("Quantidade de Assentos: %d\n", qtd_assentos[id]);
  printf("Valor da Passagem: R$%.2f\n", valor_passagem[id]);

  if (tipo_viagem[id] == -1) {
    printf("Tipo de Viagem: Direta\n");
  } else {
    printf("Tipo de Viagem: Com ponto de parada em %s\n", ponto[tipo_viagem[id]]);
  }
}

void imprimir_passagem(int id_cliente, int id_viagem, char nome_cliente[100][50], char cpf_cliente[100][15], char origem[5][50], char destino[5][50], float valor_passagem[5], int assento) {
  printf("\n=== Passagem de Viagem ===\n");
  printf("Cliente: %s\n", nome_cliente[id_cliente]);
  printf("CPF: %s\n", cpf_cliente[id_cliente]);
  printf("Origem: %s\n", origem[id_viagem]);
  printf("Destino: %s\n", destino[id_viagem]);
  printf("Assento: %d\n", assento);
  printf("Valor: R$%.2f\n", valor_passagem[id_viagem]);
  printf("===========================\n");
}

void exibir_passagens_cliente(char cpf_cliente[100][15], char nome_cliente[100][50], int assento_cliente[100][5][2], int n_passagens_c[100], int index_c, char origem[5][50], char destino[5][50]) {
  char auxcpf[15];
  int encontrado = -1;

  printf("Inserir CPF do cliente: ");
  scanf("%s", auxcpf);

  for (int i = 0; i < index_c; i++) {
    if (strcmp(auxcpf, cpf_cliente[i]) == 0) {
      encontrado = i;
      break;
    }
  }

  if (encontrado == -1) {
    printf("Cliente não encontrado ... retornando ao menu\n");
    return;
  }

  if (n_passagens_c[encontrado] == 0) {
    printf("Cliente não possui passagens compradas ... retornando ao menu\n");
    return;
  }

  printf("\nPassagens de %s (CPF: %s):\n", nome_cliente[encontrado], cpf_cliente[encontrado]);
  for (int i = 0; i < n_passagens_c[encontrado]; i++) {
    if (assento_cliente[encontrado][i][0] != -1) {
      printf("Origem: %s, Destino: %s, Assento: %d\n", origem[i], destino[i], assento_cliente[encontrado][i][0]);
    }
    if (assento_cliente[encontrado][i][1] != -1) {
      printf("Origem: %s, Destino: %s, Assento: %d\n", origem[i], destino[i], assento_cliente[encontrado][i][1]);
    }
  }
  printf("====================================\n");
}

void exibir_viagem(int codviagem, int codigos_viagem[5], int qtd_viagens, char origem[5][50], char destino[5][50], char parada[5][50], char tipo[5], float valor_passagem[5], int qtd_assentos[5], int v_assentos[5][48], int qtd_filas[5]) {
  int index = -1;
  for (int i = 0; i < qtd_viagens; i++) {
    if (codviagem == codigos_viagem[i]) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Viagem não encontrada... retornando ao menu\n");
    return;
  }

  printf("\n=== Detalhes da Viagem ===\n");
  printf("Código: %d\n", codigos_viagem[index]);
  printf("Origem: %s\n", origem[index]);
  printf("Destino: %s\n", destino[index]);
  printf("Tipo: %s\n", tipo[index] == -1 ? "Direto" : "Com Ponto de Parada");
  if (tipo[index] != -1) {
    printf("Ponto de Parada: %s\n", parada[tipo[index]]);
  }
  printf("Valor da Passagem: R$%.2f\n", valor_passagem[index]);
  int c =0;
  printf("Mapa de assentos:\n");
  for (int j = 0 ; j < 12 ; j++) {
    for (int i = 0; i < qtd_filas[index]; i++) {
      printf("%d - %c ", c, v_assentos[index][c] == 0 ? 'L' : 'O');
      c++;
    }
    printf("\n");
  }

  printf("===========================\n");
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

int cadastrar_viagem(int id, int cod[5], int qtd_filas[5],char destino[5][50], char origem[5][50], char tipo_onibus[5][50], int tipo_viagem[5],float valor_passagem[5], int qtd_assentos[5], int index_pp, char ponto[5][50], int codigo[5], int mapa_assentos[5][48]) {
  printf("Insira o código da viagem:");
  scanf("%d", &cod[id]);

  printf("Insira o quantidade de filas:");
  scanf("%d", &qtd_filas[id]);

  if (qtd_filas[id] > 4) {
    printf("Quantidade de filas invalida ... retornando ao menu\n");
    return 0;
  }

  printf("Insira o destino da viagem:");
  scanf("%s", destino[id]);

  printf("Insira o origem da viagem:");
  scanf("%s", origem[id]);

  printf("Insira o tipo da viagem: (-1) Direto (0) com ponto de parada" );
  scanf("%d", &tipo_viagem[id]);

  if (tipo_viagem[id] != -1) {
    if (index_pp ==0) {
      printf("Não existem Pontos de Paradas cadastrados... retornando ao menu\n");
      return 0;
    }
    printf("selecione a parada pelo ID: \n");
    for (int i =0; i< index_pp; i++) {
      imprimir_ponto_de_parada(i,codigo,ponto);
    }

    scanf("%d", &tipo_viagem[id]);

    if (tipo_viagem[id] > index_pp) {
      printf("ponto de parada invalido.. retornando ao menu\n");
      return 0;
    }
  }

  printf("Insira o tipo de onibus: ");
  scanf("%s", tipo_onibus[id]);

  printf("Insira o valor da passagem: ");
  scanf("%f", &valor_passagem[id]);

  qtd_assentos[id] = qtd_filas[id] * 12;

  for (int i =0 ; i< qtd_assentos[id]; i++) {
    mapa_assentos[id][i] = 0;
  }
  return 1;
}

int comprar_passagem(int id, int id_cliente[200], int id_viagem[200], char cpf_cliente[100][15], int codviagem[5], int index_v, int index_c, int qtd_assentos[5], int v_assentos[5][48], int assento_cliente[100][5][2], int assentos_disp[5], int n_passagens_c[100]) {
    char auxcpf[15];
    int auxcodviagem, assento;
    id_cliente[id] = -1;
    id_viagem[id] = -1;

    if (index_c == 0) {
        printf("Não existem clientes cadastrados ... retornando ao menu\n");
        return 0;
    }

    do {
        printf("Inserir CPF do cliente: ");
        scanf("%s", auxcpf);

        for (int i = 0; i < index_c; i++) {
            if (strcmp(auxcpf, cpf_cliente[i]) == 0) {
                id_cliente[id] = i;
                break;
            }
        }

        if (id_cliente[id] == -1) {
            int submenu;
            printf("Cliente não encontrado...\n0 - Digitar CPF novamente\n1 - Voltar ao menu\n");
            scanf("%d", &submenu);
            if (submenu == 1) return 0;
        }
    } while (id_cliente[id] == -1);

    if (index_v == 0) {
        printf("Não existem viagens cadastradas ... retornando ao menu\n");
        return 0;
    }

    do {
        printf("Insira o código da viagem: ");
        scanf("%d", &auxcodviagem);

        for (int i = 0; i < index_v; i++) {
            if (auxcodviagem == codviagem[i]) {
                id_viagem[id] = i;
                break;
            }
        }

        if (id_viagem[id] == -1) {
            int submenu;
            printf("Viagem não encontrada...\n0 - Digitar código novamente\n1 - Voltar ao menu\n");
            scanf("%d", &submenu);
            if (submenu == 1) return 0;
        }
    } while (id_viagem[id] == -1);

    if (n_passagens_c[id_cliente[id]] >= 5 || assento_cliente[id_cliente[id]][id_viagem[id]][1] != -1) {
        printf("Cliente atingiu o limite máximo de passagens... retornando ao menu\n");
        return 0;
    }

    do {
        int c =0;
        printf("Mapa de assentos:\n");
        for (int j = 0 ; j < 12 ; j++) {
          for (int i = 0; i < (qtd_assentos[id_viagem[id]]); i++) {
            printf("%d - %s ", c, v_assentos[id_viagem[id]][i] == 0 ? "L" : "O");
            c++;

          }
          printf("\n");
        }
        printf("Escolha um assento: ");
        scanf("%d", &assento);

        if (assento < 0 || assento >= (qtd_assentos[id_viagem[id]])*12 || v_assentos[id_viagem[id]][assento] != 0) {
            printf("Assento inválido ou já ocupado. Escolha outro.\n");
            assento = -1;
        }
    } while (assento == -1);

    v_assentos[id_viagem[id]][assento] = 1;
  int auxi = 0;
    if (assento_cliente[id_cliente[id]][id_viagem[id]][0] != -1) auxi =1;
    assento_cliente[id_cliente[id]][id_viagem[id]][auxi] = assento;
    n_passagens_c[id_cliente[id]]++;
    assentos_disp[id_viagem[id]]--;

    printf("Passagem comprada com sucesso! Assento %d reservado.\n", assento);
    return 1;
}
void inicializar_dados(int m[100][5][2], int m2[100]) {
    for (int i = 0; i < 100; i++) {
      m2[i]= 0;
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 2; k++) {
          m[i][j][k] = -1;
        }
      }
    }
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

  //viagem
  int index_viagem = 0;
  int codigo_viagem[5];
  int quantidade_de_filas[5];
  char destino[5][50];
  char origem[5][50];
  char tipo_onibus[5][50];
  int tipo_viagem[5]; // if == -1 direto
  float valor_passagem[5];
  int quantide_de_assentos_disp[5];
  int mapa_de_assentos_disp[5][48];

  // passagem
  int index_passagem =0;
  int id_cliente[200];
  int id_viagem[200];
  int assentos_cliente[100][5][2];
  int n_passagens_cliente[100];

  inicializar_dados(assentos_cliente,n_passagens_cliente);
  int menu = 0;
  while (menu != -1) {
    printf("\nMenu:\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Ponto de Parada\n");
    printf("3. Cadastrar Viagem\n");
    printf("4. Comprar Passagem\n");
    printf("5. Exibir Determinada Viagem\n");
    printf("6. Exibir Cliente e Suas Passagens\n");
    printf("-1. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &menu);

    switch (menu) {
      case 1:
        if (index_cliente == 100)
          printf("Número máximo de clientes atingido!\n");
        else {
          cadastrar_cliente(index_cliente, nome_cliente, cpf_cliente);
          index_cliente++;
        }
      break;
      case 2:
        if (index_ponto_de_parada == 5) printf("Número máximo de pontos de partida atingido!\n");
        else{
          cadastrar_ponto_de_parada(index_ponto_de_parada, nome_ponto_de_parada, codigo_ponto_de_parada);
          index_ponto_de_parada++;
        }
        break;
      case 3:
        if (index_viagem == 5) printf("Número máximo de viagens atingido!\n");
        else {
          index_viagem += cadastrar_viagem(index_viagem,codigo_viagem,quantidade_de_filas,destino,origem,tipo_onibus,tipo_viagem,valor_passagem,quantide_de_assentos_disp,index_ponto_de_parada,nome_ponto_de_parada,codigo_ponto_de_parada,mapa_de_assentos_disp);
        }
        break;
      case 4:
        if (comprar_passagem(index_passagem, id_cliente, id_viagem, cpf_cliente, codigo_viagem, index_viagem, index_cliente, quantidade_de_filas, mapa_de_assentos_disp, assentos_cliente, quantide_de_assentos_disp, n_passagens_cliente)) {
          index_passagem++;
        }
      break;
      case 6:
        exibir_passagens_cliente(cpf_cliente, nome_cliente, assentos_cliente, n_passagens_cliente, index_cliente, origem, destino);
      break;
      case 5:
        printf("Digite o código da viagem: ");
        int cod;
        scanf("%d", &cod);
        exibir_viagem(cod, codigo_viagem, index_viagem, origem, destino, nome_ponto_de_parada, tipo_viagem, valor_passagem, quantide_de_assentos_disp, mapa_de_assentos_disp,quantidade_de_filas);
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
