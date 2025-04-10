#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Punto {
public:
    T x, y;
    Punto() : x(0), y(0) {}
    Punto(T x, T y) : x(x), y(y) {}

    void mostrar() const {
        cout << "(" << x << ", " << y << ")";
    }
};

template <typename T>
class Poligono {
protected:
    vector<Punto<T>> puntos;
public:
    void agregarPunto(const Punto<T>& p) {
        puntos.push_back(p);
    }

    vector<Punto<T>> obtenerPuntos() const {
        return puntos;
    }

    void mostrar() const {
        for (const auto& p : puntos) {
            p.mostrar();
            cout << " ";
        }
        cout << endl;
    }
};

template <typename T>
class CurvaBezier {
private:
    vector<Punto<T>> puntosControl;
public:
    void agregarPunto(const Punto<T>& p) {
        puntosControl.push_back(p);
    }

    void mostrar() const {
        for (const auto& p : puntosControl) {
            p.mostrar();
            cout << " ";
        }
        cout << endl;
    }
};

template <typename T>
class Canvas {
private:
    vector<CurvaBezier<T>> curvas;
public:
    void agregarCurva(const CurvaBezier<T>& curva) {
        curvas.push_back(curva);
    }

    void mostrar() const {
        for (size_t i = 0; i < curvas.size(); ++i) {
            cout << "Curva " << i + 1 << ": ";
            curvas[i].mostrar();
        }
    }
};

int main() {

    int cantidadCurvas;
    cout << "Ingrese la cantidad de curvas que desea crear: ";
    cin >> cantidadCurvas;

    Canvas<float> canvas;

    for (int c = 0; c < cantidadCurvas; ++c) {
        CurvaBezier<float> curva;
        int cantidadPuntos;
        cout << "\nCurva " << c + 1 << " - Ingrese la cantidad de puntos de control: ";
        cin >> cantidadPuntos;

        for (int i = 0; i < cantidadPuntos; ++i) {
            float x, y;
            cout << "Ingrese coordenadas del punto " << i + 1 << " (x y): ";
            cin >> x >> y;
            curva.agregarPunto(Punto<float>(x, y));
        }

        canvas.agregarCurva(curva);
    }

    cout << "Curvas en el Canvas" << endl;
    canvas.mostrar();

    return 0;
}
