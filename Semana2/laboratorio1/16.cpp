#include <iostream>
using namespace std;

int multiplicarDigitos(int n) {
    if (n < 10)
        return n;
    return (n % 10) * multiplicarDigitos(n / 10);
}

int main() {
    int numero;
    cout << "Ingrese un numero mayor a 3 digitos: ";cin >> numero;

    int resultado = multiplicarDigitos(numero);
    cout << "La multiplicacion de los digitos es: " << resultado << endl;

    return 0;
}
