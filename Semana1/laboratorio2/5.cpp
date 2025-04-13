#include <iostream>
using namespace std;

template <typename T>
class Rectangulo {
private:
    T base, altura;
public:
    Rectangulo(T b, T h) : base(b), altura(h) {}

    T calcularArea() {
        return base * altura;
    }
};

int main() {
    double base, altura;
    cout << "Ingrese la base del rectangulo: ";
    cin >> base;
    cout << "Ingrese la altura: ";
    cin >> altura;
    Rectangulo<double> r(base, altura);
    cout << "El área es: " << r.calcularArea() << endl;
    return 0;
}
