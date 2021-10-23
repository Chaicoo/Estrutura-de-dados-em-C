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
	void inicia(node *LISTA);
	int menu(void);
	void opcao(node *LISTA, int op);
	node *criaNo();
	void insereFim(node *LISTA);
	void insereInicio(node *LISTA);
	void exibe(node *LISTA);
	node *retiraInicio(node *LISTA);
	node *retiraFim(node *LISTA);

int main(void){
 node *LISTA = (node *) malloc(sizeof(node));
 if(!LISTA){
  printf("Não ha memoria disponivel para a alocacao!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;
 
 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
 system("pause");
}
//Criar lista
void inicia(node *LISTA){
 LISTA->prox = NULL;
 tam=0;
}
//Menu da lista
int menu(void){
 int opt;
 
 printf("--MENU--\n");
 printf("(1) Adicionar elemento no inicio\n");
 printf("(2) Adicionar elemento no final\n");
 printf("(3) Retirar do inicio\n");
 printf("(4) Retirar do fim\n");
 printf("(5) Exibir lista\n");
 printf("Opcao: "); 
 	scanf("%d", &opt);
 
 return opt;
}
//Case executando a opção selecionada no menu
void opcao(node *LISTA, int op){
 node *tmp;
 switch(op){
 
  case 1:
   insereInicio(LISTA);
   break;  
   
  case 2:
   insereFim(LISTA);
   break;
  
  case 3:
   tmp= retiraInicio(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
   
  case 4:
   tmp= retiraFim(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  case 5:
   exibe(LISTA);
   break;
  
  default:
   printf("Comando invalido\n\n");
 }
}
//Essa função verifica se a lista esta vazia, se o elemento 1 for null a lista é declarada como vazia
int vazia(node *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}
//Inserir elemento
node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");//Caso na alocação dinamica ocorrer um erro o programa para aqui e da a mensagem da falta de memoria
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);//A função aponta para o proximo elemento, assim cada novo elemento sempre é alocado depois do anterior
  return novo;
 }
}
//Inserir elemento no fim da lista
void insereFim(node *LISTA)
{
 node *novo=aloca();
 novo->prox = NULL;
 
 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  node *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)
   tmp = tmp->prox;
  
  tmp->prox = novo;
 }
 tam++;
}
//Inserir elemento no inicio da lista
void insereInicio(node *LISTA)
{
 node *novo=aloca(); 
 node *oldHead = LISTA->prox;
 
 LISTA->prox = novo;
 novo->prox = oldHead;
 
 tam++;
}
//Exibir lista
void exibe(node *LISTA)
{
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp;
 tmp = LISTA->prox;
 printf("Lista:");
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
//Remover elemento do inicio da lista
node *retiraInicio(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{
  node *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }
    
}
//Remover elemento do fim da lista
node *retiraFim(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja esta vazia\n\n");
  return NULL;
 }else{
  node *ultimo = LISTA->prox,
    *penultimo = LISTA;
    
  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }
  
  penultimo->prox = NULL;
  tam--;
  return ultimo;  
 }
}


