#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

struct Producto {
    int id;
    string descripcion;
    float precio;
    string tipo_envase;
    Producto* siguiente;

    Producto(int _id, string _desc, float _precio, string _envase);
};

class ListaProductos {
private:
    Producto* cabeza;

public:
    ListaProductos();

    void agregar(int id, string descripcion, float precio, string tipo_envase);
    void eliminarPos(int pos);
    void eliminarFinal();
    void ordenar();
    void mostrarMayor();
    void mostrarLista();
};

#endif
