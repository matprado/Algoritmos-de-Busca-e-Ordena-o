#include <stdio.h>
#include <stdlib.h>
#include "radix_sort.h"

void radixsort8bits(STRUCT *A, int n){
	int i,j,shift;
	// 1 - alocar vetores de contagem e auxiliares
	int C[256] = {0};
	int pos[256];
	STRUCT *copy = (STRUCT *) malloc(sizeof(STRUCT)*n);
	// Radix sort - executa counting sort 
	// 		varias vezes usando base 2 e 8 bits por bloco
	for (shift = 0; shift <= 24; shift+=8) {
		// 2 - Counting sort : contagem + copia
		for (j = 0; j < n; j++) {
			int k = (A[j].key >>shift) & 255; // extrai 8 bits 
			C[k]++; // conta
			// aproveita e cria o vetor copia
			copy[j] = A[j];
		}
		// 3 - Counting sort : contagem acumulada
		//    percorre o vetor de contagem C 
		pos[0] = 0;
		for (i = 1; i < 256; i++) {
			pos[i] = pos[i-1] + C[i-1];
			C[i-1] = 0; // zera contagem para a proxima passada		
		}
		// 4 - Counting sort : copia elementos nas suas posicoes corretas
		for (j = 0; j < n; j++) {
			int k = (copy[j].key >>shift) & 255; // extrai 8 bits
			A[pos[k]] = copy[j]; // copia na posicao correta
			pos[k]++; // incrementa posicao
		}
	}
	free(copy);
}