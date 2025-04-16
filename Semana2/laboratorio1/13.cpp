#include <iostream>
using namespace std;
void verificar(int n, int i, int suma) {
    if (i >= n) {
        if (suma == n)
            cout << n << " es un numero perfecto" << endl;
        else
            cout << n << " no es un numero perfecto" << endl;
        return;
    }
    if (n % i == 0) suma += i;
    verificar(n, i + 1, suma);
}
int main() {
    int numero;
    while (true) {
        system("cls");
        cout << "Ingrese un numero positivo: ";
        cin >> numero;
        cout << "  " << endl;
        if (numero <= 0) {
            cout << "Escriba un numero positivo." << endl;
            system("pause");
            continue;
        }
        verificar(numero, 1, 0);
        cout << "  " << endl;
        system("pause");
    }
    return 0;
}