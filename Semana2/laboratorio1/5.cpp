#include "iostream"

using namespace std;

int main()
{
    char caracter;
    cout << "Ingrese un caracter: ";
    cin >> caracter;

    auto verificar = [](char c) {
        if (c >= '0' && c <= '9') { return "Es un numero"; }
        else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { return "Es una letra."; }
        return "No es letra ni numero";
    };
    cout << verificar(caracter) << endl;
    return 0;
}
