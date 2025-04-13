#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int contarPalabras(const string& cadena) {
    if (cadena.empty()) return 0;

    int contador = 1;
    for (char c : cadena) {
        if (c == ' ') {
            contador++;
        }
    }
    return contador;
}

int main() {
    string texto;
    string nombreArchivo = "Texto.txt";

    cout << "Ingrese una cadena de texto: ";
    getline(cin, texto);

    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida) {
        cerr << "No se pudo crear el archivo '" << nombreArchivo << "'\n";
        return 1;
    }
    archivoSalida << texto;
    archivoSalida.close();

    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        cerr << "No se pudo abrir el archivo '" << nombreArchivo << "'\n";
        return 1;
    }

    string linea;
    int totalPalabras = 0;

    while (getline(archivoEntrada, linea)) {
        totalPalabras += contarPalabras(linea);
    }

    archivoEntrada.close();
    cout<< "Archivo de texto generado"<<endl;
    cout << "Cantidad total de palabras en el archivo: " << totalPalabras << endl;

    return 0;
}
