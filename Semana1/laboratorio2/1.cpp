#include <iostream>
using namespace std;

template <typename T>
T menor(T a, T b, T c) {
    T menor = a;
    if (b < menor) menor = b;
    if (c < menor) menor = c;
    return menor;
}

int main() {
    int x, y, z;
    cout << "Ingrese el primer valor: ";
    cin >> x;
    cout << "Ingrese el segundo valor: ";
    cin >> y;
    cout << "Ingrese el tercer valor: ";
    cin >> z;
    cout << "El menor valor es: " << menor(x, y, z) << endl;
    return 0;
}
