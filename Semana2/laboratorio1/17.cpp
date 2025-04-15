#include <iostream>
using namespace std;

int sumaPares(int n) {
    if (n == 0)
        return 0;
    int digito = n % 10;
    if (digito % 2 == 0)
        return digito + sumaPares(n / 10);
    else
        return sumaPares(n / 10);
}

int main() {
    int numero;
    cout << "Ingrese un numero positivo: ";cin >> numero;

    int resultado = sumaPares(numero);
    cout << "La suma de los digitos pares es: " << resultado << endl;

    return 0;
}
