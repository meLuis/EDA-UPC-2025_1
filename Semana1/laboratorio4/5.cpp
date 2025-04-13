#include "iostream"
#include <fstream>
#include <string>

using namespace std;

void copiarArchivo(const string& archivoOrigen, const string& archivoDestino) {
    ifstream origen(archivoOrigen); 
    ofstream destino(archivoDestino); 

    if (!origen.is_open()) {
        cout << "Error al abrir el archivo de origen: " << archivoOrigen << endl;
        return;
    }

    if (!destino.is_open()) {
        cout << "Error al abrir el archivo de destino: " << archivoDestino << endl;
        return;
    }

    string linea;
    while (getline(origen, linea)) {
        destino << "Copia de  "<< linea << endl;
    }

    origen.close();
    destino.close();
}



int main()
{
    string nombre;
    ofstream archivoNombres1;
    cout << "Ingrese un nombre completo: ";
    getline(cin, nombre);
    archivoNombres1.open("Nombres1.txt", ios::out);
    if (archivoNombres1.is_open()) {
        archivoNombres1 << "Nombre: " << nombre << endl;
        archivoNombres1.close();
    }

    copiarArchivo("Nombres1.txt", "CopiaNombres.txt");
    return 0;
}
