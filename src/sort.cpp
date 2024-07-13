#include "Sort.hpp"
#include <algorithm> // Adicionamos esta linha para usar a função reverse

void AlgoritmosSort::limparArq() {
    ofstream outfile("output.txt", ios::trunc); // Abre o arquivo em modo de truncamento para limpar seu conteúdo
    outfile.close();
}

void AlgoritmosSort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void AlgoritmosSort::shellSort(vector<int>& arr) {
    auto start = chrono::steady_clock::now();

    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    ofstream outfile("output.txt", ios_base::app);
    outfile << "[ Tempo de execução do Shell Sort (gaps padrão) ] : [ " << duration.count() << " nanosegundos ]\n";
    outfile.close();
}

void AlgoritmosSort::shellSortHibbard(vector<int>& arr) {
    auto start = chrono::steady_clock::now();

    int n = arr.size();
    vector<int> gaps;
    for (int k = 1; pow(2, k) - 1 < n; ++k) {
        gaps.push_back(pow(2, k) - 1);
    }
    reverse(gaps.begin(), gaps.end());

    for (int gap : gaps) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    ofstream outfile("output.txt", ios_base::app);
    outfile << "[ Tempo de execução do Shell Sort (gaps de Hibbard) ] : [ " << duration.count() << " nanosegundos ]\n";
    outfile.close();
}

void AlgoritmosSort::shellSortSedgewick(vector<int>& arr) {
    auto start = chrono::steady_clock::now();

    int n = arr.size();
    vector<int> gaps;
    for (int k = 0; (pow(4, k) + 3 * pow(2, k - 1) + 1) < n; ++k) {
        if (k % 2 == 0) {
            gaps.push_back(pow(4, k) + 3 * pow(2, k - 1) + 1);
        } else {
            gaps.push_back(pow(2, k) + 1);
        }
    }
    reverse(gaps.begin(), gaps.end());

    for (int gap : gaps) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    ofstream outfile("output.txt", ios_base::app);
    outfile << "[ Tempo de execução do Shell Sort (gaps de Sedgewick) ] : [ " << duration.count() << " nanosegundos ]\n";
    outfile.close();
}

vector<int> AlgoritmosSort::gerarVetor(int tam, int max) {
    vector<int> vec;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, max);

    for (int i = 0; i < tam; ++i) {
        vec.push_back(dis(gen));
    }

    return vec;
}