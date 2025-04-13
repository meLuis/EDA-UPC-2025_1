#include <iostream>
using namespace std;

template <typename T>
T suma(T a, T b) { return a + b; }

template <typename T>
T resta(T a, T b) { return a - b; }

template <typename T>
T multi(T a, T b) { return a * b; }

template <typename T>
T division(T a, T b) { return b != 0 ? a / b : 0; }

int main() {
    double a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    cout << "Suma: " << suma(a, b) << endl;
    cout << "Resta: " << resta(a, b) << endl;
    cout << "Multiplicacion: " << multi(a, b) << endl;
    cout << "Division: " << division(a, b) << endl;
    return 0;
}
