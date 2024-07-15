#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

#define FILENAME "vetor_gerado.txt"
#define OUTPUTFILE "output.txt"

void clearFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
    }
}

int main() {
    FILE *outfile;
    char resp;
    printf("Deseja LIMPAR o Arquivo [S/N]: ");
    scanf(" %c", &resp);
    resp = toupper(resp);
    if (resp == 'S') {
        clearFile(OUTPUTFILE);
    }

    const int repetitions = 1;

    char imprimirResp;
    printf("Deseja imprimir o vetor ordenado no terminal? [S/N]: ");
    scanf(" %c", &imprimirResp);
    imprimirResp = toupper(imprimirResp);
    int imprimir = (imprimirResp == 'S');

    int numElementos, maxCasas;
    printf("Digite o número de elementos que deseja ler: ");
    scanf("%d", &numElementos);
    printf("Digite o número máximo de casas (1 a 7) para os números: ");
    scanf("%d", &maxCasas);

    outfile = fopen(OUTPUTFILE, "a");
    fprintf(outfile, "[ Elementos = %d ]\n", numElementos);
    
    if (maxCasas < 1) maxCasas = 1;
    if (maxCasas > 7) maxCasas = 7;

    int *arr = lerVetor(FILENAME, numElementos, maxCasas);
    long long durations[6][repetitions];
    long long total_durations[6] = {0};
    const char *algorithm_names[] = {"Shell Sort (gaps padrão)", "Shell Sort (gaps de Hibbard)", "Shell Sort (gaps de Sedgewick)", "Shell Sort (gaps de Tokuda)", "Shell Sort (gaps de Incerpi)", "Shell Sort (gaps de Knuth)"};

    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    for (int alg = 0; alg < 6; ++alg) {
        for (int i = 0; i < repetitions; ++i) {
            int *temp = (int *)malloc(numElementos * sizeof(int));
            memcpy(temp, arr, numElementos * sizeof(int));

            LARGE_INTEGER start, end;
            QueryPerformanceCounter(&start);
            
            switch (alg) {
                case 0:
                    shellSort(temp, numElementos);
                    break;
                case 1:
                    shellSortHibbard(temp, numElementos);
                    break;
                case 2:
                    shellSortSedgewick(temp, numElementos);
                    break;
                case 3:
                    shellSortTokuda(temp, numElementos);
                    break;
                case 4:
                    shellSortIncerpi(temp, numElementos);
                    break;
                case 5:
                    shellSortKnuth(temp, numElementos);
                    break;
                default:
                    break;
            }

            QueryPerformanceCounter(&end);

            durations[alg][i] = (end.QuadPart - start.QuadPart) * 1000000000 / frequency.QuadPart; // em nanosegundos
            total_durations[alg] += durations[alg][i];
            free(temp);
        }

        long long average_duration = total_durations[alg] / repetitions;
        fprintf(outfile, "[ Tempo médio de execução do %s ] : [ %I64d nanosegundos ]\n", algorithm_names[alg], average_duration);

        double sum_square_diff = 0.0;
        for (int i = 0; i < repetitions; ++i) {
            sum_square_diff += (durations[alg][i] - average_duration) * (durations[alg][i] - average_duration);
        }
        double standard_deviation = sqrt(sum_square_diff / repetitions);
        printf("Desvio padrão do %s : %lf nanosegundos\n", algorithm_names[alg], standard_deviation);
    }

    if (imprimir) {
        int opcao;
        printf("\nEscolha um algoritmo para testar:\n");
        printf("1. Shell Sort (gaps padrão)\n");
        printf("2. Shell Sort (gaps de Hibbard)\n");
        printf("3. Shell Sort (gaps de Sedgewick)\n");
        printf("4. Shell Sort (gaps de Tokuda)\n");
        printf("5. Shell Sort (gaps de Incerpi)\n");
        printf("6. Shell Sort (gaps de Knuth)\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        int *temp = (int *)malloc(numElementos * sizeof(int));
        memcpy(temp, arr, numElementos * sizeof(int));

        switch (opcao) {
            case 1:
                shellSort(temp, numElementos);
                break;
            case 2:
                shellSortHibbard(temp, numElementos);
                break;
            case 3:
                shellSortSedgewick(temp, numElementos);
                break;
            case 4:
                shellSortTokuda(temp, numElementos);
                break;
            case 5:
                shellSortIncerpi(temp, numElementos);
                break;
            case 6:
                shellSortKnuth(temp, numElementos);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        if (imprimir) {
            printf("Array ordenado:\n");
            printArray(temp, numElementos);
        }

        free(temp);
    }

    fclose(outfile);
    free(arr);
    return 0;
}