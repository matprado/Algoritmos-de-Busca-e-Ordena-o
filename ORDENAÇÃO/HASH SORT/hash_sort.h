#ifndef HASH_H
#define HASH_H

#define FREE -1
#define DEL -2

int* create_hash_table(int m);
int hash_insert(int* t, int key, int m);
int hash_delete(int *t, int key, int m);
int hash_search(int *t, int key, int m);
int hash_division(int key, int m, int k);
int hash_multi(int key, double A, int m, int k);

#endif