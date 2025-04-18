#include <iostream>
#include <string>

using namespace std;

string convertirARomano(int numero) {
    int valores[] = {1000, 900, 500, 400, 100, 90,
                     50, 40, 10, 9, 5, 4, 1};

    string simbolos[] = {"M", "CM", "D", "CD", "C", "XC",
                         "L", "XL", "X", "IX", "V", "IV", "I"};

    string resultado = "";

    for (int i = 0; i < 13; i++) {
        while (numero >= valores[i]) {
            numero -= valores[i];
            resultado += simbolos[i];
        }
    }
    
/*2024 >= 1000 → resto 1000 → agrego "M" → queda 1024

1024 >= 1000 → resto 1000 → agrego "M" → queda 24

24 >= 10 → resto 10 → agrego "X" → queda 14

14 >= 10 → resto 10 → agrego "X" → queda 4

4 = 4 → resto 4 → agrego "IV" → queda 0*/

    return resultado;
}

int main() {
    int numero;

    cout << "Ingrese un numero entero entre 1 y 3999: ";
    cin >> numero;

    if (numero >= 1 && numero <= 3999) {
        string romano = convertirARomano(numero);
        cout << "Numero romano: " << romano << endl;
    } else {
        cout << "Numero fuera de rango." << endl;
    }

    return 0;
}
