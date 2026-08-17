#include<iostream>
using namespace std;

class my_print {
public:
    void operator()(string s) {
        cout<<s<<"\n";
    }
};

class my_add {
public:
    int operator()(int a,int b) {
        return a+b;
    }
};

int main() {
    my_print p1;
    p1("abcd");
    string s = "abcdef";
    p1(s);
    my_add add;
    int a=1,b=3;
    cout<<add(1,3);
}