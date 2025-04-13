#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Alumno {
public:
    string codigo;
    string nombre;
    int edad;
    float promedio;

    void mostrar() const {
        cout << "Codigo: " << codigo << ", Nombre: " << nombre
            << ", Edad: " << edad << ", Promedio: " << promedio << endl;
    }
};

class AdministradorAlumnos {
private:
    Alumno alumnos[100];
    int cantidad;

public:
    AdministradorAlumnos() {
        cantidad = 0;
        cargarDesdeArchivo();
    }

    bool codigoExiste(const string& codigo) {
        for (int i = 0; i < cantidad; i++) {
            if (alumnos[i].codigo == codigo)
                return true;
        }
        return false;
    }

    void agregarAlumno() {
        if (cantidad >= 100) {
            cout << "No se pueden agregar mas alumnos.\n";
            return;
        }

        Alumno nuevo;
        cout << "Ingrese codigo: ";
        cin >> nuevo.codigo;

        if (codigoExiste(nuevo.codigo)) {
            cout << "Error: Ya existe un alumno con ese codigo.\n";
            return;
        }

        cin.ignore();
        cout << "Ingrese nombre: ";
        getline(cin, nuevo.nombre);
        cout << "Ingrese edad: ";
        cin >> nuevo.edad;
        cout << "Ingrese promedio: ";
        cin >> nuevo.promedio;

        alumnos[cantidad++] = nuevo;

        cout << "\nAlumno agregado correctamente.\n";
        system("pause");
        system("cls");
    }

    void mostrarAlumnos() {
        if (cantidad == 0) {
            cout << "No hay alumnos registrados.\n";
        }
        else {
            for (int i = 0; i < cantidad; i++) {
                alumnos[i].mostrar();
            }
        }
    }

    void guardarEnArchivo() {
        ofstream archivo("Alumnos.txt");
        for (int i = 0; i < cantidad; i++) {
            archivo << alumnos[i].codigo << "," << alumnos[i].nombre << ","
                << alumnos[i].edad << "," << alumnos[i].promedio << endl;
        }
        archivo.close();
    }

    void cargarDesdeArchivo() {
        ifstream archivo("Alumnos.txt");
        if (!archivo.is_open()) {
            cout << "No se encontro el archivo Alumnos.txt. Se creara al guardar.\n";
            return;
        }

        string linea;
        while (getline(archivo, linea)) {
            Alumno temp;
            size_t pos = 0;

            // Extraer campos separados por ','
            pos = linea.find(',');
            if (pos == string::npos) continue;
            temp.codigo = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(',');
            if (pos == string::npos) continue;
            temp.nombre = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(',');
            if (pos == string::npos) continue;
            temp.edad = stoi(linea.substr(0, pos));
            linea.erase(0, pos + 1);

            temp.promedio = stof(linea);

            alumnos[cantidad++] = temp;
        }
        archivo.close();
    }
};

int main() {
    AdministradorAlumnos admin;
    int opcion;

    do {
        cout << "1. Agregar alumno\n";
        cout << "2. Mostrar lista de alumnos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            admin.agregarAlumno();
            break;
        case 2:
            system("cls");
            admin.mostrarAlumnos();
            system("pause");
            system("cls");
            break;
        case 3:
            admin.guardarEnArchivo();
            cout << "Datos guardados en 'Alumnos.txt'. Hasta pronto!\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 3);

    return 0;
}