#include "iostream"
#include <cmath>

using namespace std;


int main()
{
    auto sumaRaices = [](double x, double y, double z) {
        return sqrt(x) + sqrt(y) + sqrt(z);
        };

    double n1, n2, n3; 
    cout << "Ingrese tres valores: " << endl;
    cout << "valor 1: ";
    cin >> n1;
    cout << "valor 2: ";
    cin >> n2;
    cout << "valor 3: ";
    cin >> n3;

    cout << "La suma de las raices cuadradas ingresadas es: " << sumaRaices(n1, n2, n3);
    return 0;
}
