#include <iostream>
using namespace std;
bool esPrimo(int n, int divisor = 2) {
    if (n <= 2) return (n == 2);
    if (n % divisor == 0) return false;
    if (divisor * divisor > n) return true;
    return esPrimo(n, divisor + 1);
}
void mostrarPrimos(int n, int actual = 2) {
    if (actual >= n) return;
    if (esPrimo(actual)) {
        cout << actual << " ";
    }
    mostrarPrimos(n, actual + 1);
}
int main() {
    int limite;
    while (true) {
        system("cls");  // Limpia la pantalla
        cout << "Ingrese un numero menor a 1000: ";
        cin >> limite;
        cout << "  " << endl;
        if (limite <= 0 || limite >= 1000) {
            cout << "Intente de nuevo " << endl;
            cout << "  " << endl;
            system("pause");  
            continue;         
        }
        cout << "Numeros primos menores de " << limite << ": ";
        mostrarPrimos(limite);
        cout << endl;
        cout << "  " << endl;
        system("pause");  
    }
    return 0;
}