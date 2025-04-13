#include <iostream>
#include <string>
using namespace std;

string obtenerMes(int mes) {
    string meses[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                       "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    return meses[mes - 1];
}

string convertirEnteroACadena(int numero) {
    return to_string(numero);
}

string fechaLarga(int anio, int mes, int dia) {
    return convertirEnteroACadena(dia) + " de " + obtenerMes(mes) + " del " + convertirEnteroACadena(anio);
}

int main() {
    int anio, mes, dia;
    cout << "Ingrese año: "; cin >> anio;
    cout << "Ingrese mes (1-12): "; cin >> mes;
    cout << "Ingrese día: "; cin >> dia;

    cout << "Fecha larga: " << fechaLarga(anio, mes, dia) << endl;
    return 0;
}
