#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

/* Funcao de ordenacao Insertion sort,
	ordena os elementos do vetor passado por parametro
   Parametros:
      int* v - vetor a ser ordenado
      int  n - tamanho do vetor*/
void insertion_sort(TIPO *vet, int n){
	int i=1, j, chave;
	while(i < n){
		j=i-1;
		chave = vet[i];
		while(j >= 0 && chave < vet[j]){
			vet[j+1] = vet[j];
			j--;
		}	
		vet[j+1] = chave;
		i++;
	}
}	