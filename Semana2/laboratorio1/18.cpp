#include <iostream>
using namespace std;

int sumaDigitos(const string& cadena, int index = 0) {
    if (index >= cadena.length())
        return 0;
    return (cadena[index] - '0') + sumaDigitos(cadena, index + 1);
    /*esto no es un hack, es que '0' vale 48 en ASCII y al restar
    las strings numericas devuelve su diferencia que es un entero*/
}

int main() {
    string numero;
    cout << "Ingrese una cadena numerica de mas de 4 digitos: ";
    cin >> numero;

    if (numero.length() <= 4) {
        cout << "La cadena debe tener mas de 4 digitos." << endl;
        return 1;
    }

    int resultado = sumaDigitos(numero);
    cout << "La suma de los digitos es: " << resultado << endl;

    return 0;
}
