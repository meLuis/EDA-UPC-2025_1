#include "iostream"
using namespace std; 
void deciAHexa(int n) {
    if (n == 0) return;
    int resto = n % 16;
    deciAHexa(n / 16);
    if (resto < 10)
        cout << resto;
    else
        cout << char('A' + resto - 10);
}
int main() {
    int numero;
    while (true) {
        system("cls"); 
        cout << "Ingrese un numero decimal para convertir a hexadecimal: ";
        cin >> numero;
        if (numero < 0) {
            cout << "Ingrese un numero positivo." << endl;
            system("pause");
            continue;   
        }
        cout << "Hexadecimal: ";
        if (numero == 0)
            cout << "0";
        else
            deciAHexa(numero);
        cout << endl;
        system("pause");
    }
    return 0;
}