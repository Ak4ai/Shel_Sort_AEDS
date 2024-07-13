#include "Sort.hpp"
#include <algorithm> // Para usar a função reverse
#include <vector>
#include <fstream>
#include <random>
#include <sstream>

void AlgoritmosSort::limparArq() {
    std::ofstream outfile("output.txt", std::ios::trunc); // Abre o arquivo em modo de truncamento para limpar seu conteúdo
    outfile.close();
}

void AlgoritmosSort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void AlgoritmosSort::shellSort(vector<int>& arr) {
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
}

void AlgoritmosSort::shellSortHibbard(vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps;
    // Generate the Hibbard sequence (2^k - 1)
    for (int k = 1; (1 << k) - 1 < n; ++k) {
        gaps.push_back((1 << k) - 1);
    }
    std::reverse(gaps.begin(), gaps.end());
    // Perform Shell Sort using the Hibbard gaps
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
}

void AlgoritmosSort::shellSortSedgewick(vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps;
    for (int k = 0; ; ++k) {
        int gap;
        if (k % 2 == 0) {
            gap = 9 * (1 << (2*k)) - 9 * (1 << k) + 1;
        } else {
            gap = 8 * (1 << k) - 6 * (1 << ((k+1)/2)) + 1;
        }
        if (gap > n) break;
        gaps.push_back(gap);
    }
    std::reverse(gaps.begin(), gaps.end());
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
}

void AlgoritmosSort::shellSortTokuda(vector<int>& arr) {
    int n = arr.size();

    // Geração dos gaps de Tokuda
    vector<int> gaps;
    for (int k = 1; ; ++k) {
        int gap = static_cast<int>(9 * (pow(2, k) - 1) / 5);
        if (gap >= n) break;
        gaps.push_back(gap);
    }
    reverse(gaps.begin(), gaps.end());

    // Ordenação usando os gaps de Tokuda
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
}


void AlgoritmosSort::shellSortIncerpi(vector<int>& arr) {
    int n = arr.size();

    // Geração dos gaps de Incerti
    vector<int> gaps;
    for (int k = 1; ; ++k) {
        int gap = static_cast<int>(pow(2, k/2));
        if (gap >= n) break;
        gaps.push_back(gap);
    }
    reverse(gaps.begin(), gaps.end());

    // Ordenação usando os gaps de Incerti
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
}

// Função para gerar a sequência de gaps de Knuth
std::vector<int> generateKnuthSequence(int size) {
    std::vector<int> sequence;
    int k = 1;
    int gap = (std::pow(3, k) - 1) / 2;
    while (gap < size) {
        sequence.push_back(gap);
        k++;
        gap = (std::pow(3, k) - 1) / 2;
    }
    return sequence;
}

// Função para ordenação usando Shell Sort com gaps de Knuth
void AlgoritmosSort::shellSortKnuth(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps = generateKnuthSequence(n);

    for (int gapIndex = gaps.size() - 1; gapIndex >= 0; gapIndex--) {
        int gap = gaps[gapIndex];
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


std::vector<int> AlgoritmosSort::gerarVetorWIP(int tam, int max) {
    std::vector<int> vec;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, max);
    for (int i = 0; i < tam; ++i) {
        vec.push_back(dis(gen));
    }
    return vec;
}

void AlgoritmosSort::salvarVetor(const std::vector<int>& arr, const std::string& filename) {
    std::ofstream outfile(filename);
    for (int num : arr) {
        outfile << num << " ";
    }
    outfile << std::endl;
    outfile.close();
}

std::vector<int> AlgoritmosSort::lerVetor(const std::string& filename, int numElementos, int maxCasas) {
    std::vector<int> vec;
    std::ifstream infile(filename);
    std::string line;
    int count = 0;
    while (getline(infile, line) && count < numElementos) {
        std::stringstream ss(line);
        std::string numStr;
        while (ss >> numStr && count < numElementos) {
            // Truncate the number to the maximum number of decimal places
            int num = std::stoi(numStr.substr(0, maxCasas));
            vec.push_back(num);
            ++count;
        }
    }
    infile.close();
    return vec;
}

void AlgoritmosSort::printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}