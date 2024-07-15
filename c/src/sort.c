#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSortHibbard(int *arr, int n) {
    int k = 1;
    int gap = (1 << k) - 1;
    while (gap < n) {
        k++;
        gap = (1 << k) - 1;
    }
    while (--k >= 1) {
        gap = (1 << k) - 1;
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSortSedgewick(int *arr, int n) {
    int k = 0;
    int gap;
    while (1) {
        if (k % 2 == 0) {
            gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1;
        } else {
            gap = 8 * (1 << k) - 6 * (1 << ((k + 1) / 2)) + 1;
        }
        if (gap >= n) break;
        k++;
    }
    while (--k >= 0) {
        if (k % 2 == 0) {
            gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1;
        } else {
            gap = 8 * (1 << k) - 6 * (1 << ((k + 1) / 2)) + 1;
        }
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSortTokuda(int *arr, int n) {
    int k = 1;
    int gap = (int)(9 * (pow(2, k) - 1) / 5);
    while (gap < n) {
        k++;
        gap = (int)(9 * (pow(2, k) - 1) / 5);
    }
    while (--k >= 1) {
        gap = (int)(9 * (pow(2, k) - 1) / 5);
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSortIncerpi(int *arr, int n) {
    int gaps[] = {1, 3, 7, 21, 48, 112, 336, 861, 1968, 4592, 13776, 33936, 86961, 198768, 463792, 1391376, 3346188, 9572352, 23358342, 58548857};
    int k = sizeof(gaps) / sizeof(gaps[0]) - 1;
    while (gaps[k] >= n) k--;
    while (k >= 0) {
        int gap = gaps[k];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        k--;
    }
}

void shellSortKnuth(int *arr, int n) {
    int k = 1;
    int gap = 1;
    while (gap < n) {
        k++;
        gap = (int)(pow(3, k) - 1) / 2;
    }
    while (--k >= 1) {
        gap = (int)(pow(3, k) - 1) / 2;
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int *lerVetor(const char *filename, int numElementos, int maxCasas) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    int *arr = (int *)malloc(numElementos * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    char format[20];
    snprintf(format, sizeof(format), "%%%dd", maxCasas);

    for (int i = 0; i < numElementos; i++) {
        if (fscanf(file, format, &arr[i]) != 1) {
            fprintf(stderr, "Erro ao ler o elemento %d do arquivo\n", i + 1);
            free(arr);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return arr;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
