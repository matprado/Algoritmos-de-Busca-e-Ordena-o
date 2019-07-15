#ifndef HEAP_H
#define HEAP_H

#define TIPO int

void max_heapify(TIPO *vet, int pai, int n);
void build_maxheap(TIPO *vet, int n);
void heap_sort(TIPO *vet, int n);

#endif