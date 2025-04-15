#include <iostream>
using namespace std;

bool esPrimo(int n, int i = 2) {
    if (n <= 2)
        return n == 2;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    return esPrimo(n, i + 1);
}

int main() {
    int numero;
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;

    if (esPrimo(numero)) {
        cout << numero << " es primo." << endl;
    } else {
        cout << numero << " no es primo." << endl;
    }

    return 0;
}
