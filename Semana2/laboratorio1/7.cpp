#include <iostream>
using namespace std;
int main() {
    int numero;
    cout << "Ingrese un numero entero de 5 digitos: ";
    cin >> numero;
    if (numero < 10000 || numero > 99999) {
        cout << "El numero no tiene 5 digitos." << endl;
        return 1;
    }
    auto obtenerDigitoCentral = [](int num) -> int {
        return (num / 100) % 10;
    };
    auto esPar = [](int digito) -> bool {
        return digito % 2 == 0;
    };
    int central = obtenerDigitoCentral(numero);
    cout << "El digito del centro es: " << central << endl;
    if (esPar(central)) {
        cout << "Es un numero par\n";
    } else {
        cout << "No es numero par\n";
    }
    return 0;
}
