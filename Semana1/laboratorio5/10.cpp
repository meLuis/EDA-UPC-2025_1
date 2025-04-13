#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Ingrese una palabra: ";
    getline(cin, str);

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << "Texto en mayúsculas: " << str << endl;
    return 0;
}
