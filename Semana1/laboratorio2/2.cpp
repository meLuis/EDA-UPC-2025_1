#include <iostream>
using namespace std;

template <typename T>
T factorial(T n) {
    T resultado = 1;
    for (T i = 1; i <= n; ++i)
        resultado *= i;
    return resultado;
}

int main() {
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    cout << "El factorial de " << num << " es: " << factorial(num) << endl;
    return 0;
}
