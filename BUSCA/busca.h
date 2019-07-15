#ifndef BUSCA_H
#ifndef BUSCA_H

#define TIPO int /*Customizar o tipo de dados*/

/*AS BUSCAS RETORNAM A POSIÇÃO NO VETOR*/
int busca_sequencial(TIPO *vet, TIPO chave); /*Para qualquer vetor: complexidade O(n)*/	
int busca_binaria(TIPO *vet, TIPO chave, int comeco, int fim); /*Para vetores ordenados: complexidade O(log(n))*/
int* gera_vetor (int tam, int min, int max);
int* gera_vetor_ordenado(int tam, int min, int max);
void imprime_vetor(TIPO *v, int N);

#endif