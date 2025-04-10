#include <iostream>
#include <functional>

using namespace std;

int main(){
    auto f1=[](int x,int y){return x + y;};
    cout<<"Lambda F1: "<<f1(4,3)<<endl;

    function <int(int,int)> f2=[](int x,int y){ return x+y;};
    cout<<"Lambda F2: "<<f2(4,3)<<endl;

    auto f3=[](int x) {return x*x;}(12);
    cout<<"Lambda F3: "<<f3<<endl;

    int sum=[](int x, int y){return x+y;}(4,5);
    cout<<"Lambda F4: "<<sum<<endl;

    auto mul=[](int x, int y){ return x*y;};
    cout<<"Lambda F5: "<<mul(5,7)<<endl;
}