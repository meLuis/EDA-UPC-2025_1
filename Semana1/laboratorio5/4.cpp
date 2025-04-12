#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool esPalindromo(string cadena) {
    string limpia = "";

    for (int i = 0; i < cadena.length(); i++) {
        char c = cadena[i];
        if (!isspace(c)) {
            limpia += tolower(c);
        }
    }

    int inicio = 0;
    int fin = limpia.length() - 1;

    while (inicio < fin) {
        if (limpia[inicio] != limpia[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }

    return true;
}

int main() {
    string texto;

    cout << "Ingrese una cadena (sin signos de puntuacion o tildes) ";
    getline(cin, texto);

    if (esPalindromo(texto)) {
        cout << "Es un palindromo." << endl;
    } else {
        cout << "No es un palindromo." << endl;
    }

    return 0;
}
