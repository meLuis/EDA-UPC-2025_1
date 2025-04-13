#include <string>
#include "iostream"

using namespace std;

string invertirCadena(string cadena) {
    string cadenaInvertida;
    for (int i = cadena.length() - 1; i >= 0; i--) {
        cadenaInvertida += cadena[i];
    }
    return cadenaInvertida;
}

int main()
{
    string cadena;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    string cadenaInvertida = invertirCadena(cadena);
    cout << "Cadena Invertida: " << cadenaInvertida << endl;

    return 0;
}
