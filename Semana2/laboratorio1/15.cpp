#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int limite;
    cout << "Ingrese la cantidad de numeros Fibonacci a mostrar: ";cin >> limite;

    for (int i = 1; i <= limite; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
