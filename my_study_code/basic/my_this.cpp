#include<iostream>
using namespace std;

class Person {
public:
    int age;
    Person& AddPerson(Person &p) {
        this->age += p.age;
        return *this;
    }
};

void ts01() {
    Person p1(10);
    Person p2(10);
    p1.AddPerson(p2).AddPerson(p2).AddPerson(p2);
    cout<<"age of p1: "<<p1.age;
}

int main() {
    ts01();
}