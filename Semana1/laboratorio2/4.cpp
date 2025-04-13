#include <iostream>
#include <string>
using namespace std;

template <typename T>
string deBinario(T num) {
    string binario = "";
    while (num > 0) {
        binario = (num % 2 == 0 ? "0" : "1") + binario;
        num /= 2;
    }
    return binario.empty() ? "0" : binario;
}

int main() {
    int num;
    cout << "Ingrese un número decimal: ";
    cin >> num;
    cout << "Binario: " << deBinario(num) << endl;
    return 0;
}
