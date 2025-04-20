#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto(int _id, string _desc, float _precio, string _envase) {
    id = _id;
    descripcion = _desc;
    precio = _precio;
    tipo_envase = _envase;
    siguiente = nullptr;
}

ListaProductos::ListaProductos() {
    cabeza = nullptr;
}

void ListaProductos::agregar(int id, string descripcion, float precio, string tipo_envase) {
    Producto* nuevo = new Producto(id, descripcion, precio, tipo_envase);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Producto* actual = cabeza;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void ListaProductos::eliminarPos(int pos) {
    if (!cabeza) {
        cout << "Lista vacia\n";
        return;
    }

    if (pos == 0) {
        Producto* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }

    Producto* actual = cabeza;
    Producto* anterior = nullptr;
    int indice = 0;

    while (actual && indice < pos) {
        anterior = actual;
        actual = actual->siguiente;
        indice++;
    }

    if (actual) {
        anterior->siguiente = actual->siguiente;
        delete actual;
    } else {
        cout << "Posicion fuera de rango\n";
    }
}

void ListaProductos::eliminarFinal() {
    if (!cabeza) {
        cout << "Lista vacía\n";
        return;
    }

    if (!cabeza->siguiente) {
        delete cabeza;
        cabeza = nullptr;
        return;
    }

    Producto* actual = cabeza;
    while (actual->siguiente->siguiente) {
        actual = actual->siguiente;
    }

    delete actual->siguiente;
    actual->siguiente = nullptr;
}

void ListaProductos::ordenar() {
    if (!cabeza || !cabeza->siguiente)
        return;

    bool cambiado;
    do {
        cambiado = false;
        Producto* actual = cabeza;

        while (actual->siguiente) {
            Producto* sig = actual->siguiente;
            if (actual->precio > sig->precio) {
                swap(actual->id, sig->id);
                swap(actual->descripcion, sig->descripcion);
                swap(actual->precio, sig->precio);
                swap(actual->tipo_envase, sig->tipo_envase);
                cambiado = true;
            }
            actual = actual->siguiente;
        }
    } while (cambiado);
}

void ListaProductos::mostrarMayor() {
    if (!cabeza) {
        cout << "Lista vacia\n";
        return;
    }

    Producto* mayor = cabeza;
    Producto* actual = cabeza->siguiente;

    while (actual) {
        if (actual->precio > mayor->precio) {
            mayor = actual;
        }
        actual = actual->siguiente;
    }

    cout << "\nProducto con mayor precio:\n";
    cout << "ID: " << mayor->id << endl;
    cout << "Descripcion: " << mayor->descripcion << endl;
    cout << "Precio: " << mayor->precio << endl;
    cout << "Tipo de envase: " << mayor->tipo_envase << endl;
}

void ListaProductos::mostrarLista() {
    Producto* actual = cabeza;
    cout << "\nLista de productos:\n";
    while (actual) {
        cout << "ID: " << actual->id << " | "
             << actual->descripcion << " | Precio: " << actual->precio
             << " | Envase: " << actual->tipo_envase << endl;
        actual = actual->siguiente;
    }
}
