#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Registro {
    char codigo[8];
    char nombre[20];
    int edad;
};

void crearArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary);

    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    int cantidad;
    cout << "Cuantos registros desea ingresar? ";
    cin >> cantidad;
    cin.ignore();

    Registro reg;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nRegistro " << i + 1 << ":\n";
        cout << "Codigo (max 7 caracteres): ";
        cin.getline(reg.codigo, 8);
        cout << "Nombre (max 19 caracteres): ";
        cin.getline(reg.nombre, 20);
        cout << "Edad: ";
        cin >> reg.edad;
        cin.ignore();
        cout << "";

        archivo.write(reinterpret_cast<char*>(&reg), sizeof(Registro));
    }

    archivo.close();
    cout << "\nArchivo '" << nombreArchivo << "' creado correctamente.\n" << endl;
}

class Eliminador {
    string nombreArchivo;

    bool primerDigitoEsPar(const char* codigo) {
        if (isdigit(codigo[0])) {
            int digito = codigo[0] - '0';
            return digito % 2 == 0;
        }
        return false;
    }

public:
    Eliminador(string nombreArchivo) : nombreArchivo(nombreArchivo) {}

    void eliminarRegistros() {
        ifstream archivoEntrada(nombreArchivo, ios::binary);
        if (!archivoEntrada.is_open()) {
            cout << "No se pudo abrir el archivo original." << endl;
            return;
        }

        ofstream archivoTemporal("temporal.txt", ios::binary);
        if (!archivoTemporal.is_open()) {
            cout << "No se pudo crear el archivo temporal." << endl;
            return;
        }

        Registro reg;
        while (archivoEntrada.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) {
            if (!primerDigitoEsPar(reg.codigo)) {
                archivoTemporal.write(reinterpret_cast<char*>(&reg), sizeof(Registro));
            }
        }

        archivoEntrada.close();
        archivoTemporal.close();

        remove(nombreArchivo.c_str());
        rename("temporal.txt", nombreArchivo.c_str());

        cout << "Registros con codigos que inician en numero par fueron borrados." << endl;
    }
};

int main() {
    string archivo = "registros.txt";

    int opcion;
    do {
        cout << "1. Crear archivo y agregar registros\n";
        cout << "2. Eliminar registros por codigos que empiezan en numero par\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearArchivo(archivo);
            break;
        case 2: {
            Eliminador eliminador(archivo);
            eliminador.eliminarRegistros();
            break;
        }
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 3);

    return 0;
}