#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Francisco Gabriel Noleto Lima
struct Node{
  int num;
  struct Node *prox;
  };
    typedef struct Node node;
    
    int tam;
    int menu(void);
    void inicia(node *PILHA);
    void opcao(node *PILHA, int op);
    void exibe(node *PILHA);
    void push(node *PILHA);
    node *pop(node *PILHA);

int main(void){
  node *PILHA = (node *) malloc(sizeof(node));
  if(!PILHA){
    printf("Nao ha memoria disponivel para a alocacao!\n");
    exit(1);
  }else{
  inicia(PILHA);
  int opt;

  do{
    opt=menu();
    opcao(PILHA,opt);
  }while(opt);

  free(PILHA);
  return 0;
  }
  }

  void inicia(node *PILHA)
  {
  PILHA->prox = NULL;
  tam=0;
  }

  int menu(void)
  {
  int opt;

  printf("--MENU--\n\n");
  printf("(0) Sair\n");
  printf("(1) Exibir PILHA\n");
  printf("(2) Adcionar elemento na pilha\n");
  printf("(3) Remover elemento da pilha\n");
  printf("Opcao: "); scanf("%d", &opt);

  return opt;
  }

void opcao(node *PILHA, int op){
  node *tmp;
  switch(op){
    
    case 0:
      printf("\n\nFIM!\n\n");
      free(PILHA);
    break;

    case 1:
      exibe(PILHA);
    break;

    case 2:
      push(PILHA);
    break;

    case 3:
      tmp= pop(PILHA);
        if(tmp != NULL)
          printf("Retirado: %3d\n\n", tmp->num);
    break;

    default:
    printf("\n\nComando invalido\n\n");
  }
  }

  int vazia(node *PILHA){
  if(PILHA->prox == NULL)
    return 1;
  else
    return 0;
  }

node *aloca(){
  node *novo=(node *) malloc(sizeof(node));
  if(!novo){
    printf("Nao ha memoria disponivel para a alocacao!\n");
    exit(1);
  }else{
    printf("Novo elemento: "); scanf("%d", &novo->num);
    return novo;
  }
}

void exibe(node *PILHA){
  if(vazia(PILHA)){
    printf("PILHA vazia!\n\n");
    return ;
  }

  node *tmp;
  tmp = PILHA->prox;
  printf("PILHA:");
  while( tmp != NULL){
    printf("%5d", tmp->num);
    tmp = tmp->prox;
  }
  printf("\n        ");
  int count;
  for(count=0 ; count < tam ; count++)
    printf("  ^  ");
  printf("\nOrdem:");
  for(count=0 ; count < tam ; count++)
    printf("%5d", count+1);


  printf("\n\n");
  }

void push(node *PILHA){
  node *novo=aloca();
  novo->prox = NULL;

  if(vazia(PILHA))
    PILHA->prox=novo;
  else{
    node *tmp = PILHA->prox;

    while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
  }
  tam++;
  }

node *pop(node *PILHA){
  if(PILHA->prox == NULL){
    printf("PILHA ja vazia\n\n");
    return NULL;
  }else{
    node *ultimo = PILHA->prox,
                *penultimo = PILHA;

    while(ultimo->prox != NULL){
    penultimo = ultimo;
    ultimo = ultimo->prox;
    }

    penultimo->prox = NULL;
    tam--;
    return ultimo;
    }
  }