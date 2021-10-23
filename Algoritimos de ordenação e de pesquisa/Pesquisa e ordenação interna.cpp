#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define max 4//Definição do tamanho do vetor
//Francisco Gabriel Noleto Lima
//Cabeçalho das funções de ordenação
void leVet(int vet[]);
void insertionSort(int vet[]);
void selectionSort(int vet[]);
void shellSort(int *vet);
void mergeSort(int *vet, int Inicio, int Fim);
void quick(int vet[], int esquerda, int direita);
void bubblesort(int vet[], int n);
//Cabeçalho das funções de pesquisa
int pesquisaSeq(int vet[], int pesquisa);
int pesquisaBin(int *vet, int chave, int final);
//Cabeçalho das funções que imprimem o resultado
void exibeInsertion();
void exibeSelection();
void exibeShell();
void exibeMerge();
void exibeQuick();
void exibeBubble();
void exibeSeq();
void exibeBin();
//Variaveis de escopo global
int a, i, j, ref;
int main(int argc, char *argv[]){  
setlocale(LC_ALL, "portuguese");   
    int op;
        //Menu do programa
        printf("\n\n------------------------------MENU------------------------------\n\n");
        printf("O vetor deve ser declarado pelo usuario e deve ter 10 elementos.\n\n");
        printf("Metodos de ordenação:\n\n");
        printf("(1) insertion\n");
        printf("(2) selection\n");
        printf("(3) shell\n");
        printf("(4) merge\n");
        printf("(5) quick\n");
        printf("(6) bubble\n");
        printf("\nMetodos de pesquisa:\n\n");
        printf("(7) pesquisa sequencial\n");
        printf("(8) pesquisa binaria\n");
        printf("\nOpcao: "); 	
    scanf("%d", &op);
    //Switch case que ira executar apenas a função selecionada
    switch(op){   
    case 1:
        printf("\nOrdenação por insertion\n\n");
        exibeInsertion();
    break;  
    case 2:
        printf("\nOrdenação por selection\n\n");
        exibeSelection();
    break;    
    case 3:
        printf("\nOrdenação por shell\n\n");
        exibeShell();
    break;   
    case 4:
        printf("\nOrdenação por merge\n\n");
        exibeMerge();
    break;       
    case 5:
        printf("\nOrdenação por quick\n\n");
        exibeQuick();
    break;
    case 6:
        printf("\nOrdenação por bubble\n\n");
        exibeBubble();
    break;
    case 7:
        printf("\nPesquisa sequencial\n\n");
        exibeSeq();
    break;
    case 8:
        printf("\nPesquisa binaria\n\n");
        exibeBin();
    break;
    default:
        printf("\nOpção inexistente, por favor escolha uma opção entre 1 e 8.\n\n");
    }  
return 0;
}
//Função que le o vetor 
void leVet(int vet[]){
    //Usando for para ler os 10 elementos do vetor
        for(i = 0; i < max; i++){
            printf("Digite um valor: ");
            scanf("%d", &vet[i]);
        }
    //Exibição do vetor declarado
    printf("\n\nVetor declarado pelo usuario:\n\n");
    printf("| ");
        for(i = 0; i < max; i++){
                printf("%d | ", vet[i]);
        }
}
//Execução das funções de ordenação
//insertionSort
void insertionSort(int vet[]){
        for(i = 1; i < max; i++){
            ref  = vet[i];
            j = i - 1;
                while((j >= 0) && (ref < vet[j])){
                    vet[j + 1] = vet[j];
                    j--;
                }
                    vet[j + 1] = ref;
        }
}
//selectionSort
void selectionSort(int vet[]){
    int minimo;
    for(i = 0; i < max - 1 ; i++){
        minimo = i;
            for( j=i+1 ; j<max ; j++){
                if(vet[minimo] > vet[j])
                    minimo=j;
            }
                    if(i!=minimo){
                        ref=vet[i];
                        vet[i]=vet[minimo];
                        vet[minimo]=ref;
                    }
    }
}
//shellSort
void shellSort(int *vet) {
    int inicio = 1;
    while(inicio < max) {
        inicio = 3 * inicio + 1;
    }
        while ( inicio > 1) {
            inicio /= 3;
                for(i = inicio; i < max; i++) {
                    ref = vet[i];
                    j = i - inicio;
                        while (j >= 0 && ref < vet[j]) {
                            vet [j + inicio] = vet[j];
                            j -= inicio;
                        }
                            vet [j + inicio] = ref;
                }
        }
}
//mergeSort
void mergeSort(int *vet, int inicio, int final) {
	int meio, *ref;
		if(inicio == final) return;
		meio = (inicio + final ) / 2;
            mergeSort(vet, inicio, meio);
		    mergeSort(vet, meio + 1, final);
        i = inicio;
		j = meio + 1;
		a = 0;
            ref = (int *) malloc(sizeof (int) * (final - inicio + 1));
                while(i < meio + 1 || j < final + 1) {
                    if (i == meio + 1 ){
                        ref[a] = vet[j];
                        j++;
                        a++;
                    }			
                        else {
                            if (j == final + 1) {
                                ref[a] = vet[i];
                                i++;
                                a++;
                            }
                                else {
                                    if (vet[i] < vet[j]) {
                                        ref[a] = vet[i];
                                        i++;
                                        a++;
                                    }
                                        else {
                                            ref[a] = vet[j];
                                            j++;
                                            a++;
                                        }
                                }
                        }
                }
	for(i = inicio; i <= final; i++) {
	    vet[i] = ref[i - inicio];
	}
free(ref);//Libera da memoria o espaço ocupado pelo ponteiro para evitar erros
}
//quickSort
void quickSort(int vet[], int esquerda, int direita){
        ref = esquerda; 
        for(i = esquerda + 1; i <= direita; i++){        
            j = i;                      
            if(vet[j] < vet[ref]){     
                a = vet[j];               
                    while(j > ref){           
                        vet[j] = vet[j - 1];      
                        j--;                    
                    }
                vet[j] = a;               
                ref++;                    
            }
        }
    if(ref-1 >= esquerda){              
        quickSort(vet, esquerda, ref - 1);      
    }
        if(ref+1 <= direita){              
            quickSort(vet, ref + 1, direita);      
        }
 }
 //bubble sort
