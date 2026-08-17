#include <iostream>
using namespace std;
void swap01(int &a, int &b) {
    int t;
    t = a;
    a = b;
    b = t;
}

void swap02(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a = 10;
    int b = 15;
    swap01(a,b);
    cout<<"a = "<<a<<endl<<"b = "<<b<<endl;

    int c = 1;
    int d = 2;
    swap02(&c, &d);
    cout<<"c = "<<c<<endl<<"d = "<<d;

    return 0;
}


