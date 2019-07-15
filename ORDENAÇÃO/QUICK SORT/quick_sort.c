#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

/* Funcao de ordenacao Quicksort
	Baseado em divisão e conquista, o algoritmo ordena baseado em uma estratégia de escolha para um pivô.
	Se o pivô for o elemento central do vetor, o quicksort funciona como o mergesort;
   Parametros:
      int* v- vetor a ser ordenado
      int  ini- posicao inicial do vetor
      int  fim- posicao final do vetor
      int (*eep) - funcao que retorna a posicao do pivo*/
void quicksort(TIPO* v, int ini, int fim, int (*eep)(int, int)){
	// 0 - caso base (vetores de tamanho 1 ou 0)
	if (ini >= fim) return;
	// 1 - escolha do pivo
	int p = eep(ini, fim);
	// 2 - particiona
	// troca pivo com a primeira posicao
	TIPO tmp = v[p];
	v[p] = v[ini];
	v[ini] = tmp; 
	p = ini; // pivo passa a ser inicio
	// variaveis percorrem listas procurando elementos para troca
	int i = ini+1; // lista 1
	int j = fim;   // lista 2
	while (i < j) {
		while (i < fim && v[i] <= v[p]) i++;
		while (v[j] > v[p]) j--;
		// troca elementos em 'i' e 'j'	
		if (j > i) {
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}
	// a posicao de 'j' sera a posicao ordenada do pivo
	// repare que sera sempre um elemento antes do valor > pivo
	p = j;
	tmp = v[p];
	v[p] = v[ini];
	v[ini] = tmp; 
	// 3 - chamadas recursivas
	quicksort(v, ini, p-1, eep);
	quicksort(v, p+1, fim, eep);
}
/*Funções de escolha do pivô para quick_sort*/
int pivo_inicial(int i, int f){
	return i;
}
int pivo_central(int i, int f){
	return (int) ((i+f)/2.0);
}
int pivo_aleatorio(int i, int f){
	return (rand()%(f-i))+i;
}
