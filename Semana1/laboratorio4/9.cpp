#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string prefijo;
    cout << "Ingrese las primeras letras de la palabra que desea buscar: ";
    getline(cin, prefijo);

    ifstream archivo("palabras.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1; 
    }

    string palabra;
    bool encontrado = false;

    while (getline(archivo, palabra)) {
        
        bool coincide = true;
        for (size_t i = 0; i < prefijo.length(); ++i) {
            if (i >= palabra.length() || palabra[i] != prefijo[i]) {
                coincide = false;
                break;
            }
        }

        if (coincide) {
            cout << palabra << endl; 
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron palabras que comiencen con: " << prefijo << endl;
    }

    archivo.close(); 
    return 0;
}