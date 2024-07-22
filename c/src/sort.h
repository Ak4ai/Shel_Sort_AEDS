#ifndef SORT_H
#define SORT_H

void shellSort(int *arr, int n);
void shellSortHibbard(int *arr, int n);
void shellSortSedgewick(int *arr, int n);
void shellSortTokuda(int *arr, int n);
void shellSortCiura(int *arr, int n);
void shellSortKnuth(int *arr, int n);

int *lerVetor(const char *filename, int numElementos, int maxCasas);
void printArray(int *arr, int size);

#endif
