#include<iostream>
using namespace std;

int& ts01() {
    static int a = 10;
    return a;
}

int main() {

    int &ref = ts01();
    cout<<"ref = "<<ref<<endl;
    ts01() = 1000;
    cout<<"ref = "<<ref;
}
