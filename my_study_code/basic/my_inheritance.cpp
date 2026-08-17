#include<iostream>
using namespace std;

class Father {
public:
    Father() {
        a=1;
        b=2;
        c=3;
    }
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Son: public Father{
public:
    Son() {
        a = 999;
    }
public:
    int a; //s1.Father::a  加作用域访问同名元素
};

//菱形继承问题：
class Animal {
public:
    int age;
};

class Goat : public Animal {

};

class Horse: public Animal {

};

class GoatHorse: public Goat,public Horse {
public:
    int age;
};

int main() {
    GoatHorse e1;
    e1.Goat::age = 10;
    e1.Horse::age = 11;
    e1.age = 13;
}