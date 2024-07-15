#include "Sort.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ofstream outfile("output.txt", ios_base::app);
    char resp;
    cout << "Deseja LIMPAR o Arquivo [S/N]: ";
    cin >> resp;
    resp = toupper(resp);
    if (resp == 'S')
        AlgoritmosSort::limparArq();

    const int repetitions = 1; // Número de repetições para cada algoritmo

    
    char imprimirResp;
    cout << "Deseja imprimir o vetor ordenado no terminal? [S/N]: ";
    cin >> imprimirResp;
    imprimirResp = toupper(imprimirResp);
    bool imprimir = (imprimirResp == 'S');
    
    int numElementos, maxCasas;
    cout << "Digite o número de elementos que deseja ler: ";
    cin >> numElementos;
    cout << "Digite o número máximo de casas (1 a 7) para os números: ";
    cin >> maxCasas;

    outfile << "[ Vetor Ordenado Inversamente ]  " ;
    outfile << "[ Elementos = " << numElementos << "]" << endl;
    
    if (maxCasas < 1) maxCasas = 1;
    if (maxCasas > 7) maxCasas = 7;

    // Ler o vetor do arquivo
    vector<int> arr = AlgoritmosSort::lerVetor("descending_array.txt", numElementos, maxCasas);
    
    vector<vector<long long>> durations(6, vector<long long>(repetitions, 0)); // Para armazenar as durações de cada algoritmo
    vector<long long> total_durations(6, 0); // Para armazenar os tempos totais de cada algoritmo

    // Nomes dos algoritmos
    vector<string> algorithm_names = {"Shell Sort (gaps padrão)", "Shell Sort (gaps de Hibbard)", "Shell Sort (gaps de Sedgewick)", "Shell Sort (gaps de Tokuda)", "Shell Sort (gaps de Incerpi)", "Shell Sort (gaps de Knuth)"};
    vector<int> temp; // Declaração do vetor temp fora do loop

    // Testar cada algoritmo
    for (int alg = 0; alg < 6; ++alg) {
        for (int i = 0; i < repetitions; ++i) {
            vector<int> temp = arr; // Cópia do vetor original
            auto start = chrono::high_resolution_clock::now();
            switch(alg) {
                case 0:
                    AlgoritmosSort::shellSort(temp);
                    break;
                case 1:
                    AlgoritmosSort::shellSortHibbard(temp);
                    break;
                case 2:
                    AlgoritmosSort::shellSortSedgewick(temp);
                    break;
                case 3:
                    AlgoritmosSort::shellSortTokuda(temp);
                    break;
                case 4:
                    AlgoritmosSort::shellSortIncerpi(temp);
                    break;
                case 5:
                    AlgoritmosSort::shellSortKnuth(temp);
                    break;
                default:
                    break;
            }
            auto end = chrono::high_resolution_clock::now();
            long long duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            durations[alg][i] = duration;
            total_durations[alg] += duration;
        }

        // Calcular média
        long long average_duration = total_durations[alg] / repetitions;
        outfile << "[ Tempo médio de execução do " << algorithm_names[alg] << " ] : [ " << average_duration << " nanosegundos ]\n";

        // Calcular desvio padrão
        double sum_square_diff = accumulate(durations[alg].begin(), durations[alg].end(), 0.0, [average_duration](double acc, long long val) { return acc + (val - average_duration) * (val - average_duration); });
        double standard_deviation = sqrt(sum_square_diff / repetitions);
        cout << "Desvio padrão do " << algorithm_names[alg] << " : " << standard_deviation << " nanosegundos" << endl;
    }

    if(imprimir){
        
    int opcao;
    cout << "\nEscolha um algoritmo para testar:\n";
    cout << "1. Shell Sort (gaps padrão)\n";
    cout << "2. Shell Sort (gaps de Hibbard)\n";
    cout << "3. Shell Sort (gaps de Sedgewick)\n";
    cout << "4. Shell Sort (gaps de Tokuda)\n";
    cout << "5. Shell Sort (gaps de Incerpi)\n";
    cout << "6. Shell Sort (gaps de Knuth)\n";
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1: {
            vector<int> temp = arr; // Cópia do vetor original
            AlgoritmosSort::shellSort(temp);

            if (imprimir) {
                cout << "Array ordenado pelo Shell Sort (gaps padrão):" << endl;
                AlgoritmosSort::printArray(temp);
            }
            break;
        }
        case 2: {
            vector<int> temp = arr; // Cópia do vetor original
            AlgoritmosSort::shellSortHibbard(temp);

            if (imprimir) {
                cout << "Array ordenado pelo Shell Sort (gaps de Hibbard):" << endl;
                AlgoritmosSort::printArray(temp);
            }
            break;
        }
        case 3: {
            vector<int> temp = arr; // Cópia do vetor original
            AlgoritmosSort::shellSortSedgewick(temp);

            if (imprimir) {
                cout << "Array ordenado pelo Shell Sort (gaps de Sedgewick):" << endl;
                AlgoritmosSort::printArray(temp);
            }
            break;
        }
        case 4: {
            vector<int> temp = arr; // Cópia do vetor original
            AlgoritmosSort::shellSortTokuda(temp);

            if (imprimir) {
                cout << "Array ordenado pelo Shell Sort (gaps de Tokuda):" << endl;
                AlgoritmosSort::printArray(temp);
            }
            break;
        }
        case 5: {
            vector<int> temp = arr; // Cópia do vetor original
            AlgoritmosSort::shellSortIncerpi(temp);

            if (imprimir) {
                cout << "Array ordenado pelo Shell Sort (gaps de Incerpi):" << endl;
                AlgoritmosSort::printArray(temp);
            }
            break;
        }
        case 6: {
            vector<int> temp = arr; // Cópia do vetor original
            AlgoritmosSort::shellSortKnuth(temp);

            if (imprimir) {
                cout << "Array ordenado pelo Shell Sort (gaps de Knuth):" << endl;
                AlgoritmosSort::printArray(temp);
            }
            break;
        }
        default:
            cout << "Opção inválida!" << endl;
            break;
    }
    }

    outfile.close();
    return 0;
}