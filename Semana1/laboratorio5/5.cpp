#include "iostream"
#include <string>

using namespace std;

int cantCharRepetido(const string& cadena, char caracter) {
    int contador = 0;
    for (char c : cadena) {
        if (c == caracter) {
            contador++;
        }
    }
    return contador++;
}
int main()
{
    string cadena;
    char caracter;
    cout << "Ingresar una cadena: ";
    getline(cin, cadena);
    cout << "Caracter que desea contar cuantas veces se repite: ";
    cin >> caracter;
    cout << "El caracter se repite " << cantCharRepetido(cadena, caracter) << " veces." << endl;


    return 0;
}
