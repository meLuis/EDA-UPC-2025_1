#include <iostream>
#include <string>
using namespace std;

int palabras(string cadena) {
    int contador = 0;
    bool esPalabra = false;

    for (char c : cadena) {
        if (c != ' ' && !esPalabra) {
            contador++;
            esPalabra = true;
        }
        else if (c == ' ') {
            esPalabra = false;
        }
    }
    return contador;
}

int main() {
    string texto;
    cout << "Ingrese una palabra: ";
    getline(cin, texto);

    cout << "Total de palabras: " << palabras(texto) << endl;
    return 0;
}
