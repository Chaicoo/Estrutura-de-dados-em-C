#include <stdio.h>
#define max 10
//Francisco Gabriel Noleto Lima
void quick(int vet[], int esq, int dir);
int main(){
    int i, vet[] = {5, 8, 3, 1, 6, 2, 4, 9, 7, 5};
    printf("\n\nVetor declarado:\n\n");
    printf("| ");
        for(int i = 0; i < max; i++){
                printf("%d | ", vet[i]);
        }
    quick(vet, 0, max- 1);
    printf("\n\nVetor ordenado pelo metodo quickSort\n\n");
    printf("| ");
        for(int i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n");
    return 0;
}
//Função que ordena o vetor
void quick(int vet[], int esquerda, int direita){
    int i, j, h;    
    int ref = esquerda;     
    for(i = esquerda + 1 ; i <= direita ; i++){        
        j = i;                      
        if(vet[j] < vet[ref]){     
            h = vet[j];               
                while(j > ref){           
                    vet[j] = vet[j - 1];      
                    j--;                    
                }
                vet[j] = h;               
                ref++;                    
        }
    }
        if(ref - 1 >= esquerda){              
            quick(vet, esquerda, ref - 1);      
        }
            if(ref + 1 <= direita){              
                quick(vet, ref + 1, direita);      
            }
 }
