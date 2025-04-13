#include <iostream>
using namespace std;

template <typename T>
class Estudiante {
private:
    T notas[5];
public:
    void ingresarNotas() {
        for (int i = 0; i < 5; i++) {
            cout << "Ingrese la nota " << (i + 1) << ": ";
            cin >> notas[i];
        }
    }

    T promedio() {
        T suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += notas[i];
        }
        return suma / 5;
    }

    T notaMayor() {
        T mayor = notas[0];
        for (int i = 1; i < 5; i++) {
            if (notas[i] > mayor)
                mayor = notas[i];
        }
        return mayor;
    }
};

int main() {
    Estudiante<float> e;
    e.ingresarNotas();
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Nota mayor: " << e.notaMayor() << endl;
    return 0;
}
