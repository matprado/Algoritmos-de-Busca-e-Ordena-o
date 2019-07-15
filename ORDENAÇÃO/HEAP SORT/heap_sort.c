#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"


/*Encontra a posição correta de um dos elementos da heap(MAXHEAP)*/
void max_heapify(TIPO *vet, int pai, int n){
	TIPO aux;
	int filho1 = (2*pai)+1, filho2 = (2*pai)+2, escolhido;
	if(filho1 >= n) return; /*Ultrapassa o vetor*/
	else if(filho2 >= n){
		if(vet[filho1] > vet[pai]){
			aux = vet[filho1];
			vet[filho1] = vet[pai];
			vet[pai] = aux; /*troca o pai com o filho*/
			max_heapify(vet, filho1, n); /*repete o processo com o filho trocado*/ 
		}
	}
	else if(vet[filho1] > vet[pai] || vet[filho2] > vet[pai]){
		if(vet[filho2] > vet[filho1]){	//SEPARAR OS IFS
			escolhido = filho2;
		}/*escolhe o maior filho para ser trocado com o pai*/
		else escolhido = filho1;
		aux = vet[escolhido];
		vet[escolhido] = vet[pai];
		vet[pai] = aux; /*troca o pai com o filho*/	
		max_heapify(vet, escolhido, n); /*repete o processo com o filho trocado*/
	}
}
/*Monta um max heap num vetor.
 Lembrando que a posição 0 do vetor não é usada!*/
void build_maxheap(TIPO *vet, int n){
	int pai = (int)((n-1)/2); /*O último pai da árvore é o pai do último filho*/ /*0-1,2; 1-3,4; 2-5,6; 3-7,8*/
	for(int i = pai; i >= 0; i--){
		max_heapify(vet, i, n); /*Arruma a posição de todos os nós pais na árvore*/
	}
}
/*Algoritmo de árvore binária baseado em três passos:
1º) montar MAXHEAP;
2º) ordenar o maior elemento;
3º) remontar heap;*/
void heap_sort(TIPO *vet, int n){	
	build_maxheap(vet, n);
	TIPO aux;
	int u = n-1;
	while(u > 0){
		aux = vet[u];
		vet[u] = vet[0];
		vet[0] = aux;
		max_heapify(vet, 0, u--);
	}
}
