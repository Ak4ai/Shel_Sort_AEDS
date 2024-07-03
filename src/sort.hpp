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
    static vector<int> gerarVetor();
private:
    static void swap(int& a, int& b);
};

#endif
