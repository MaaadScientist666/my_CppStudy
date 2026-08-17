#include<iostream>
using namespace std;

void func(int &a) {
    cout<<"fun(int &a)的调用"<<endl;
}
void func(const int &a) {
    cout<<"fun(const int &a)的调用"<<endl;
}



int main() {
    int a=10;
    func(a);
    func(10);
    const int b = 100;
    func(b);
}