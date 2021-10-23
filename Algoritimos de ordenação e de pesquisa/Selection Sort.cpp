#include <stdio.h>
#include <stdlib.h>

void selectionSort(int vet[],int MAX){

    int min, aux;

    for(int i=0;i<MAX-1;i++){
        min=i;
        for(int j=i+1 ; j<MAX ; j++){
            if(vet[min] > vet[j])
                min=j;
        }
            if(i!=min){
                aux=vet[i];
                vet[i]=vet[min];
                vet[min]=aux;
            }
    }
}
int main(){

    int MAX=10;
    int Vet[] = {3, 0, 1, 8, 7, 2, 5, 4, 9, 6} ;

    selectionSort(Vet,MAX);

    printf("\n ");

    for(int i=0;i<MAX;i++){
        printf("%d\n ",Vet[i]);
    }

    printf("\n\n\n");

    system("pause");
    return 0;
}