void bubblesort(int vet[], int n){  
    for (i = n - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                    if (vet[j] > vet[j + 1]) {
                        ref = vet[j];
                        vet[j] = vet[j + 1];
                        vet[j + 1] = ref;
                    }
            }
    }
}
//Funções de pesquisa
//Pesquisa sequencial
int pesquisaSeq(int vet[], int pesquisa){
        for(i = 0; i < max; i++){
            if(vet[i] == pesquisa){
                return i;
            }
        }
     return -1;//Se a função não retornar valor ela deve retornar -1 para exibir que o elemento não existe no vetor   
}
//Pesquisa binária
int pesquisaBin(int *vet, int chave, int final){
    int inicio = 0, meio = ((inicio + final) / 2);//A variavel meio funcionara como pivo da pesquisa
        while(inicio <= final){
            if(chave == vet[meio]){
                return meio;//Se o elemento pesquisado for o do meio a pesquisa retorna o meio
            }
                else{
                    if(chave < vet[meio]){
                        final = meio -1;
                    }
                        else{
                            inicio = meio +1;
                        }
                }
            meio = ((inicio + final) / 2);
        }
    return -1;//Se a função não retornar valor ela deve retornar -1 para exibir que o elemento não existe no vetor
}
//Funções para imprimir o vetor
//Imprime insertion
void exibeInsertion(){
    int vet[max];
    leVet(vet);
    printf("\n\nVetor ordenado pelo metodo insertionSort\n\n");
    //Exibindo o vetor ordenado
    insertionSort(vet);
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
    return;
}
//Imprime selection
void exibeSelection(){
    int vet[max];
    leVet(vet);
    printf("\n\nVetor ordenado pelo metodo selectionSort\n\n");
    //Exibindo o vetor ordenado
    selectionSort(vet);
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
    return;
}
//Imprime Shell
void exibeShell(){
    int vet[max];
    leVet(vet);
    printf("\n\nVetor ordenado pelo metodo shellSort\n\n");
    //Exibindo o vetor ordenado
    shellSort(vet);
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
    return;
}
//Imprime Merge
void exibeMerge(){
    int vet[max];
    leVet(vet);
    printf("\n\nVetor ordenado pelo metodo mergeSort\n\n");
    //Exibindo o vetor ordenado
    mergeSort(vet, 0, max - 1);
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
    return;
}
//Imprime Quick
void exibeQuick(){
    int vet[max];
    leVet(vet);
    printf("\n\nVetor ordenado pelo metodo quickSort\n\n");
    //Exibindo o vetor ordenado
    quickSort(vet, 0, max - 1);
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
    return;
}
//Imprime Bubble
void exibeBubble(){
    int vet[max];
    leVet(vet);
    printf("\n\nVetor ordenado pelo metodo bubblesort\n\n");
    //Exibindo o vetor ordenado
    bubblesort(vet, max);
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
    return;
}
//Exibição do resultado da pesquisa sequencial
void exibeSeq(){
    int vet[max], posicao, pesquisa;
    leVet(vet);
    printf ("\n\nDigite o elemento desejado: ");
    scanf("%d", &pesquisa);// lê o elemento a ser pesquisado 
    posicao = pesquisaSeq(vet, pesquisa);
        if (posicao == -1)/* Se na função pesquisaSeq o returno for -1 então o valor não foi encontrado*/{
            printf("\n\nO elemento digitado nao existe no vetor.\n\n");
        }
            else{
                printf("\n\nO elemento %d esta na posicao de numero %d\n\n", pesquisa, posicao+1);    
            }
}
//Exibição do resultado da pesquisa binária
void exibeBin(){
    int vet[max], pesquisa, posicao;
    leVet(vet);
    quickSort(vet, 0, max - 1);
    printf("\n\nVetor ordenado pelo metodo quickSort\n\n");
    //Exibindo o vetor ordenado
    printf("| ");
        for(i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf ("\n\nDigite o elemento desejado: ");
    scanf("%d", &pesquisa);// lê o elemento a ser pesquisado
    posicao = pesquisaBin(vet, pesquisa, max);
    if (posicao == -1)/* Se na função pesquisaSeq o returno for -1 então o valor não foi encontrado*/{
            printf("\n\nO elemento digitado nao existe no vetor.\n\n");
        }
            else{
                printf("\n\nO elemento %d esta na posicao de numero %d\n\n", pesquisa, posicao+1);    
            }
}
