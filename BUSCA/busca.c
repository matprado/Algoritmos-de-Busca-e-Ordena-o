#include "busca.h"



int busca_sequencial(TIPO *vet, int n, TIPO chave){
	for(int i=0; i<n; i++){
		if(vet[i] == chave) return i;
	}
	return -1;	//ERRO
}

/*PRECISA ESTAR ORDENADO!*/
int busca_binaria(TIPO *vet, TIPO chave, int comeco, int fim){
	int centro = (comeco+fim)/2;
	if(comeco > fim) return -1;
	if(vet[centro] == chave) return centro;
	else{
		if(chave < vet[centro])
			return busca_binaria(vet, chave, comeco, centro-1);
		else
			return busca_binaria(vet, chave, centro+1, fim);
	}
}

/* Funcao que gera um vetor de inteiros aleatorios
	em um determinado intervalo de valores
   Parametros:
	int tam - tamanho do vetor a ser gerado
	int min - valor minimo
	int max - valor maximo
   Retorno:
	int*    - endereco do vetor na heap
*/
int* gera_vetor(int tam, int min, int max){
	// verifica problemas
	if (tam < 1 || min > max) return NULL;
	int* vet = (int *) malloc(sizeof(int)*tam);
	// verifica se houve problema na alocacao
	if (vet == NULL) return NULL;
	for (int i = 0; i < tam; i++) {
		// ex. min = 0, max = 5, [0, 4] = [0,4+1] = [0, 5]
		//     min = 3, max = 8, [0, 5] + 3 = [3, 8]
		int val = (rand()%(max-min+1)) + min;
		vet[i] = val;
	}
	return vet;
}

int* gera_vetor_ordenado(int tam, int min, int max){
	// verifica problemas
	if (tam < 1 || min > max) return NULL;
	int* vet = (int *) malloc(sizeof(int)*tam);
	// verifica se houve problema na alocacao
	if (vet == NULL) return NULL;
	// TODO: melhorar isso pra ficar uniformemente distribuido
	int val = min;
	vet[0] = 0;
	for (int i = 0; i < tam; i++) {
		vet[i] = val;
		val = vet[i]+rand()%3;
		if (val > max) val = max;
	}
	return vet;
}

/* Imprime vetor de inteiros
   Parametros
	int* v - vetor
	int  N - tamanho do vetor
*/
void imprime_vetor(TIPO *v, int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);
	printf("\n");
}