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
    mapa_assentos[id][i] = 1;
  }
  return 1;
}

int comprar_passagem(int id, int id_cliente[200], int id_viagem[200],char cpf[100], int codviagem[5],int index_v, int index_c, int qtd_assentos[5], int v_assentos[5][48], int assento_cliente[100][5][2], int assentos_disp[5], int n_passagens_c[100]){
  char auxcpf[15];
  int auxcodviagem;
  id_cliente[id] = -1;
  id_viagem[id] = -1;

  do{
    if (index_c == 0) {
      printf("não existem clientes cadastrados ... retornando ao menu");
      return 0;
    }
    printf("inserir cpf cliente: ");
    scanf("%s", cpf);

    for(int i = 0; i < index_c; i++) {
      if(strcmp(cpf, cpf[i]) == 0) id_cliente = i;
    }

    if (id_cliente[id] == -1) {
      int submenu = 0;
      printf("cliente não encontrado...\n");
      printf("0- digitar CPF novamente\n");
      printf("1- voltar ao menu\n");
      scanf("%d", &submenu);
      if (submenu == 0) return 0;

    }
  }while (id_cliente[id] == -1);

  do {
    if (index_v == 0) {
      printf("não existem viagens cadastradas ... retornando ao menu");
      return 0;
    }

    printf("Insira o codigo da viagem: ");
    scanf("¨%d", &auxcodviagem);

    for (int i = 0; i < index_v; i++) {
      if (auxcodviagem == codviagem[i]) id_viagem[i] = i;
    }

    if (id_viagem[id] == -1) {
      int submenu = 0;
      printf("viagem não encontrada...\n");
      printf("0- digitar codigo novamente\n");
      printf("1- voltar ao menu\n");
      scanf("%d", &submenu);
      if (submenu == 0) return 0;
    }
  }while (id_viagem[id] != -1);

  int assento = -1;
 do {

   for (int i =0; i< qtd_assentos[id]; i++) {
     printf("%d-", i);
     if (v_assentos[i] == 0) printf("disponível\n");
     else printf("indisponivel\n");
   }

   scanf("%d", &assento);

   if (v_assentos[assento] == 0) assento =-1;

 }while(assento ==-1);

  if(n_passagens_c[id_cliente] == 5 || assento_cliente[id_cliente][id_viagem][2] != -1) {
    printf("cliente já atingiu o limite de passagens ... retornando ao menu");
    return 0;
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
  int passagens_cliente[100][5];
  int assentos_cliente[100][5][2];
  int n_passagens_cliente[100];

  int menu = 0;
  while (menu != -1) {
    printf("\nMenu:\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Ponto de Parada\n");
    printf("3. Cadastrar Viagem\n");
    printf("4. Comprar Passagem\n");
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
      case -1:
        printf("Saindo...\n");
      break;

      default:
        printf("Opção inválida!\n");
    }
  }

  return 0;
}
