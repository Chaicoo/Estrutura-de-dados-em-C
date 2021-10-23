#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Francisco Gabriel Noleto Lima
/*Estrutura de dados lineares:
Lista | Fila | Pilha*/
struct Node{
  int num;
  struct Node *prox;
}; 
  typedef struct Node node;

    int tam;
//Lista
    void inicia(node *ESTRUTURA);
    int menu(void);
    void opcao(node *ESTRUTURA, int op);
    node *criaNo();
    void insereFim(node *ESTRUTURA);
    void insereInicio(node *ESTRUTURA);
    void exibe(node *ESTRUTURA);
    node *retiraInicio(node *ESTRUTURA);
    node *retiraFim(node *ESTRUTURA);

int main(void){
  node *ESTRUTURA = (node *) malloc(sizeof(node));
  if(!ESTRUTURA){
    printf("Nao ha memoria disponivel para a alocacao!\n");
    exit(1);
  }else{
  inicia(ESTRUTURA);
  int opt;
  
  do{
    opt=menu();
    opcao(ESTRUTURA,opt);
  }while(opt);

  free(ESTRUTURA);
  return 0;
   }
  }
//Criar estrutura
void inicia(node *ESTRUTURA){
  ESTRUTURA->prox = NULL;
  tam=0;
  }
//Menu 
int menu(void){
  int opt;
  
	  printf("--MENU--\n");
	  printf("(0) Sair\n");
	  printf("(1) Zerar\n");
	  printf("\n\n--LISTA--\n\n");
	  printf("(2) Adicionar elemento no inicio\n");
	  printf("(3) Adicionar elemento no final\n");
	  printf("(4) Retirar do inicio\n");
	  printf("(5) Retirar do fim\n");
	  printf("(6) Exibir lista\n");
	  printf("\n\n--FILA--\n\n");
	  printf("(7) Adicionar Elemento na Fila\n");
	  printf("(8) Retirar Elemento da Fila\n");
	  printf("(9) Exibir fila\n");
	  printf("\n\n--PILHA--\n\n");
	  printf("(10) Adcionar elemento na pilha\n");
	  printf("(11) Remover elemento da pilha\n");
	  printf("(12) Exibir PILHA\n");
	  printf("Opcao: "); 
	    scanf("%d", &opt);
  
  return opt;
  }
//Case executando a opção selecionada no menu
void opcao(node *ESTRUTURA, int op){
  node *tmp;
    switch(op){
  
      case 0:
        printf("\n\nFIM!\n\n");
        free(ESTRUTURA);
      break; 
      
      case 1:
		free(ESTRUTURA);
  		inicia(ESTRUTURA);
      break;
    
      case 2:
        insereInicio(ESTRUTURA);
      break;  
      
      case 3:
        insereFim(ESTRUTURA);
      break;
      
      case 4:
        tmp= retiraInicio(ESTRUTURA);
        printf("Retirado: %3d\n\n", tmp->num);
      break;
      
      case 5:
        tmp= retiraFim(ESTRUTURA);
        printf("Retirado: %3d\n\n", tmp->num);
      break;
      
      case 6:
        exibe(ESTRUTURA);
      break;
      
      case 7:
      	insereFim(ESTRUTURA);//Sera adcionado no final pois se trata de uma fila
      break;
      
      case 8:
      	tmp= retiraInicio(ESTRUTURA);//Sera removido do inicio pois  se trata de uma fila
        printf("Retirado: %3d\n\n", tmp->num);
      break;
      
      case 9:
      	exibe(ESTRUTURA);
      break;
      
      case 10:
      	insereFim(ESTRUTURA);//Sera adcionado no fim pois se trata de uma pilha
      break;
      
      case 11:
      	 tmp= retiraFim(ESTRUTURA);//Sera retirado do fim pois se trata de uma pilha
        printf("Retirado: %3d\n\n", tmp->num);
      break;
      
      case 12:
      	exibe(ESTRUTURA);
      break;
      
      default:
      printf("\n\nComando invalido\n\n");
   }
  }
//Essa função verifica se a estrutura esta vazia, se o elemento 1 for null a estrutura é declarada como vazia
int vazia(node *ESTRUTURA)
{
  if(ESTRUTURA->prox == NULL)
    return 1;
  else
    return 0;
  }
//Inserir elemento
node *aloca(){
  node *novo=(node *) malloc(sizeof(node));
  if(!novo){
    printf("Sem memoria disponivel!\n");//Caso na alocação dinamica ocorrer um erro o programa para aqui e da a mensagem da falta de memoria
    exit(1);
  }else{
    printf("Novo elemento: "); scanf("%d", &novo->num);//A função aponta para o proximo elemento, assim cada novo elemento sempre é alocado depois do anterior
    return novo;
   }
  }
//Inserir elemento no fim da estrutura
void insereFim(node *ESTRUTURA){
  node *novo=aloca();
  novo->prox = NULL;
  
  if(vazia(ESTRUTURA))
    ESTRUTURA->prox=novo;
  else{
    node *tmp = ESTRUTURA->prox;
    
    while(tmp->prox != NULL)
    tmp = tmp->prox;
    
    tmp->prox = novo;
    }
  tam++;
  }
//Inserir elemento no inicio da estrutura
void insereInicio(node *ESTRUTURA){
  node *novo=aloca(); 
  node *oldHead = ESTRUTURA->prox;
  
  ESTRUTURA->prox = novo;
  novo->prox = oldHead;
  
  tam++;
  }
//Exibir estrutura
void exibe(node *ESTRUTURA){
  if(vazia(ESTRUTURA)){
    printf("Estrutura vazia!\n\n");
    return ;
   }
 
  node *tmp;
  tmp = ESTRUTURA->prox;
  printf("Elementos:");
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
//Remover elemento do inicio da estrutura
node *retiraInicio(node *ESTRUTURA){
  if(ESTRUTURA->prox == NULL){
    printf("Lista ja esta vazia\n");
    return NULL;
  }else{
    node *tmp = ESTRUTURA->prox;
    ESTRUTURA->prox = tmp->prox;
    tam--;
    return tmp;
   }
  }
//Remover elemento do fim da estrutura
node *retiraFim(node *ESTRUTURA){
  if(ESTRUTURA->prox == NULL){
    printf("Lista ja esta vazia\n\n");
    return NULL;
  }else{
    node *ultimo = ESTRUTURA->prox,
      *penultimo = ESTRUTURA;
      
    while(ultimo->prox != NULL){
    penultimo = ultimo;
    ultimo = ultimo->prox;
    }
  
    penultimo->prox = NULL;
    tam--;
    return ultimo;  
  }
}
//Esvaziar estrutura
void libera(node *ESTRUTURA)
{
 if(!vazia(ESTRUTURA)){
  node *proxNode,
     *atual;
  
  atual = ESTRUTURA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}


