#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <cctype>
#include <algorithm>

using namespace std;

class AlgoritmosSort {
public:
    static void limparArq();
    static void shellSort(vector<int>& arr);
    static void shellSortHibbard(vector<int>& arr);
    static void shellSortSedgewick(vector<int>& arr);
    static void shellSortTokuda(std::vector<int>& arr);
    static void shellSortIncerpi(std::vector<int>& arr);
    static vector<int> gerarVetorWIP(int tam, int max);
    static void salvarVetor(const vector<int>& arr, const string& filename);
    static vector<int> lerVetor(const string& filename, int numElementos, int maxCasas); // Adicione esta linha
    static void printArray(const vector<int>& arr);
    static void shellSortKnuth(std::vector<int>& arr);
private:
    static void swap(int& a, int& b);
};

#endif
