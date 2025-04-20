#include <iostream>
#include "Producto.h"
using namespace std;

int main() {
    ListaProductos lista;

    lista.agregar(1, "Jugo", 5.0, "Botella");
    lista.agregar(2, "Agua", 3.5, "Botella");
    lista.agregar(3, "Refresco", 6.2, "Lata");
    lista.agregar(4, "Te", 4.0, "Pack");

    cout<<"\nLista completa";
    lista.mostrarLista();
    cout<<"\nEliminar producto en la posicion 1";
    lista.eliminarPos(1);
    lista.mostrarLista();
    cout<<"\nEliminar Final";
    lista.eliminarFinal();
    lista.mostrarLista();
    cout<<"\nOrdenar";
    lista.ordenar();
    lista.mostrarLista();
    lista.mostrarMayor();

    return 0;
}
