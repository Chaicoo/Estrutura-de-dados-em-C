#include <stdlib.h>
#include <stdio.h>
#define max 10
//Francisco Gabriel Noleto Lima
void mergeSort(int *vet, int Inicio, int Fim);
int main(int argc, char *argv[]){
    int i, vet[] = { 5, 3, 1, 9, 7, 2, 4, 5, 8, 3};
    printf("\n\nVetor declarado:\n\n");
    printf("| ");
        for(int i = 0; i < max; i++){
                printf("%d | ", vet[i]);
        }
    printf("\n\nVetor ordenado pelo metodo mergeSort\n\n");
    //Exibindo o vetor ordenado
    mergeSort(vet, 0, max - 1);
    printf("| ");
        for(int i = 0; i < max; i++){
            printf("%d | ", vet[i]);
        }
    printf("\n\n");
return 0;
}
//Função que ordena o vetor
void mergeSort(int *vet, int Inicio, int Fim) {
	int i, j, a, metade, *ref;
		if(Inicio == Fim) return;
		metade = (Inicio + Fim ) / 2;
            mergeSort(vet, Inicio, metade);
		    mergeSort(vet, metade + 1, Fim);
        i = Inicio;
		j = metade + 1;
		a = 0;
            ref = (int *) malloc(sizeof (int) * (Fim - Inicio + 1));
                while(i < metade + 1 || j < Fim + 1) {
                    if (i == metade + 1 ){
                        ref[a] = vet[j];
                        j++;
                        a++;
                    }			
                        else {
                            if (j == Fim + 1) {
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
	for(i = Inicio; i <= Fim; i++) {
	    vet[i] = ref[i - Inicio];
	}
}