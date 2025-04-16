#include "iostream"
using namespace std;

bool multiplo(int resultado) {
    return resultado % 3 == 0;
}
int main()
{
    int num1, num2;
 
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << " " << endl;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    auto suma = [](int a, int b) {
        return a + b;
        };
    cout << " " << endl;
    int resultado = suma(num1, num2);
    cout << "La suma " << num1 << " + " << num2 << " es igual a: " << resultado << endl;  
    cout << " " << endl;

    if (multiplo (resultado)) {
        cout << resultado << " es multiplo de 3 " << endl;
    }else 
        cout << resultado << " no es multiplo de 3 " << endl;

    return 0;
}
