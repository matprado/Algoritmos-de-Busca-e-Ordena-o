#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void bubble_sort(int* vet, int n){
	int i, j, temp;
	for (i = 0; i < n - 1; i++){
        for (j = (i+1); j < n; j++){
            if (vet[j] < vet[i]){
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}	