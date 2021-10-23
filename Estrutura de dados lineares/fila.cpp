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
	void opcao(node *FILA, int op);
	void inicia(node *FILA);
	int vazia(node *FILA);
	node *aloca();
	void insere(node *FILA);
	node *retira(node *FILA);
	void exibe(node *FILA);
	void libera(node *FILA);


int main(void)
{
 node *FILA = (node *) malloc(sizeof(node));
 if(!FILA){
  printf("Não ha memoria disponivel para a alocacao!\n");
  exit(1);
 }else{
 inicia(FILA);
 int opt;

 do{
  opt=menu();
  opcao(FILA,opt);
 }while(opt);

 free(FILA);
 return 0;
 }
}

int menu(void)
{
 int opt;
 
 printf("--MENU--\n");
 printf("(1) Adicionar Elemento na Fila\n");
 printf("(2) Retirar Elemento da Fila\n");
 printf("(3) Exibir fila\n");
 printf("Opcao: "); 
 	scanf("%d", &opt);

 return opt;
}

void opcao(node *FILA, int op)
{
 node *tmp;
 switch(op){

  case 1:
   insere(FILA);
   break;

  case 2:
   tmp= retira(FILA);
   if(tmp != NULL){
    printf("Retirado: %3d\n\n", tmp->num);
    free(tmp);
   }
   break;

  case 3:
   exibe(FILA);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}

void inicia(node *FILA)
{
 FILA->prox = NULL;
 tam=0;
}

int vazia(node *FILA)
{
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}

void insere(node *FILA)
{
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(FILA))
  FILA->prox=novo;
 else{
  node *tmp = FILA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}

node *retira(node *FILA)
{
 if(FILA->prox == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  node *tmp = FILA->prox;
  FILA->prox = tmp->prox;
  tam--;
  return tmp;
 }

}

void exibe(node *FILA)
{
 if(vazia(FILA)){
  printf("Fila vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = FILA->prox;
 printf("Fila :");
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



