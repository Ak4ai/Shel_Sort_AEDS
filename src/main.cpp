#include "Sort.hpp"

using namespace std;

int main() {
    ofstream outfile("output.txt", ios_base::app);
    char resp;
    cout << "Deseja LIMPAR o Arquivo [S/N]: ";
    cin >> resp;
    resp = toupper(resp);
    if(resp == 'S')
        AlgoritmosSort::limparArq();
    vector<int> arr = AlgoritmosSort::gerarVetor();
    outfile << endl << "[MÉTODOS EM C++]" << endl;

    // Teste Shell Sort com gaps padrão
    cout << "Array antes do Shell Sort (gaps padrão):" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    AlgoritmosSort::shellSort(arr);
    cout << "Array depois do Shell Sort (gaps padrão):" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Teste Shell Sort com gaps de Hibbard
    arr = AlgoritmosSort::gerarVetor();
    cout << "Array antes do Shell Sort (gaps de Hibbard):" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    AlgoritmosSort::shellSortHibbard(arr);
    cout << "Array depois do Shell Sort (gaps de Hibbard):" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Teste Shell Sort com gaps de Sedgewick
    arr = AlgoritmosSort::gerarVetor();
    cout << "Array antes do Shell Sort (gaps de Sedgewick):" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    AlgoritmosSort::shellSortSedgewick(arr);
    cout << "Array depois do Shell Sort (gaps de Sedgewick):" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    outfile.close();
    return 0;
}
