#include <iostream>
#include <string>
using namespace std;

string unidades[] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis",
                     "siete", "ocho", "nueve", "diez", "once", "doce", "trece",
                     "catorce", "quince", "dieciséis", "diecisiete", "dieciocho",
                     "diecinueve", "veinte" };

string decenas[] = { "", "", "veinte", "treinta", "cuarenta", "cincuenta",
                    "sesenta", "setenta", "ochenta", "noventa" };

string centenas[] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos",
                     "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };

string numeroATexto(long long numero) {
    if (numero < 0) return "menos " + numeroATexto(-numero);
    if (numero <= 20) return unidades[numero];
    if (numero < 100) {
        int d = numero / 10;
        int u = numero % 10;
        if (u == 0) return decenas[d];
        if (d == 2) return "veinti" + unidades[u];
        return decenas[d] + " y " + unidades[u];
    }
    if (numero < 1000) {
        if (numero == 100) return "cien";
        int c = numero / 100;
        int resto = numero % 100;
        return centenas[c] + " " + numeroATexto(resto);
    }
    if (numero < 1000000) {
        int m = numero / 1000;
        int resto = numero % 1000;
        string miles = (m == 1) ? "mil" : numeroATexto(m) + " mil";
        return (resto == 0) ? miles : miles + " " + numeroATexto(resto);
    }

    return "Número demasiado grande";
}

int main() {
    long long num;
    cout << "Ingrese un numero entero positivo: ";
    cin >> num;

    cout << "\nEn texto: " << numeroATexto(num) << endl;
    return 0;
}
