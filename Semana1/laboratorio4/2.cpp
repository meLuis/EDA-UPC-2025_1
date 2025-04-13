#include <iostream>
#include <fstream>
using namespace std;

struct Empleado {
    char nombre[10];
    int edad;
    double salario;
};

int main() {
    ifstream archivo("empleados.dat", ios::binary);

    if (!archivo) {
        cout << "No se pudo abrir el archivo empleados.dat" << endl;
        return 1;
    }

    archivo.seekg(0, ios::end);
    int tamaño = archivo.tellg();
    int cantidad = tamaño / sizeof(Empleado);

    Empleado emp;

    for (int i = cantidad - 1; i >= 0; --i) {
        archivo.seekg(i * sizeof(Empleado), ios::beg);
        archivo.read(reinterpret_cast<char*>(&emp), sizeof(Empleado));
        cout << "Nombre: " << emp.nombre
             << ", Edad: " << emp.edad
             << ", Salario: " << emp.salario << endl;
    }

    archivo.close();
    return 0;
}
