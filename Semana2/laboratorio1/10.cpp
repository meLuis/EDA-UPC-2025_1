#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    vector<int> numeros;
    int numero;
    cout << "Ingresa 10 numeros: "<< endl;

    for (int i = 0; i < 10; ++i) { //la cantidad se puede cambiar
        cout << "Numero " << i + 1 << ": ";
        cin >> numero;
        numeros.push_back(numero);
    }

    sort(numeros.begin(), numeros.end(), [](int a, int b) {
        return a < b;
        });

    cout << " " << endl;
    cout << "Numeros ordenados de forma ascendente:";
    cout << " " << endl;
    for (int n : numeros) {
        cout << n << " ";
    }

    cout << endl;
    return 0;
}