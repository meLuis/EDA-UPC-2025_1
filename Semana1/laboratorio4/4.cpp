#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int buscarPalabraEnArchivo(const string& nombreArchivo, const string& palabra) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
    }

    string linea;
    int numeroLinea = 1;

    while (getline(archivo, linea)) {
        if (linea.find(palabra) != string::npos) {
            archivo.close();
            return numeroLinea;
        }
        numeroLinea++;
    }

    archivo.close();
    return -1;
}

int main() {
    string archivo, palabra;

    cout << "Ingrese el nombre del archivo (con extension): ";
    getline(cin, archivo);

    cout << "Ingrese la palabra a buscar: ";
    getline(cin, palabra);

    int resultado = buscarPalabraEnArchivo(archivo, palabra);

    if (resultado != -1) {
        cout << "La palabra se encontro en la linea " << resultado << "." << endl;
    } else {
        cout << "La palabra no se encontro en el archivo." << endl;
    }

    return 0;
}
