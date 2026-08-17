#include<iostream>
using namespace std;

class Person {
public:
    int age;
    bool operator<(const Person &p) {
        if (this->age < p.age) return true;
        else return false;
    }
    bool operator>(const Person &p) {
        if (this->age > p.age) return true;
        else return false;
    }
    bool operator==(const Person &other) const {
        if (this->age == other.age) return true;
        return false;
    }
};

int main() {
    Person p1,p2;
    p1.age = 10;
    p2.age = 15;
    if (p1 < p2)
        cout<<"p1<p2"<<'\n';
    else if (p1 > p2)
        cout<<"p1>p2"<<"\n";
    else
        cout<<"p1 = p2"<<"\n";
}