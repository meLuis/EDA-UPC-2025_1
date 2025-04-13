#include "iostream"
#include <string>
#include <cctype>

using namespace std;

string convertirAMinusculas(const string& cadena) {
    string cadenaMinuscula;
    for (char c : cadena) {
        cadenaMinuscula += tolower(c);
    }
    return cadenaMinuscula;
}

int main()
{
    string cadena;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);

    string cadenaMinuscula = convertirAMinusculas(cadena);
    cout << "Cadena en minusculas: " << cadenaMinuscula << endl;
    return 0;
}
