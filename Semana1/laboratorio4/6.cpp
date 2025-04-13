#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool esVocal(char c) {
    char minuscula = tolower((unsigned char)c);
    string vocales = "aeiouáéíóú";
    return vocales.find(minuscula) != string::npos;
}

char reemplazarVocal(char c) {
    if (esVocal(c)) {
        return isupper((unsigned char)c) ? 'A' : 'a';
    }
    return c;
}

void copiarConCambioDeVocales(const string& archivoOrigen, const string& archivoDestino) {
    ifstream origen(archivoOrigen);
    ofstream destino(archivoDestino);

    if (!origen) {
        cout << "No se pudo abrir el archivo de origen: " << archivoOrigen << endl;
        return;
    }
    if (!destino) {
        cout << "No se pudo crear el archivo de destino: " << archivoDestino << endl;
        return;
    }

    string linea;
    while (getline(origen, linea)) {
        for (char& c : linea) {
            c = reemplazarVocal(c);
        }
        destino << linea << '\n';
    }

    origen.close();
    destino.close();

    cout << "Archivo copiado con vocales reemplazadas por 'a' correctamente." << endl;
}

int main() {
    int opcion;
    string origen, destino;

    do {
        cout << "1. Copiar archivo reemplazando vocales por 'a'\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del archivo origen (con extension .txt): ";
                getline(cin, origen);
                cout << "Ingrese el nombre del archivo destino: ";
                getline(cin, destino);
                copiarConCambioDeVocales(origen, destino);
                break;
            case 2:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 2);

    return 0;
}
