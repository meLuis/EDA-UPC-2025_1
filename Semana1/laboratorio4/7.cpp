#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

bool esVocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string nombreArchivo = "Datos.txt";
    string texto;

    cout << "Ingrese una cadena de texto: ";
    getline(cin, texto);

    ofstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        cerr << "No se pudo crear el archivo de entrada.\n";
        return 1;
    }
    archivoEntrada << texto;
    archivoEntrada.close();

    int totalCaracteres = 0;
    int letras = 0;
    int espacios = 0;
    int simbolos = 0;
    int vocales = 0;
    int mayusculas = 0;
    int minusculas = 0;
    map<char, int> frecuencia;

    ifstream archivoLectura(nombreArchivo);
    if (!archivoLectura) {
        cerr << "No se pudo leer el archivo.\n";
        return 1;
    }

    char c;
    while (archivoLectura.get(c)) {
        totalCaracteres++;

        if (isalpha(c)) {
            letras++;
            frecuencia[tolower(c)]++;

            if (isupper(c)) {
                mayusculas++;
            } else {
                minusculas++;
            }

            if (esVocal(c)) {
                vocales++;
            }
        } else if (isspace(c)) {
            espacios++;
        } else {
            simbolos++;
        }
    }
    archivoLectura.close();

    string archivoResultado = nombreArchivo + ".estat.txt";
    ofstream archivoSalida(archivoResultado);
    if (!archivoSalida) {
        cerr << "No se pudo crear el archivo de salida.\n";
        return 1;
    }

    archivoSalida << "Cantidad de caracteres: " << totalCaracteres << "\n";
    archivoSalida << "Cantidad de letras: " << letras << "\n";
    archivoSalida << "Cantidad de espacios: " << espacios << "\n";
    archivoSalida << "Cantidad de símbolos: " << simbolos << "\n";
    archivoSalida << "Cantidad de vocales: " << vocales << "\n";
    archivoSalida << "Cantidad de mayúsculas: " << mayusculas << "\n";
    archivoSalida << "Cantidad de minúsculas: " << minusculas << "\n";
    archivoSalida << "Frecuencia\n";
    for (const auto& par : frecuencia) {
        archivoSalida << "  " << par.first << ": " << par.second << "\n";
    }

    archivoSalida.close();

    cout << "Analisis completado. Resultados guardados en '" << archivoResultado << "'\n";

    return 0;
}
