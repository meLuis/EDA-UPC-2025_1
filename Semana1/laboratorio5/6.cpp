#include <iostream>
#include <string>
using namespace std;

int split(string texto, char separador, string resultado[], int maxPartes) {
    int cantidad = 0;
    string palabra = "";

    for (char c : texto) {
        if (c != separador) {
            palabra += c;
        }
        else {
            if (!palabra.empty() && cantidad < maxPartes) {
                resultado[cantidad++] = palabra;
                palabra = "";
            }
        }
    }

    if (!palabra.empty() && cantidad < maxPartes) {
        resultado[cantidad++] = palabra;
    }

    return cantidad;
}

int main() {
    string cadena;
    char separador;
    string partes[100]; 

    cout << "Ingrese un caracter para su separador: ";
    cin >> separador;
    cin.ignore(); 

    cout << "Ingrese texto separado por '" << separador << "': ";
    getline(cin, cadena);

    int total = split(cadena, separador, partes, 100);

    cout << "\nElementos:\n";
    for (int i = 0; i < total; i++) {
        cout << "- " << partes[i] << endl;
    }

    return 0;
}
