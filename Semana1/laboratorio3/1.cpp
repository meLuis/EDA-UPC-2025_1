#include <iostream>
using namespace std;

template <typename T>
T encontrarMayor(T arr[], int size) {
    T mayor = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > mayor)
            mayor = arr[i];
    return mayor;
}

template <typename T>
T encontrarMenor(T arr[], int size) {
    T menor = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < menor)
            menor = arr[i];
    return menor;
}

template <typename T>
T sumarElementos(T arr[], int size) {
    T suma = 0;
    for (int i = 0; i < size; ++i)
        suma += arr[i];
    return suma;
}

template <typename T>
T encontrarModa(T arr[], int size) {
    int maxCount = 0;
    T moda = arr[0];
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (arr[j] == arr[i])
                ++count;
        }
        if (count > maxCount) {
            maxCount = count;
            moda = arr[i];
        }
    }
    return moda;
}

template <typename T>
void ordenarArreglo(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void eliminarEnPosicion(T arr[], int& size, int pos) {
    if (pos < 0 || pos >= size) return;
    for (int i = pos; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
}

template <typename T>
int buscarElemento(T arr[], int size, T valor) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == valor)
            return i;
    return -1;
}

template <typename T>
bool existeElemento(T arr[], int size, T valor) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == valor)
            return true;
    return false;
}

template <typename T>
int contarRepeticiones(T arr[], int size, T valor) {
    int conteo = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] == valor)
            ++conteo;
    return conteo;
}

template <typename T>
void mostrarArreglo(T arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main() {
    const int MAX = 100;
    int arreglo[MAX], size;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> size;

    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Elemento " << i << ": ";
        cin >> arreglo[i];
    }

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Encontrar el mayor\n";
        cout << "2. Encontrar el menor\n";
        cout << "3. Sumar todos los elementos\n";
        cout << "4. Encontrar la moda\n";
        cout << "5. Ordenar el arreglo\n";
        cout << "6. Eliminar en una posición\n";
        cout << "7. Buscar un elemento\n";
        cout << "8. Ver si un elemento existe\n";
        cout << "9. Contar repeticiones de un elemento\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        int pos, valor;

        switch (opcion) {
        case 1:
            cout << "Mayor: " << encontrarMayor(arreglo, size) << endl;
            break;
        case 2:
            cout << "Menor: " << encontrarMenor(arreglo, size) << endl;
            break;
        case 3:
            cout << "Suma: " << sumarElementos(arreglo, size) << endl;
            break;
        case 4:
            cout << "Moda: " << encontrarModa(arreglo, size) << endl;
            break;
        case 5:
            ordenarArreglo(arreglo, size);
            cout << "Arreglo ordenado: ";
            mostrarArreglo(arreglo, size);
            break;
        case 6:
            cout << "Posición a eliminar: ";
            cin >> pos;
            eliminarEnPosicion(arreglo, size, pos);
            cout << "Nuevo arreglo: ";
            mostrarArreglo(arreglo, size);
            break;
        case 7:
            cout << "Valor a buscar: ";
            cin >> valor;
            pos = buscarElemento(arreglo, size, valor);
            if (pos != -1)
                cout << "Encontrado en la posición: " << pos << endl;
            else
                cout << "No encontrado.\n";
            break;
        case 8:
            cout << "Valor a verificar: ";
            cin >> valor;
            cout << (existeElemento(arreglo, size, valor) ? "Existe." : "No existe.") << endl;
            break;
        case 9:
            cout << "Elemento a contar: ";
            cin >> valor;
            cout << "Se repite " << contarRepeticiones(arreglo, size, valor) << " veces.\n";
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida\n";
        }

    } while (opcion != 0);

    return 0;
}
