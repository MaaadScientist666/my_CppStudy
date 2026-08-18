#include<functional>
#include<iostream>
using namespace std;

plus<int> p;
negate<int> n;
multiplies<int> m;
divides<double> di;
modulus<int> mo;


int main() {
    int a=3,b=2;
    cout<<p(1,2);
    cout<<endl<<n(b);
    cout<<endl<<m(a,b);
    double c=6.0,d=3.5;
    cout<<endl<<di(c,d);
    cout<<endl<<mo(a,b);
}