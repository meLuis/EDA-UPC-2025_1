#include "iostream"
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int n1, n2, n3;
    cout << "Ingresar 3 valores enteros (separalos con un espacio) : " << endl;
    cin >> n1 >> n2 >> n3;

    auto maxNum = [](int n1, int n2, int n3) {
        if (n1 >= n2 && n1 >= n3) { return n1; }
        else if (n2 >= n1 && n2 >= n3) { return n2; }
        else { return n3; }
        };

    /*auto maxNum = [](int n1, int n2, int n3) { return max({ n1,n2,n3 }); };*/
    
    cout << "El numero mayor es: " << maxNum(n1, n2, n3) << endl;

  
    return 0;
}