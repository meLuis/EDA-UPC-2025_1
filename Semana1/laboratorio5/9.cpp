#include "iostream"
#include <string>

using namespace std;

int romanoAentero(const string& cadena) {
    int numEntero = 0;
    int longitud = cadena.length();

    for (int i = 0; i < longitud; i++) {
        if (cadena[i] == 'I') {
            numEntero += 1;
        }
        else if (cadena[i] == 'V') {
            numEntero += 5;
        }
        else if (cadena[i] == 'X') {
            numEntero += 10;
        }
        else if (cadena[i] == 'L') {
            numEntero += 50;
        }
        else if (cadena[i] == 'C') {
            numEntero += 100;
        }
        else if (cadena[i] == 'D') {
            numEntero += 500;
        }
        else if (cadena[i] == 'M') {
            numEntero += 1000;
        }

        if (i < longitud - 1) { 
            if (cadena[i] == 'I' && cadena[i + 1] == 'V') {
                numEntero -= 2; 
            }
            else if (cadena[i] == 'I' && cadena[i + 1] == 'X') {
                numEntero -= 2; 
            }
            else if (cadena[i] == 'X' && cadena[i + 1] == 'L') {
                numEntero -= 20; 
            }
            else if (cadena[i] == 'X' && cadena[i + 1] == 'C') {
                numEntero -= 20; 
            }
            else if (cadena[i] == 'C' && cadena[i + 1] == 'D') {
                numEntero -= 200; 
            }
            else if (cadena[i] == 'C' && cadena[i + 1] == 'M') {
                numEntero -= 200; 
            }
        }
    }
    return numEntero;
}
int main()
{
    string cadena;
    cout << "Ingrese un numero romano: ";
    cin >> cadena;
    cout << "El equivalente en entero es: " << romanoAentero(cadena) << endl;
    return 0;
}
