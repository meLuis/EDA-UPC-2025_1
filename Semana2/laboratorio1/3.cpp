#include "iostream"
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n1, n2, n3;
    int multiplo = 3;
    int contador = 0;

    cout << "Ingrese tres numero entero (separalos con un espacio): ";
    cin >> n1 >> n2 >> n3;

    vector <int> v{ n1, n2, n3 };
  
    auto esMultiplo = [&](int num) { return !(num % multiplo); };
    for (int num : v) {
        if (esMultiplo(num)) contador++;
    }
    cout << "Enteros que son multiplos de 3 =>" << contador << endl; 
   /* size_t count = count_if(v.begin(), v.end(), [=](int num) { return !(num % multi); });
    cout << "Enteros que son multiplos de 3 =>" << count << endl;*/
    return 0;
}
