#include<iostream>
using namespace std;

int * func() {
    int * p = new int(rand());
    return p;
}
int main() {
    int * a = func();
    cout<<a<<endl;
    cout<<*a<<endl;
    int * p = new int(10);
    int * arr = new int[10];
    cout<<*p<<endl;
    for (int i=0;i<10;i++) {
        arr[i] = i;
    }
    for (int i=0;i<10;i++) {
        cout<<arr[i];
    }
}