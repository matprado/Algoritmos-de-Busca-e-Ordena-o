#ifndef QUICK_H
#define QUICK_H

#define TIPO int

void quicksort(TIPO* v, int ini, int fim, int (*eep)(int, int)); /*eep = função de escolha do pivô*/
int pivo_inicial(int i, int f);
int pivo_central(int i, int f);
int pivo_aleatorio(int i, int f);

#endif