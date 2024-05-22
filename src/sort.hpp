#ifndef sort_HPP
#define sort_HPP
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <cmath>
#include <cctype>
#include <algorithm> // Adicionado para usar a função reverse
using namespace std;

class AlgoritmosSort {
public:
    static void limparArq();
    static void shellSort(vector<int>& arr);
    static void shellSortHibbard(vector<int>& arr);
    static void shellSortSedgewick(vector<int>& arr);
    static vector<int> gerarVetor();
private:
    static void swap(int& a, int& b);
};

#endif