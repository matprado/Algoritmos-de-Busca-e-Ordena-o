#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

/* Funcao de ordenacao Mergesort:
	Algoritmo de divisão e conquista onde se ordena, primeiro, pequenos vetores, e depois os junta formando um só vetor ordenado;	
   Parametros:
      int* v - vetor a ser ordenado
      int  ini - posição inicial do vetor
      int fim - posição final do vetor*/
void merge_sort(TIPO *vet, int ini, int fim){
	if(fim <= ini)	return;
	int meio = (int) (ini+fim)/2;	
	merge_sort(vet, ini, meio);
	merge_sort(vet, meio+1, fim);
	merge(vet, ini, meio, fim);
}
/*Função merge(intercala):
 Pega dois vetores previamente ordenados e os intercala formando um só vetor ordenado*/
void merge(TIPO *vet, int ini, int meio, int fim){
	TIPO *aux = (TIPO*)malloc((fim-ini+1) * sizeof(TIPO));
	int i, j, k;	
    for(i=ini, j=meio+1, k=0; i<=meio && j<=fim; k++){	//Ordena os dois 'blocos'
    	if(vet[i] < vet[j])
    		aux[k] = vet[i++];
    	else
    		aux[k] = vet[j++];
    }
    while(i <= meio){  //Caso ainda haja elementos na primeira metade
        aux[k++] = vet[i++];
    }
    while(j <= fim){   //Caso ainda haja elementos na segunda metade
        aux[k++] = vet[j++];
    }
    for(k = ini; k <= fim; k++){//Move os elementos de volta para o vetor original
        vet[k] = aux[k-ini];
    }
    free(aux);
}
