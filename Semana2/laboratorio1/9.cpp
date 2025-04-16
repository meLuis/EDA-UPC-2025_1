#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int num;
    do {
        system("cls");
        cout << "Ingrese un numero de 4 digitos: ";
        cin >> num;

        if (num < 1000 || num > 9999) {
            cout << "Por favor ingrese nuevamente un numero de 4 digitos ." << endl;
            system("pause");
        }
    } while (num < 1000 || num > 9999);
    int numIzquierda = num / 100;
    int numDerecha = num % 100;
    cout << " " << endl;
    if (numDerecha > 50) {

        cout << numDerecha << " es mayor que 50" << endl;
    }
    else {
        cout << numDerecha << " es menor que 50" << endl;
    }

    if (numIzquierda % 2 != 0) {
        cout << numIzquierda << " es impar" << endl;
    }
    else {
        cout << numIzquierda << " es par" << endl;
    }

    vector<int> digitos;
    int temp = num;
    while (temp > 0) {
        digitos.push_back(temp % 10);
        temp /= 10;
    }

    sort(digitos.begin(), digitos.end(), [](int a, int b) {
        return a < b;
        });

    cout << endl;
    system("pause");

    return 0;
}