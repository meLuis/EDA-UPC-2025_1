#include "iostream"
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void imprimirArr(T a, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << (i ? " , " : "") << a[i];
    }
    cout << "]\n";
}
int main()
{
    int n1, n2, n3, n4, n5;
    cout << "Ingresar 5 valores enteros (separalos con un espacio) : " <<endl;
    cin >> n1>> n2>> n3>> n4>> n5;

    vector <int> v{ n1,n2,n3,n4,n5 };
    sort(
        v.begin(), v.end(), [=](const int left, const int right) {return left > right; }
    );
    imprimirArr(v, v.size());
    return 0;
}
