#include <iostream>
#include <string>
using namespace std;
string reemplazarPalabra(string texto, string palabraAntigua, string palabraNueva) {
    size_t posicion = 0;
    while ((posicion = texto.find(palabraAntigua, posicion)) != string::npos) {
        texto.replace(posicion, palabraAntigua.length(), palabraNueva);
        posicion += palabraNueva.length();
    }
    return texto;
}
int main() {
    string texto, palabraAntigua, palabraNueva;
    cout << "Ingrese una frase: ";
    getline(cin, texto);
    cout << "Palabra a reemplazar (respetar mayus y tilde): ";
    cin >> palabraAntigua;
    cout << "Palabra nueva: ";
    cin >> palabraNueva;
    string resultado = reemplazarPalabra(texto, palabraAntigua, palabraNueva);
    cout << "Frase modificada: " << resultado << endl;
    return 0;
}