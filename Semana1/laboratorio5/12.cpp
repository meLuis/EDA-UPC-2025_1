#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string formatoTitulo(string cadena) {
    string resultado = "";
    bool nuevaPalabra = true;

    for (int i = 0; i < cadena.length(); i++) {
        char c = cadena[i];

        if (isspace(c)) {
            nuevaPalabra = true;
            resultado += c;
        } else {
            if (nuevaPalabra) {
                resultado += toupper(c);
                nuevaPalabra = false;
            } else {
                resultado += tolower(c);
            }
        }
    }

    return resultado;
}

int main() {
    string texto;

    cout << "Ingrese una cadena: ";
    getline(cin, texto);

    string titulo = formatoTitulo(texto);

    cout << "Formato titulo: " << titulo << endl;

    return 0;
}
