#include <iostream>
#include <fstream>
using namespace std;

struct Empleado {
    char nombre[10];
    int edad;
    double salario;
};

int main() {
    ofstream archivo("empleados.dat", ios::binary);

    if (!archivo) {
        cout << "No se pudo crear el archivo" << endl;
        return 1;
    }

    Empleado empleados[] = {
        {"Carlos", 30, 2500.5},
        {"Maria", 25, 3200.75},
        {"Luis", 28, 2800.0}
    };

    for (int i = 0; i < 3; ++i) {
        archivo.write(reinterpret_cast<char*>(&empleados[i]), sizeof(Empleado));
    }

    archivo.close();
    cout << "Archivo creado correctamente." << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Nombre: " << empleados[i].nombre
             << ", Edad: " << empleados[i].edad
             << ", Salario: " << empleados[i].salario << endl;
    }

    return 0;
}
