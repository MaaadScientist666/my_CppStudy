#include<iostream>
using namespace std;

class Person {
    friend  ostream & operator<<(ostream &cout, Person &p);
    friend Person operator+(Person const &p1, int val);
public:
    Person(){}
    Person(int a, int b) {
        this->a = a;
        this->b = b;
    }
    Person operator+(Person &p1) {
        Person t;
        t.a = this->a + p1.a;
        t.b = this->b + p1.b;
        return t;
    }
    int a;
    int b;
};
Person operator+(Person const &p1, int val) {
        Person t;
        t.a = p1.a + val;
        t.b = p1.b + val;
        return t;
} //全局函数重载加号运算符

class MyInt {
public:
    MyInt(int num) : num(num) {}
    //重载前置++
    MyInt& operator++(){
        ++this->num;
        return *this;
    }
    //重载后置++
    MyInt operator++(int){
        MyInt t (*this);
        this->num++;
        return t;
    }
private:
    int num;
public:
    int get_num() const {
        return num;
    }
};
//全局函数重载<<运算符
ostream & operator<<(ostream &cout,const Person  &p) {
    cout<<"p.a = "<<p.a<<endl;
    cout<<"p.b = "<<p.b<<endl;
    return cout;
} // cout<<p 本质operator<<(cout, p)

ostream &operator<<(ostream &cout, const MyInt  &p) {
    cout<<p.get_num();
    return cout;
}



int main() {
    MyInt p(10);
    cout<<++p<<endl;
    MyInt p2(0);
    cout<<p2++<<endl;
}