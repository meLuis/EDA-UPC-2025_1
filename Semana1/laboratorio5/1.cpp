#include <iostream>
#include <string>
using namespace std;

int contarCaracteres(const string& cadena, char caracter) {
    int contador = 0;
    for (char c : cadena) {
        if (c == caracter) {
            break;
        }
        contador++;
    }
    return contador;
}

int main()
{
    string cadena;
    char caracter;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    cout << "Ingrese hasta que letra quiere que se cuenten los caracteres (sin incluir): ";
    cin >> caracter;
    int resultado = contarCaracteres(cadena, caracter);
    cout << "Numero de caracteres hasta " << caracter << " : " << resultado;
    return 0;
}
