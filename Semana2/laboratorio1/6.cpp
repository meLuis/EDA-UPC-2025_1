#include "iostream"

using namespace std;

void preguntar_numero(string pos, float* y) {
    cout << "Ingrese el " << pos << "numero: ";
    cin >> *y;
}
int main()
{
    auto igualdad_de_tres = [](float a, float b, float c)->bool {return a == b ? (a == c ? true : false) : false; };
    float a, v, c;
    preguntar_numero("primer ", &a);
    preguntar_numero("segundo ", &v);
    preguntar_numero("tercer ", &c);

    if (igualdad_de_tres(a, v, c)) {
        cout << "Los numeros: " << a << ", " << v << " y " << c << " son iguales.";
    }
    else cout << "Los numeros: " << a << ", " << v << " y " << c << " no son iguales";

    return 0;
}
